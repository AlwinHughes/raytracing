/*
 * takes 1.5 seconds with 13 object sceene, no reflections no shadows
 *
 * takes 3.26 seconds with same sceene with non self occluded shadows 
 * and no shading on
 *
 *
 *
 *
 *
 *
 *
 */
#include "controler.h"
#include <sstream>

void Controler::render(LightCol** raw_colours, int width, int height, float dy, float dz, int max_bounce, int rays_per_pixel) {

  std::cout << cam_pos.toString() << std::endl;
  std::cout << cam_direc.toString() << std::endl;

  for(int i = 0; i < width; i++) {
    raw_colours[i] = new LightCol[height];
    if(i %100 == 0) {
      std::cout << "Line " << i << std::endl;
    }
    for(int j = 0; j < height;
        j++){

      LightCol c(0,0,0);
      for(int k = 0; k < rays_per_pixel; k++) {

        //std::cout << i << " " << j << std::endl;
        //get the starting ray
        Vector3 extra(0, dz * (j - (float) height/ 2 ), dy * (i - (float) width/2));
        Ray ray(cam_pos, cam_direc + extra);

        //std::cout << ray.toString() << std::endl;

        Intersection inter = sceene.getClosestInter(ray, cam_pos);
        c = c + getColAtInter(inter, ray);

      }
      raw_colours[i][j] = c.scale(rays_per_pixel);
    }
  }
};

LightCol Controler::getColAtInter(Intersection inter, Ray ray) {
  
  if(inter.isEmpty() && sceene.isInShade(inter)) {
    //std::cout << "empty" << std::endl;
    return sceene.default_color;
  }
  
  //std::cout << inter.hit_object->toString() << std::endl;
  //simplest possible result
  return inter.hit_object->pixel_col;
};



std::string Controler::toString() {
  std::ostringstream ss;
  ss << "cam pos: " << cam_pos.toString() << " cam direc " << cam_direc.toString() << std::endl;

  ss << sceene.toString() << std::endl;;
  return ss.str();
};
