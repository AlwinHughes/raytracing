#include "fixedsceene.h"
#include <limits>
#include <sstream>

FixedSceene::FixedSceene(int n, int m = 0) {
  curr_num_obj = 0;
  max_num_objs = n;
  renderable_objs = new Renderable[n]; 
  curr_num_lights = 0;
  max_num_lights = m;
  lights = new Light[m];
};

/*
FixedSceene::FixedSceene(Renderable* objs, int n, int m = 1) {
  curr_num_obj = n;
  max_num_objs = n;
  renderable_objs = objs;
  curr_num_lights = m;
};
*/


void FixedSceene::addRenderable(Renderable rend) {
  if(curr_num_obj < max_num_objs) {
    renderable_objs[curr_num_obj] = rend;
    //geometry needs a reference to its parent 
    renderable_objs[curr_num_obj].geometry->parent = &renderable_objs[curr_num_obj];
    renderable_objs[curr_num_obj].material->sceene = this;
    renderable_objs[curr_num_obj].material->parent = &renderable_objs[curr_num_obj];
    curr_num_obj++;
  }
};

void FixedSceene::addLight(Light l) {
  if(curr_num_lights < max_num_lights) {
    lights[curr_num_lights] = l;
    curr_num_lights++;
  }
};

bool FixedSceene::hasPositiveInter(const Ray& ray) const {
  for(int i = 0; i < curr_num_obj; i++) {
    if(renderable_objs[i].geometry->hasPositiveInter(ray)) {
      return true;
    }
  }
  return false;
};

Intersection FixedSceene::getClosestInter(const Ray& ray, Vector3 cam_pos) const {

  float curr_dist_2 = std::numeric_limits<float>::max();

  Intersection inter;
  Intersection best;

  for(int i = 0; i < curr_num_obj; i++) {

    inter = renderable_objs[i].geometry->getPosInter(ray);

    if(inter.isEmpty()) {
      continue;
    }

    float dist = (inter.pos - cam_pos).squareDist();

    if(dist < curr_dist_2) {
      best = inter;
      curr_dist_2 = dist;
    }
  }

  return best;
};

Intersection FixedSceene::getClosestInter(const Ray& ray, const Vector3 cam_pos, const Renderable* avoid) const {

  float curr_dist_2 = std::numeric_limits<float>::max();

  Intersection inter;
  Intersection best;

  for(int i = 0; i < curr_num_obj; i++) {
    if(avoid == &renderable_objs[i]) {

      //std::cout << "found same " << std::endl;
      //we want to avoid this specific object
      continue;
    }

    inter = renderable_objs[i].geometry->getPosInter(ray);

    if(inter.isEmpty()) {
      continue;
    }

    float dist = (inter.pos - cam_pos).squareDist();

    if(dist < curr_dist_2) {
      best = inter;
      curr_dist_2 = dist;
    }
  }
  return best;
};


//am i in shade from this particular light?
bool FixedSceene::isInShade(const Intersection& inter, Light* l) const {
  Intersection light_inter;

  float inter_to_light_dist = (inter.pos - l->pos).squareDist();
  for(int i = 0; i < curr_num_obj; i ++) {
    //checks if other objects occule the light

    
    if(renderable_objs[i].can_occlude && &renderable_objs[i] != inter.hit_object){
      //shoots ray from the light to the intersection
      light_inter = renderable_objs[i].geometry->getPosInter(Ray(l->pos, inter.pos - l->pos));

      if(!light_inter.isEmpty() && (light_inter.pos - l->pos).squareDist() < inter_to_light_dist) {
        //occluded by a different object
        //std::cout << "occluded other" << std::endl;
        return true;
      }

    }
  }

    //check if the objects is occlusing its self by 
    //shooting a ray from the light to the object and 
    //checking that difference bewteen the new intersection 
    //and first intersection isn't too big


  light_inter = inter.hit_object->geometry->getPosInter(Ray(l->pos, inter.pos - l->pos));

  if(!light_inter.isEmpty() && (light_inter.pos - inter.pos).squareDist() > 0.000001) {
    //std::cout << "occluded self" << std::endl;
    return true;

  }

  return false;
};


std::string FixedSceene::toString() const {

  std::ostringstream ss;

  ss << "Fixed Sceene has " << curr_num_obj << " of a total of " << max_num_objs << " they are: " << std::endl;

  for(int i = 0; i < curr_num_obj; i++) {
    ss << renderable_objs[i].toString() << std::endl;
  }

  return ss.str();
};


/*
Ray FixedSceene::getRayFromLight(Vector3 target) {
  return Ray(light->pos, target - light->pos);
}
*/
