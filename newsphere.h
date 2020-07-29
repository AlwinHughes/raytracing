#ifndef NEWSPHERE
#define NEWSPHERE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "light_col.h"
#include "fixedsceene.h"
#include <png++/png.hpp>

class NewSphere : public Renderable {

  public:
    std::string toString();
    NewSphere(Intersectable geom, Material mat) : geometry(geom), material(mat) {};
};

#endif
