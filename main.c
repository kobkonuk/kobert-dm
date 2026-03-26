#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// learnt this from "Tsoding Daily" on youtube, to learn the basics of x11.
// this is sort of a copy, but having him going through this short piece of code
// explaining everything helped me understand the parts.

int main (void) {
	Display *display = XOpenDisplay(NULL);
	if (display == NULL) {
		fprintf(stderr, "error couldnt open the default display \n");
		exit(1);
	}

	Window window = XCreateSimpleWindow(
			display,
			XDefaultRootWindow(display),
			0, 0,
			1920, 1080,
			20,
			0x0011111b,
			0x001e1e2e);

	Atom wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(display, window, &wm_delete_window, 1);

	XSelectInput(display, window, KeyPressMask);
	XMapWindow(display, window);
	XSync(display, False);

	int q = 0;
	while (!q) {
		XEvent event = {0};
		XNextEvent(display, &event);
		switch (event.type) {
			case KeyPress: {
			   printf("w keypress\n");
			} break;
			
			case ClientMessage: {
				if ((Atom) event.xclient.data.l[0] == wm_delete_window) {
					printf("WM_SAVE_YOUSELF\n");
					q = 1;
				} 
			} break;
		}
	}

	XCloseDisplay(display);
	
	return 0;
}
