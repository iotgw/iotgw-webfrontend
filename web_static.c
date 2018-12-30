#include "web_static.h"

typedef struct {
  const char content_type[32];
  void *begin;
  void *end;
  bool gzip;
} periph_web_file_t;

extern const uint8_t index_start[]         asm("_binary_index_html_start");
extern const uint8_t index_end[]           asm("_binary_index_html_end");

extern const uint8_t main_css_start[]      asm("_binary_main_css_start");
extern const uint8_t main_css_end[]        asm("_binary_main_css_end");

extern const uint8_t main_js_start[]       asm("_binary_main_js_start");
extern const uint8_t main_js_end[]         asm("_binary_main_js_end");

extern const uint8_t favicon_ico_start[]   asm("_binary_favicon_ico_start");
extern const uint8_t favicon_ico_end[]     asm("_binary_favicon_ico_end");

extern const uint8_t manifest_json_start[] asm("_binary_manifest_json_start");
extern const uint8_t manifest_json_end[]   asm("_binary_manifest_json_end");


const periph_web_file_t index_html_file = {
    .begin        = (void *)index_start,
    .end          = (void *)index_end,
    .content_type = "text/html",
    .gzip         = true,
};

const periph_web_file_t main_css_file = {
    .begin        = (void *)main_css_start,
    .end          = (void *)main_css_end,
    .content_type = "text/css",
    .gzip         = true,
};

const periph_web_file_t main_js_file = {
    .begin        = (void *)main_js_start,
    .end          = (void *)main_js_end,
    .content_type = "text/js",
    .gzip         = true,
};

const periph_web_file_t favicon_ico_file = {
    .begin        = (void *)favicon_ico_start,
    .end          = (void *)favicon_ico_end,
    .content_type = "image/x-icon",
    .gzip         = true,
};

const periph_web_file_t manifest_json_file = {
    .begin        = (void *)manifest_json_start,
    .end          = (void *)manifest_json_end,
    .content_type = "application/json",
    .gzip         = true,
};


esp_err_t webstatic_register(httpd_handle_t handle, static_handle_t handler)
{
    esp_err_t err;
    if (handle == NULL || handler == NULL) {
        return ESP_FAIL;
    }
    httpd_uri_t route = {
        .uri      = "/",
        .method   = HTTP_GET,
        .handler  = handler,
        .user_ctx = (void *)&index_html_file
    };
    err = httpd_register_uri_handler(handle, &route);
    if (err != ESP_OK) {
        return err;
    }
    route.uri = "/static/js/main.js";
    route.user_ctx = (void *)&main_js_file;
    err = httpd_register_uri_handler(handle, &route);
    if (err != ESP_OK) {
        return err;
    }

    route.uri = "/static/css/main.css";
    route.user_ctx = (void *)&main_css_file;
    err = httpd_register_uri_handler(handle, &route);
    if (err != ESP_OK) {
        return err;
    }

    route.uri = "/favicon.ico";
    route.user_ctx = (void *)&favicon_ico_file;
    err = httpd_register_uri_handler(handle, &route);
    if (err != ESP_OK) {
        return err;
    }

    route.uri = "/manifest.json";
    route.user_ctx = (void *)&manifest_json_file;
    err = httpd_register_uri_handler(handle, &route);
    if (err != ESP_OK) {
        return err;
    }

    return ESP_OK;
}

esp_err_t webstatic_unregister(httpd_handle_t handle)
{
    esp_err_t err;
    if (handle == NULL) {
        return ESP_ERR_INVALID_ARG;
    }
    err = httpd_unregister_uri(handle, "/");
    err |= httpd_unregister_uri(handle, "/static/js/main.js");
    err |= httpd_unregister_uri(handle, "/static/css/main.css");
    err |= httpd_unregister_uri(handle, "/favicon.ico");
    err |= httpd_unregister_uri(handle, "/manifest.json");
    return err;
}
