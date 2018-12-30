#ifndef _EMBED_WEB_STATIC_H_
#define _EMBED_WEB_STATIC_H_

#include "esp_http_server.h"

typedef esp_err_t (*static_handle_t)(httpd_req_t* req);

esp_err_t webstatic_register(httpd_handle_t handle, static_handle_t handler);
esp_err_t webstatic_unregister(httpd_handle_t handle);

#endif
