/*
#include "ray.h"
#include "sphere.h"
#include "plane.h"
#include "spheresceene.h"
#include "vector3.h"
#include "light_col.h"
#include <iostream>


#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <png++/png.hpp>

using namespace png;
using namespace std;

int consoleTracing() {

  int img_width = 200;
  int img_height = 100;

  Vector3 camera_start(0,0,0);

  Vector3 cam_direction(1,0,0);

  image<rgb_pixel> image (img_width, img_height);


  float dz = 0.005;
  float dy = 0.01;

  Vector3 sphere_center(4,0,0);
  float sphere_rad = 1;

  Sphere sphere(sphere_center, sphere_rad);


  SphereSceene sceene(10);
  sceene.addSphere(&sphere);

  Sphere* s2 = new Sphere(Vector3(1,0.3,0.3), 0.2, LightCol(1.0,0,0));
  s2->char_col = '~';
  sceene.addSphere(s2);

  Sphere* s3 = new Sphere(Vector3(4,-2, -0.3), 2, LightCol(0,0,0.1));
  s3->char_col = 'O';
  sceene.addSphere(s3);

  Sphere* s4 = new Sphere(Vector3(0.5,0,0), 0.01, LightCol(0.39,0.39,0.39));
  s4->char_col = '*';
  sceene.addSphere(s4);

  cout << sceene.toString();


  for(int k = 0; k < 500; k++) {

    Vector3 cam_pos(camera_start.x + 0.1*k, camera_start.y, camera_start.z);


    ostringstream console_image[img_height];

Intersection inter;
    for(int i = 0; i < img_width; i++) {
      for(int j = 0; j < img_height; j++){
        Vector3 extra(0,dy * (j - (float) img_height/2), dz * (i - (float) img_width/ 2 ));

        Ray ray(cam_pos, cam_direction + extra);


        inter = sceene.getClosestInter(ray, cam_pos); 


        if(!inter.isEmpty()) {
          console_image[j] << sceene.getClosestInter(ray, cam_pos).hit_object->char_col;
        } else {
          console_image[j] << '.';

        }


      }
    }

    for(int j = 0; j < img_height; j++){
      cout << console_image[j].str() << endl;;
    }

    cin.get();

  };


  return 0;

};

*/
