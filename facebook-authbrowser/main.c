#include <gtk/gtk.h>
#include <libsoup/soup.h>
#include "webkit.h"

static void
back_cb (const gchar* uri)
{
    GHashTable *form;
    gchar **split_str = g_strsplit (uri, "?", 2);
    form = soup_form_decode (split_str[1]);

    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, form);
    while(g_hash_table_iter_next(&iter, &key, &value)) {
        g_print("key\t: %s\nvalue\t: %s\n\n", (char *)key , (char *)value);
    }
    gtk_main_quit ();
}

int
main (int argc, char* argv[])
{
    gtk_init (&argc, &argv);
    g_thread_init(NULL);

    gchar* uri; 
    uri = "http://www.facebook.com/login.php?api_key=d012235b3034109003451109a1926eee&connect_display=popup&v=1.0&fbconnect=true&return_session=true&session_key_only=true&req_perms=read_stream,publish_stream,offline_access";
    open_url_with_webkit(uri, "http://www.facebook.com/?session=", back_cb);

    gtk_main ();

    return 0;
}
