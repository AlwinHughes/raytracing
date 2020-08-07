#include "previewer.h"

void Previewer::view (LightCol** cols, int height, int width, float scale) {

  Display* d;
  Window w;
  GC gc;

  d = XOpenDisplay(0);

  int blackColor = BlackPixel(d, DefaultScreen(d));
  int whiteColor = WhitePixel(d, DefaultScreen(d));

  w = XCreateSimpleWindow(d, DefaultRootWindow(d), 0,0, width, height, 0, blackColor, whiteColor);
  gc = XCreateGC(d, w, 0, 0);
  XSelectInput(d,w, KeyPressMask);
  XMapWindow(d,w);

  Pixmap pixmap;
  int depth = DefaultDepth(d, DefaultScreen(d));

  pixmap = XCreatePixmap(d, w, width, height, depth);


  for(int i = 0; i < width; i++) {
    for(int j = 0; j < height;j++){
      XSetForeground(d, gc, blackColor + (int) (sqrt(cols[i][j].blue) * scale * 255) + (int) (sqrt(cols[i][j].green) * scale * 255) * 256 + (int) (sqrt(cols[i][j].red) * scale * 255) *256 * 256);
      XDrawPoint(d,pixmap,gc,i,j);
    }
  }

  XCopyArea(d, pixmap, w, gc, 0,0, width, height, 0,0);

  XFlush(d);

  XEvent event;
  unsigned int key_q = 0x18;

  while(1) {
    XNextEvent(d, &event);

    if(event.type == KeyPress) {

      if(event.xkey.keycode == key_q) {
        break;
      }
    }
  }

  XCloseDisplay(d);

}
