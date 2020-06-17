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
    }

    //delete inter;
  }

  return best;
};

bool FixedSceene::isInShade(Intersection* inter) {
  Intersection* new_inter;
  float inter_to_light_dist = (inter->pos - light->pos).squareDist();
  for(int i = 0; i < curr_num_obj; i ++) {
    //checks if other objects occule the light

    
    if(renderable_objs[i] != inter->hit_object){
      //shoots ray from the light to the intersection
      new_inter = renderable_objs[i]->getPosInter(Ray(light->pos, inter->pos - light->pos));

      /*
      if(new_inter) {
        std::cout << "new inter pos " << new_inter->pos.toString() << std::endl;
      } else {
        std::cout << "no intersection" << std::endl;
      }
      */

//      if(new_inter && (new_inter->pos - light->pos).squareDist() < inter_to_light_dist) {
        if(new_inter && (new_inter->pos - light->pos).squareDist() < inter_to_light_dist) {
       //std::cout << "occluded by: " << renderable_objs[i]->toString() << std::endl;
        delete new_inter;
        return true;
      }

      delete new_inter;

    }
  }

  //check if the object occuldes its self
  //currently not working for spheres
  //return false;


  new_inter = inter->hit_object->getPosInter(Ray(light->pos, inter->pos - light->pos));

  if(new_inter && (new_inter->pos - inter->pos).squareDist() > 0.01) {
    
    delete new_inter;
    //self occlues 
    return true;

  }

  delete new_inter;
  //self object is not occluded
  return false;
  
  
  Intersection* self_inter = inter->hit_object->getPosInter(Ray(light->pos, inter->pos - light->pos));
  
  
  
  
  if(self_inter &&  self_inter->pos.Dot(  light->pos * -1.0) < 0.0000000001) {
    //when we move from the light to the intersection
    //the closest point of intersection is the same
    //as the original point of intersection
    //std::cout << "not occluded" << std::endl;
    delete self_inter;
    return false;
  }
  

  delete self_inter;
  //std:: cout << "self occluded" << std::endl;
  return true;
};

std::string FixedSceene::toString() {

  std::ostringstream ss;

  ss << "Fixed Sceene has " << curr_num_obj << " of a total of " << max_num_objs << " they are: " << std::endl;

  for(int i = 0; i < curr_num_obj; i++) {
    ss << renderable_objs[i]->toString() << std::endl;
  }

  return ss.str();
}





