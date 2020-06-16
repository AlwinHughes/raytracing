#include "ray.h"
#include "sphere.h"
#include "plane.h"
#include "spheresceene.h"
#include "vector3.h"
#include "fixedsceene.h"
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

  Vector3 camera_start(0,-4,0);

  Vector3 cam_direction(1,0,0);

  image<rgb_pixel> image (img_width, img_height);

  /*
  FixedSceene sceene(10);

  //Sphere sphere(sphere_center, sphere_rad, rgb_pixel(0,255,0));
  //sceene.addRenderable(&sphere);

  
  Sphere* s1 = new Sphere(Vector3(10,0,5), 1, rgb_pixel(255,0,0));
  sceene.addRenderable(s1);


  Sphere* s2 = new Sphere(Vector3(12,0,-2), 0.5, rgb_pixel(0,255,0));
  sceene.addRenderable(s2);
  
  Sphere* s3 = new Sphere(Vector3(20,0,2), 2, rgb_pixel(0,0,200));
  sceene.addRenderable(s3);
  
  Sphere* s4 = new Sphere(Vector3(20,0,-5), 0.5, rgb_pixel(200,200,00));
  sceene.addRenderable(s4);
  
  Sphere* s5 = new Sphere(Vector3(20,-3,-5), 0.5, rgb_pixel(200,0,100));
  sceene.addRenderable(s5);
  
  Sphere* s6 = new Sphere(Vector3(15.5,-3,-2), 0.5, rgb_pixel(200,0,100));
  sceene.addRenderable(s6);

  Light* light = new Light(Vector3(10,-10,-10));

  Plane* p1 = new Plane(Vector3(0,1,0), 0, rgb_pixel(150,150,150));
  sceene.addRenderable(p1);

  sceene.setLight(light);
  */
  
  FixedSceene sceene(20);

  Light* light = new Light(Vector3(15,-10,0));
  sceene.setLight(light);

  Plane* p1 = new Plane(Vector3(0,1,0), 0, rgb_pixel(150,150,150));
  sceene.addRenderable(p1);

  Sphere* s1 = new Sphere(Vector3(10,-1,0),0.5, rgb_pixel(200,0,0));
  sceene.addRenderable(s1);

  Sphere* s2 = new Sphere(Vector3(15,-1,5),0.5, rgb_pixel(200,0,0));
  sceene.addRenderable(s2);

  Sphere* s3 = new Sphere(Vector3(15,-1,-5),0.5, rgb_pixel(200,0,0));
  sceene.addRenderable(s3);

  Sphere* s4 = new Sphere(Vector3(25,-1,0),0.5, rgb_pixel(200,0,0));
  sceene.addRenderable(s4);

  Sphere* s5 = new Sphere(Vector3(15,-3,0),0.5, rgb_pixel(200,0,200));
  sceene.addRenderable(s5);

  Sphere* s6 = new Sphere(Vector3(15,1,0),3, rgb_pixel(100,200,200));
  sceene.addRenderable(s6);

  Sphere* s7 = new Sphere(Vector3(15,1,8),3, rgb_pixel(100,200,200));
  sceene.addRenderable(s7);

  Sphere* s8 = new Sphere(Vector3(15,-4,-3),0.2, rgb_pixel(100,0,200));
  sceene.addRenderable(s8);

  Sphere* s9 = new Sphere(Vector3(15,-10,-5),2, rgb_pixel(0,200,100));
  sceene.addRenderable(s9);


  Plane* p2 = new Plane(Vector3(0,0,1), -8, rgb_pixel(100,100,150));
  sceene.addRenderable(p2);


  /*
  FixedSceene sceene(5);
  Sphere* ts1 = new Sphere(Vector3(10,0,5), 1, rgb_pixel(255,0,0));
  sceene.addRenderable(ts1);

  Plane* tp1 = new Plane(Vector3(0,1,0), 0, rgb_pixel(150,150,150));
  sceene.addRenderable(tp1);

  Light* test_light = new Light(Vector3(10,-10,-10));
  sceene.setLight(test_light);

  Sphere* loc = new Sphere(Vector3(10,-1,3.5), 0.1, rgb_pixel(255,0,0));
  sceene.addRenderable(loc);

  Intersection* test_inter = new Intersection(tp1, Vector3(10,0,3.5));

  cout << test_light->toString() << endl;

  cout << "starting intersection " << test_inter->toString() << endl;

  cout << "is in shade? " << sceene.isInShade(test_inter) << endl;

  delete test_inter;
  */

  std::cout << sceene.toString() << endl;

  Vector3 cam_pos = camera_start;

  Intersection* inter;

  //return;

  /*
  inter = sceene.getClosestInter(Ray(Vector3(2.2,1,10), Vector3(1,0,0)),camera_start);


  if(!inter) {
    cout << "is null" << endl;
  } else {

    cout << inter->toString() << endl;

    Ray light_ray(inter->pos, light->pos - inter->pos);
    cout << light_ray.toString() << endl;

    cout << "in line: " << light_ray.containsPoint(light->pos) << endl;

    Intersection* self_inter = s1->getPosInter(light_ray);

    if(self_inter) {
      cout << "self inter: " <<self_inter->toString() << endl;
    } else {
      cout << "no self intersection" << endl;
    }
  }
  */




//  cout << "are they the same ? " << cam_pos.Equal(camera_start) << endl;



  rgb_pixel shadow_col(10,10,10);

  for(int i = 0; i < img_width; i++) {
    for(int j = 0; j < img_height; j++){


      Vector3 extra(0,dy * (j - (float) img_height/2), dz * (i - (float) img_width/ 2 ));

      Ray ray(cam_pos, cam_direction + extra);

      inter = sceene.getClosestInter(ray, cam_pos);


      if(inter != NULL) {
        //light has hit an object

        if(sceene.isInShade(inter)) {
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
