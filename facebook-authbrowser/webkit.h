typedef void (*CbPtr) (const gchar *);
void open_url_with_webkit(const char *url, const char *stop, CbPtr back_cb);
