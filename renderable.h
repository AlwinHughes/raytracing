#ifndef RENDERABLE
#define RENDERABLE

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include <png++/png.hpp>
#include "intersection.h"


class Renderable {

  public:
    virtual std::string toString() = 0;
    virtual bool hasPositiveInter(Ray) = 0;
    virtual Intersection* getPosInter(Ray) = 0;
    char char_col = '#';
    png::rgb_pixel pixel_col;
    Renderable(){};

};
#endif
