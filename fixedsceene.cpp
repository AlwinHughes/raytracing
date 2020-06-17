#include "fixedsceene.h"
#include <limits>
#include <sstream>

FixedSceene::FixedSceene(int n) {
  curr_num_obj = 0;
  max_num_objs = n;
  renderable_objs = new Renderable*[n];
};

FixedSceene::FixedSceene(Renderable** objs, int n) {
  curr_num_obj = n;
  max_num_objs = n;
  renderable_objs = objs;
};


void FixedSceene::addRenderable(Renderable* rend) {
  if(curr_num_obj < max_num_objs) {
    renderable_objs[curr_num_obj] = rend;
    curr_num_obj++;
  }
};

void FixedSceene::setLight(Light* l) {
  light = l;
};

bool FixedSceene::hasPositiveInter(Ray ray) {
  for(int i = 0; i < curr_num_obj; i++) {
    if(renderable_objs[i]->hasPositiveInter(ray)) {
      return true;
    }
  }
  return false;
};

Intersection* FixedSceene::getClosestInter(Ray ray, Vector3 cam_pos) {

  float curr_dist_2 = std::numeric_limits<float>::max();

  Intersection* inter;
  Intersection* best = NULL;

  for(int i = 0; i < curr_num_obj; i++) {
    inter = renderable_objs[i]->getPosInter(ray);

    if(inter == NULL) {
      continue;
    }

    float dist = (inter->pos - cam_pos).squareDist();

    if(dist < curr_dist_2) {
      best = inter;
      curr_dist_2 = dist;
    } else {
      delete inter;
    }
  }

  return best;
};

Intersection* FixedSceene::getClosestInter(Ray ray, Vector3 cam_pos, Renderable* avoid) {

  float curr_dist_2 = std::numeric_limits<float>::max();

  Intersection* inter;
  Intersection* best = NULL;

  for(int i = 0; i < curr_num_obj; i++) {
    if(avoid == renderable_objs[i]) {
      //we want to avoid this specific object
      continue;
    }

    inter = renderable_objs[i]->getPosInter(ray);

    if(inter == NULL) {
      continue;
    }

    float dist = (inter->pos - cam_pos).squareDist();

    if(dist < curr_dist_2) {
      best = inter;
      curr_dist_2 = dist;
    } else {
      delete inter;
    }
  }

  return best;
};


bool FixedSceene::isInShade(Intersection* inter) {


  Intersection* light_inter;

  float inter_to_light_dist = (inter->pos - light->pos).squareDist();
  for(int i = 0; i < curr_num_obj; i ++) {
    //checks if other objects occule the light

    
    if(renderable_objs[i]->can_occlude && renderable_objs[i] != inter->hit_object){
      //shoots ray from the light to the intersection
      light_inter = renderable_objs[i]->getPosInter(Ray(light->pos, inter->pos - light->pos));

      if(light_inter && (light_inter->pos - light->pos).squareDist() < inter_to_light_dist) {
        //occluded by a different object
        delete light_inter;
        return true;
      }

      delete light_inter;

    }
  }

    //check if the objects is occlusing its self by 
    //shooting a ray from the light to the object and 
    //checking that difference bewteen the new intersection 
    //and first intersection isn't too big


  light_inter = inter->hit_object->getPosInter(Ray(light->pos, inter->pos - light->pos));

  if(light_inter && (light_inter->pos - inter->pos).squareDist() > 0.00001) {
    
    delete light_inter;
    //self occlues 
    return true;

  }

  delete light_inter;
  //self object is not occluded
  return false;
};

std::string FixedSceene::toString() {

  std::ostringstream ss;

  ss << "Fixed Sceene has " << curr_num_obj << " of a total of " << max_num_objs << " they are: " << std::endl;

  for(int i = 0; i < curr_num_obj; i++) {
    ss << renderable_objs[i]->toString() << std::endl;
  }

  return ss.str();
}

rgb_pixel FixedSceene::getColAtInter(Intersection* inter, Ray insident_ray) {
  return inter->hit_object->getColAtInter(inter, insident_ray, this);
}

Ray FixedSceene::getRayFromLight(Vector3 target) {
  return Ray(light->pos, target - light->pos);
}
