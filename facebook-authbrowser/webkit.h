#include <gtk/gtk.h>
#include <webkit/webkit.h>

typedef struct {
  GtkWidget* main_window;
  WebKitWebView* web_view;
  char* main_title;
  int load_progress;
  char* stop_url;
  void (*session_handler)(const char *);
} UrlInfo;

void urlinfo_init (UrlInfo *info);
void open_url_with_webkit (UrlInfo *info, const char* url);
