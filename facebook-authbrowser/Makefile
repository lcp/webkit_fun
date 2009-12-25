CFLAGS=`pkg-config --cflags gtk+-2.0 libsoup-2.4` -I/usr/include/webkit-1.0/
LIBS=`pkg-config --libs gtk+-2.0 webkit-1.0 libsoup-2.4` -L /usr/lib

all:
	gcc -Wall $(CFLAGS) $(LIBS) -g webkit.c session_parse.c main.c -o authbrowser

clean:
	rm -f authbrowser
