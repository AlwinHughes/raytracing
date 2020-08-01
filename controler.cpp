/*
 * takes 1.5 seconds with 13 object sceene, no reflections no shadows
 *
 * takes 3.26 seconds with same sceene with non self occluded shadows 
 * and no shading on
 *
 * takes 6.7 seconds with 4 lights but at (1600 by 800)
 *
 *
 * takes 1m21s at 2000x1000 with 8 rays per pixel; or 11 sec at 1 ray per pixel; or 7m2s at 32 rays per pixel
 *
 *
 */
#include "controler.h"
#include <sstream>


//void render(LightCol** raw_cols, int width, int height, float dy, float dz, int max_bounce = 1, int rays_per_pixel = 1, int difuse_rays = 0);

void Controler::render(LightCol** raw_colours, int width, int height, float dy, float dz, int max_bounce, int rays_per_pixel, int difuse_rays) {

  std::cout << cam_pos.toString() << std::endl;
  std::cout << cam_direc.toString() << std::endl;


  if(rays_per_pixel == 1) {

    srand(time(NULL));

    for(int i = 0; i < width; i++) {
      raw_colours[i] = new LightCol[height];
      if(i %10 == 0) {
        std::cout << "Column " << i << std::endl;
      }
      for(int j = 0; j < height;j++){

        srand(time(NULL));
        LightCol c(0,0,0);

        //get the starting ray
        Vector3 extra(0, dz * (j - (float) height/ 2 ), dy * (i - (float) width/2));
        Ray ray(cam_pos, cam_direc + extra);

        Intersection inter = sceene.getClosestInter(ray, cam_pos);
        //std::cout << "bounces " << inter.bounces << std::endl;
        if(!inter.isEmpty()) {
          c = inter.hit_object->material->getColAtInter(inter,ray);
        }

        raw_colours[i][j] = c;
      }
    }

  } else {

    srand(time(NULL));
    for(int i = 0; i < width; i++) {
      raw_colours[i] = new LightCol[height];
      if(i %10 == 0) {
        std::cout << "Column " << i << std::endl;
      }
      for(int j = 0; j < height;j++){
        LightCol c(0,0,0);

        for(int k = 0; k < rays_per_pixel; k++) {
          int r1 = rand() % 1000000;
          int r2 = rand() % 1000000;
          //define jitter
          float zj = (float) r1 / 1000000.0;
          float yj = (float) r2 / 1000000.0;

         // std::cout << zj << " " << yj << std::endl;

          //std::cout << i << " " << j << std::endl;
          //get the starting ray
          Vector3 extra(0, dz * (j + zj - (float) height/ 2 ), dy * (i  + yj - (float) width/2));
          Ray ray(cam_pos, cam_direc + extra);

          Intersection inter = sceene.getClosestInter(ray, cam_pos);
          if(!inter.isEmpty()) {
            c = c + inter.hit_object->material->getColAtInter(inter,ray);
            //std::cout << "not empty" << std::endl;
          }
          //c = c + getColAtInter(inter, ray, max_bounce, difuse_rays);

        }
        raw_colours[i][j] = c.scale(1.0 / (float) rays_per_pixel);
      }
    }

  }

};

LightCol Controler::getColAtInter(Intersection inter, Ray ray, int max_bounce, int difuse_rays) {

  if(inter.isEmpty()) { 
    //std::cout << "empty" << std::endl;
    return sceene.default_color;
  }

  Light* lights = sceene.getLights();
  LightCol lc(0,0,0);

  /*

  for(int i = 0; i < sceene.curr_num_lights; i++) {

    Vector3 v = lights[i]->pos - inter.pos;
    if(inter.hit_object->apply_dot){
      float f = inter.normal.Dot(v);
      if(f < 0) {
        //std::cout << "wrong side" << std::endl;
        //lc = lc + sceene.default_color;
        continue;
      }
    }

    if(sceene.isInShade(inter, lights[i])) {
      //lc = lc + sceene.default_color;
      //std::cout << "shade" << std::endl;
      continue;
    }

    //std::cout << inter.hit_object->toString() << std::endl;
    //simplest possible result



    //std::cout << v.normalize().Dot(inter.normal) << std::endl;
    lc = lc + inter.hit_object->pixel_col.reflect(lights[i]->lc).scale(v.normalize().Dot(inter.normal) * lights[i]->brightness );
    // didn't work properly did look cool though /v.squareDist()

  }

  if(inter.hit_object->use_scattering && inter.bounces < max_bounce) {
    for(int i = 0; i < difuse_rays; i++) {

      Vector3 u = Vector3(0, -inter.normal.x, inter.normal.y).normalize();
      Vector3 v = u.cross(inter.normal);
      
      //now u, v and inter.normal form an ortogonal basis

      int r = rand() % 1000000;
      //define jitter
      float uj = (float) (r % 1000) / 1000.0;
      uj = 2.0*(uj -0.5);
      float vj = (float) (r - r % 1000) / 1000000.0;
      vj = 2.0*(vj -0.5);

      Vector3 new_direction = inter.normal + (u * uj) + (v * vj);
      Ray new_r = Ray(inter.pos, new_direction);

      Intersection new_inter = sceene.getClosestInter(new_r, cam_pos);
      new_inter.bounces = inter.bounces + 1;
      lc = lc + inter.hit_object->pixel_col.reflect(getColAtInter(new_inter, new_r, max_bounce, difuse_rays).scale(0.5 / difuse_rays));

    }
  }
  */

  /*
  if(inter.use_scattering && inter.bounces < max_bounce) {
    for(int i = 0; i < difuse_rays; i++) {
          int r = rand() % 1000000;
          //define jitter
          float x = (float) (r % 100) / 100.0;
          float z = (float) (r % 10000) / 1000000;
          float y = (float) ((r - r % 100) % 100) / 10000;


    }
  }
  */

  return lc;
};



std::string Controler::toString() {
  std::ostringstream ss;
  ss << "cam pos: " << cam_pos.toString() << " cam direc " << cam_direc.toString() << std::endl;

  ss << sceene.toString() << std::endl;;
  return ss.str();
};
