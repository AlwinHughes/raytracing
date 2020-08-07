#ifndef PREVIEW
#define PREVIEW

#include "vector3.h"
#include "ray.h"
#include "light_col.h"
#include <X11/Xlib.h>
#include <unistd.h>
#include "controler.h"
#include "fixedsceene.h"


class Previewer {
  public:
    static Previewer& get() {
      static Previewer instance;
      return instance;
    }
    void view(LightCol** cols, int height, int width, float scale = 1);

  private:
    Previewer() {};
    Previewer(Previewer const &);
    void operator=(Previewer const &);
};
#endif
