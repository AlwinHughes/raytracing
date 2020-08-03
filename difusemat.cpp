#include "difusemat.h"
#include <math.h>

std::string DifuseMat::toString() const {
  std::ostringstream ss;
  ss << "Difuse mat with " << difuseion << color.toString(); 
  return ss.str();
};

LightCol DifuseMat::getColAtInter(const Intersection& inter, const Ray& ray) const { 

  Light* lights = sceene->getLights();
  LightCol lc(0,0,0);


  for(int i = 0; i < sceene->curr_num_lights; i++) {

    Vector3 v = lights[i].pos - inter.pos;

    if(inter.normal.Dot(v) < 0) {
      continue;
    }

    if(sceene->isInShade(inter, lights + i)) {
      continue;
    }

    lc = lc + color.reflect(lights[i].lc).scale(v.normalize().Dot(inter.normal) * lights[i].brightness);
  }

      //std::cout << "bounces " << inter.bounces << " max " << this->max_bounce << std::endl;
  //only do difuse if we are in shade not any more
  if(inter.bounces < max_bounce  ) {

    
    LightCol c(0,0,0);

    for(int i = 0; i < max_difuse_rays; i++) {

      //std::cout << "bounces " << inter.bounces << std::endl;

      Vector3 u = Vector3(0, -inter.normal.x, inter.normal.y).normalize();
      Vector3 v = u.cross(inter.normal);
      //now u, v and inter.normal form an ortogonal basis

      int r1 = rand() % 10000;
      int r2 = rand() % 10000;
      //define jitter
      float uj = (float) r1 / 10000.0;
      uj = 2.0*(uj -0.5) * difuseion;
      float vj = (float) r2 / 10000.0;
      vj = 2.0*(vj -0.5) * difuseion;

      Vector3 new_direction = inter.normal + (u * uj) + (v * vj);
      Ray new_ray = Ray(inter.pos, new_direction);

      Intersection new_inter = sceene->getClosestInter(new_ray, inter.pos,this->parent);
      new_inter.bounces = inter.bounces + 1;

      if(!new_inter.isEmpty()) {
        c = c + color.reflect(new_inter.hit_object->material->getColAtInter(new_inter,new_ray));
      }

    }

    lc = lc + c.scale(0.5/(float) max_difuse_rays);
  }

  return lc;
};

