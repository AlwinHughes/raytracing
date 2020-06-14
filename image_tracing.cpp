#include "ray.h"
#include "sphere.h"
#include "plane.h"
#include "spheresceene.h"
#include "vector3.h"
#include "light.h"

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace png;
using namespace std;

void imageTracing() {

  int img_width = 2000;
  int img_height = 1000;
  
  float dz = 0.001;
  float dy = 0.001;

  Vector3 camera_start(0,0,0);

  Vector3 cam_direction(1,0,0);

  image<rgb_pixel> image (img_width, img_height);


  Vector3 sphere_center(4,0,0);
  float sphere_rad = 1;

  Sphere sphere(sphere_center, sphere_rad, rgb_pixel(0,255,0));


  SphereSceene sceene(10);

  Sphere * s1 = new Sphere(Vector3(10,0,0), 2, rgb_pixel(200,0,100));
  sceene.addSphere(s1);



  
  Sphere* s2 = new Sphere(Vector3(5,0,2), 0.2, rgb_pixel(255,0,0));
  s2->char_col = '~';
  sceene.addSphere(s2);
  
  /*

  Sphere* s3 = new Sphere(Vector3(4,-2, -0.3), 2, rgb_pixel(0,0,255));
  s3->char_col = 'O';
  sceene.addSphere(s3);
  

  Sphere* s4 = new Sphere(Vector3(0.5,0,0), 0.01, rgb_pixel(100,100,100));
  s4->char_col = '*';
  sceene.addSphere(s4);
  */

  std::cout << sceene.toString();

  Vector3 cam_pos = camera_start;

  Intersection* inter;

  Light light(Vector3(0,0,4));

  rgb_pixel shadow_col(10,10,10);

  for(int i = 0; i < img_width; i++) {
    for(int j = 0; j < img_height; j++){


      Vector3 extra(0,dy * (j - (float) img_height/2), dz * (i - (float) img_width/ 2 ));

      Ray ray(cam_pos, cam_direction + extra);

      inter = sceene.getClosestInter(ray, cam_pos);

      if(inter != NULL) {
        //light has hit an object

        if(sceene.isInShade(inter, light.pos)) {
          //in shaddow. set the shadow using the predefined shadow color
          image[j][i] = shadow_col;
        } else {
          image[j][i] = inter->hit_object->pixel_col;
        }
      } else {
        image[j][i] = rgb_pixel(0,0,0);
      }

      delete inter;
    }
  }


  image.write("image.png");
};
