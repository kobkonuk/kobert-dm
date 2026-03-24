#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
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
		}
	}

	XCloseDisplay(display);

	return 0;
}
