#include "previewer.h"

void Previewer::view (LightCol** cols, int height, int width, float scale) {

  Display* d;
  Window w;
  GC gc;

  d = XOpenDisplay(0);

  int blackColor = BlackPixel(d, DefaultScreen(d));
  int whiteColor = WhitePixel(d, DefaultScreen(d));

  w = XCreateSimpleWindow(d, DefaultRootWindow(d), 0,0, width, height, 0, blackColor, whiteColor);
  XMapWindow(d,w);
  gc = XCreateGC(d, w, 0, 0);

  for(int i = 0; i < width; i++) {
    for(int j = 0; j < height;j++){
      XSetForeground(d, gc, blackColor + (int) (cols[i][j].blue * scale * 255) + (int) (cols[i][j].green * scale * 255) * 256 + (int) (cols[i][j].red * scale * 255) *256 * 256);
      XDrawPoint(d,w,gc,i,j);
    }
  }

  XMapWindow(d,w);
  XFlush(d);
  sleep(5);
  XCloseDisplay(d);

}
