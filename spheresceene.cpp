#include "spheresceene.h"
#include "sphere.h"
#include "intersection.h"
#include "ray.h"
#include <sstream>
#include <limits>
#include <iostream>


bool SphereSceene::hasIntersection(Ray ray) {
  for(int i = 0; i < curr_num_sphres; i++) {
    if(spheres[i].doesIntersect(ray)) {
      return true;
    }
  }
  return false;
};

bool SphereSceene::hasPositiveInter(Ray ray) {
  for(int i = 0; i < curr_num_sphres; i++) {
    if(spheres[i].hasPositiveInter(ray)) {
      return true;
    }
  }
  return false;
};

bool SphereSceene::isInShade(Intersection* inter, Vector3 light_pos) {
  for(int i = 0; i < curr_num_sphres; i ++) {
    if(&spheres[i] != inter->hit_object && spheres[i].hasPositiveInter(Ray(inter->pos,light_pos - inter->pos))) {
      return true;
    }
  }
  return false;
}


SphereSceene::SphereSceene(int n) {
  max_num_spheres = n;
  curr_num_sphres = 0; 
  spheres = new Sphere[n];
};

SphereSceene::SphereSceene(Sphere* new_spheres, int n){
  curr_num_sphres = n;
  max_num_spheres = n;
  spheres = new_spheres;
};

void SphereSceene::addSphere(Sphere* s) {
  if(curr_num_sphres < max_num_spheres) {
    spheres[curr_num_sphres] = *s;
    curr_num_sphres++;
  }
};

std::string SphereSceene::toString(){
  std::ostringstream ss;
  ss << "Contains " << curr_num_sphres << " spheres of a max of " << max_num_spheres << std::endl;
  
  for(int i = 0; i < curr_num_sphres; i++) {
    ss << spheres[i].toString() << std::endl;
  }

  return ss.str();
};

Intersection* SphereSceene::getClosestInter(Ray ray, Vector3 cam_pos) {
  float curr_dist_2 = std::numeric_limits<float>::max();

  Intersection* inter;
  Intersection* best = NULL;


  for(int i = 0; i < curr_num_sphres; i++) {
    inter = spheres[i].getInter(ray);

    if(inter == NULL) {
      continue;
    }

    if((inter->pos - cam_pos).squareDist() < curr_dist_2) {
      best = inter;
    }
  }

  return best;
};



