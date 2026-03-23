#include <X11/Xlib.h>
#include <stdio.h>
#include <err.h>


static Display* dpy;
static int scr;
static Window root;

#define POSY   500
#define POSX   500
#define WIDTH  500
#define HEIGHT 500
#define BORDER 15

int main () {

	Window win;
	XEvent ev;

	if ((dpy == XOpenDisplay(NULL)) == NULL)
		err(1, "Can't open display");

	scr = DefaultScreen(dpy);
	root = RootWindow(dpy, scr);
	
	win = XCreateSimpleWindow(dpy, root, POSX, POSY, WIDTH, HEIGHT, BORDER, BlackPixel(dpy, scr), WhitePixel(dpy, scr));
	XMapWindow(dpy, win);
	
	while (XNextEvent(dpy, &ev) == 0) {

	}

	XUnmapWindow(dpy, win);
	XDestroyWindow(dpy, win);
	XCloseDisplay(dpy);

	return 0;
}
