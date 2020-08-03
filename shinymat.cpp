#include "shinymat.h"
#include <math.h>

std::string ShinyMat::toString() const {
  std::ostringstream ss;
  ss << "Shiny mat with "  << color.toString(); 
  return ss.str();
};

LightCol ShinyMat::getColAtInter(const Intersection& inter, const Ray& ray) const { 

  LightCol lc = DifuseMat::getColAtInter(inter, ray);
  Light* lights = sceene->getLights();

  for(int i = 0; i < sceene->curr_num_lights; i++) {

    Vector3 v = lights[i].pos - inter.pos;

    if(inter.normal.Dot(v) < 0) {
      continue;
    }

    if(sceene->isInShade(inter, lights + i)) {
      continue;
    }

    
    /*
    std::cout << "light " << lights[i].lc.toString() << std::endl;
    std::cout << "scale " << (ray.grad.invert() + v).normalize().Dot(inter.normal) << std::endl;
    std::cout << "scale lights " << lights[i].lc.scale((ray.grad.invert() + v).normalize().Dot(inter.normal)).toString() << std::endl;
    */
    


    lc = lc + lights[i].lc.scale(pow((ray.grad.invert() + v).normalize().Dot(inter.normal),shiny_param));

  }

  return lc;

};

