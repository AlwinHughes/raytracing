#include "ray.h"
#include "sphere.h"
#include "sphere2.h"
#include "rsphere.h"
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
#include <fstream>

using namespace png;
using namespace std;

void imageTracing(bool write = true) {

  fstream file;

  file.open("count", ofstream::in);
  string count;
  getline(file, count);
  file.close();

  count = to_string((stoi(count) + 1));
cout << "count : "<< count <<  endl; int img_width = 2000;
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

  Light* light = new Light(Vector3(15,-50,0));
  sceene.setLight(light);

  Plane* p1 = new Plane(Vector3(0,1,0), 0, rgb_pixel(150,150,150));
  p1->shade_pixel_col = rgb_pixel(70,70,70);
  sceene.addRenderable(p1);

  Sphere* s1 = new Sphere2(Vector3(10,-1,0),0.5, rgb_pixel(200,0,0), true, true);
  s1->shade_pixel_col = rgb_pixel(100,0,0);
  sceene.addRenderable(s1);

  Sphere* s2 = new Sphere2(Vector3(15,-1,5),0.5, rgb_pixel(200,0,0));
  s2->shade_pixel_col = rgb_pixel(100,0,0);
  sceene.addRenderable(s2);

  Sphere* s3 = new Sphere2(Vector3(15,-1,-5),0.5, rgb_pixel(200,0,0), false, false);
  s3->shade_pixel_col = rgb_pixel(100,0,0);
  sceene.addRenderable(s3);

  Sphere* s4 = new Sphere2(Vector3(25,-1,0),0.5, rgb_pixel(200,0,0));
  s4->shade_pixel_col = rgb_pixel(100,0,0);
  sceene.addRenderable(s4);

  Sphere* s5 = new Sphere2(Vector3(15,-3,0),0.5, rgb_pixel(200,0,200));
  s5->shade_pixel_col = rgb_pixel(100,0,100);
  sceene.addRenderable(s5);

  Sphere* s6 = new Sphere2(Vector3(15,1,0),3, rgb_pixel(100,200,200));
  s6->shade_pixel_col = rgb_pixel(50,100,100);
  sceene.addRenderable(s6);

  Sphere* s7 = new Sphere2(Vector3(20,1,8),3, rgb_pixel(100,200,200));
  s7->shade_pixel_col = rgb_pixel(50,100,100);
  sceene.addRenderable(s7);

  Sphere* s8 = new Sphere2(Vector3(15,-4,-3),0.2, rgb_pixel(100,0,200));
  s8->shade_pixel_col = rgb_pixel(50,0,100);
  sceene.addRenderable(s8);

  Sphere* s9 = new Sphere2(Vector3(15,-10,-5),2, rgb_pixel(0,200,100), true, true);
  s9->shade_pixel_col = rgb_pixel(0,100,50);
  sceene.addRenderable(s9);

  Sphere* s10 = new RSphere(Vector3(70,-3,4),20);
  sceene.addRenderable(s10);


  Plane* p2 = new Plane(Vector3(0,0,1), -8, rgb_pixel(100,100,150));
  p2->shade_pixel_col = rgb_pixel(50,50,75);
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

  rgb_pixel pixel = rgb_pixel(0.2,30,40);

  cout << "pixel red " << (int) pixel.red << endl;

  //return;


  rgb_pixel shadow_col(10,10,10);

  for(int i = 0; i < img_width; i++) {
    for(int j = 0; j < img_height; j++){


      Vector3 extra(0,dy * (j - (float) img_height/2), dz * (i - (float) img_width/ 2 ));

      Ray ray(cam_pos, cam_direction + extra);

      inter = sceene.getClosestInter(ray, cam_pos);

      if(inter != NULL) {
        //light has hit an object

        image[j][i] = sceene.getColAtInter(inter, ray);

      } else {
        image[j][i] = sceene.default_color;
      }

      delete inter;
    }

    if(i % 200 == 0) {
      cout << "finished column: " << i << endl;
    }
  }

  if(write){

    image.write("./images/image" + count + ".png");

    ofstream ofile;
    ofile.open("count", ofstream::trunc);
    ofile << count;
    ofile.close();

    cout << "./images/image" << count << ".png";
  }

};
