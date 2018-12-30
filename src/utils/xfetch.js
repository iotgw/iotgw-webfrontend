export function xfetch(url) {
  return new Promise((resolve, reject) => {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState === 4 && this.status === 200) {
        try {
          let json = JSON.parse(this.responseText);
          resolve({ json: json, text: this.responseText });
        } catch (e) {
          reject(e);
        }
      }
    };
    xhttp.open("GET", url, true);
    xhttp.send();
  });
}
