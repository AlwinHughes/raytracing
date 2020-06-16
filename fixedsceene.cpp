#include "fixedsceene.h"
#include <limits>
#include <sstream>

FixedSceene::FixedSceene(int n) {
  curr_num_obj = 0;
  max_num_objs = n;
  renderable_objs = new Renderable*[n];
};


void FixedSceene::addRenderable(Renderable* rend) {
  if(curr_num_obj < max_num_objs) {
    renderable_objs[curr_num_obj] = rend;
  }
};

void FixedSceene::setLight(Light * l) {
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

    if((inter->pos - cam_pos).squareDist() < curr_dist_2) {
      best = inter;
    }

    delete inter;
  }

  return best;
};

bool FixedSceene::isInShade(Intersection* inter) {
  for(int i = 0; i < curr_num_obj; i ++) {
    if(renderable_objs[i] != inter->hit_object && renderable_objs[i]->hasPositiveInter(Ray(inter->pos,light->pos - inter->pos))) {
      return true;
    }
  }
  return false;
}

std::string FixedSceene::toString() {

  std::ostringstream ss;

  ss << "Fixed Sceene has " << curr_num_obj << " of a total of " << max_num_objs << " they are: " << std::endl;

  for(int i = 0; i < curr_num_obj; i++) {
    ss << renderable_objs[i]->toString() << std::endl;
  }

  return ss.str();
}





