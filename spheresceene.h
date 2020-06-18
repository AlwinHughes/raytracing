#ifndef SPHERESCEENE
#define SPHERESCEENE

#include "vector3.h"
#include "sphere.h"
#include "ray.h"

class SphereSceene {

  private:
    Sphere* spheres;
    int curr_num_sphres;


  public:
    int max_num_spheres;
    bool hasIntersection(Ray);
    bool hasPositiveInter(Ray);
    Intersection getClosestInter(Ray, Vector3);
    SphereSceene(int);
    SphereSceene(Sphere*, int);
    void addSphere(Sphere*);
    bool isInShade(Intersection, Vector3);
    std::string toString();

};
#endif
