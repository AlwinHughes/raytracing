#include "metalicmat.h"
#include <math.h>

std::string MetalicMat::toString() const {
  std::ostringstream ss;
  ss << "metalic mat with "  << color.toString(); 
  return ss.str();
};

LightCol MetalicMat::getColAtInter(const Intersection& inter, const Ray& ray) const { 

  LightCol lc(0,0,0);
  Light* lights = sceene->getLights();

  Vector3 new_direc = ray.grad + (inter.normal * (ray.grad.Dot(inter.normal)) * (-2));

  Vector3 u = Vector3(0, -inter.normal.x, inter.normal.y).normalize();
  Vector3 v = u.cross(inter.normal);

  int r1 = rand() % 10000;
  int r2 = rand() % 10000;
  //define jitter
  float uj = (float) r1 / 10000.0;
  uj = 2.0*(uj -0.5) * metalic_param;
  float vj = (float) r2 / 10000.0;
  vj = 2.0*(vj -0.5) * metalic_param;

  Vector3 new_direction = inter.normal + (u * uj) + (v * vj);
  Ray new_ray = Ray(inter.pos, new_direction);

  Intersection new_inter = sceene->getClosestInter(new_ray, inter.pos,this->parent);

  if(!new_inter.isEmpty()) {

    new_inter.bounces = inter.bounces;
    lc = color.reflect(new_inter.hit_object->material->getColAtInter(new_inter, new_ray)).scale(metal_weight);
  }


  LightCol lc2(0,0,0);


  for(int i = 0; i < sceene->curr_num_lights; i++) {

    Vector3 v = lights[i].pos - inter.pos;

    if(inter.normal.Dot(v) < 0) {
      continue;
    }

    if(sceene->isInShade(inter, lights + i)) {
      continue;
    }

    lc = lc + lights[i].lc.scale(shiny_weight * pow((ray.grad.invert() + v).normalize().Dot(inter.normal),shiny_param));
  }

  return lc;
};

