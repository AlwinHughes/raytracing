#include "ray.h"
#include "sphere.h"
#include "sphere2.h"
#include "rsphere.h"
#include "plane.h"
#include "mplane.h"
#include "checkered_plane.h"
#include "spheresceene.h"
#include "vector3.h"
#include "fixedsceene.h"
#include "light.h"
#include "light_col.h"
#include "controler.h"

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
cout << "count : "<< count <<  endl; 
  int img_width = 2000;
  int img_height = 1000;

  float dz = 0.001;
  float dy = 0.001;

  Vector3 camera_start(0,-4,0);

  Vector3 cam_direction(1,0,0);

  image<rgb_pixel> image (img_width, img_height);


  /*
  FixedSceene sceene(10,1);

  //Sphere sphere(sphere_center, sphere_rad, LightCol(0,255,0));
  //sceene.addRenderable(&sphere);


  Sphere* s1 = new Sphere(Vector3(10,0,5), 1, LightCol(255,0,0));
  sceene.addRenderable(s1);


  Sphere* s2 = new Sphere(Vector3(12,0,-2), 0.5, LightCol(0,255,0));
  sceene.addRenderable(s2);

  Sphere* s3 = new Sphere(Vector3(20,0,2), 2, LightCol(0,0,200));
  sceene.addRenderable(s3);

  Sphere* s4 = new Sphere(Vector3(20,0,-5), 0.5, LightCol(200,200,00));
  sceene.addRenderable(s4);

  Sphere* s5 = new Sphere(Vector3(20,-3,-5), 0.5, LightCol(200,0,100));
  sceene.addRenderable(s5);

  Sphere* s6 = new Sphere(Vector3(15.5,-3,-2), 0.5, LightCol(200,0,100));
  sceene.addRenderable(s6);

  Light* light = new Light(Vector3(10,-10,0));

  Plane* p1 = new Plane(Vector3(0,-1,0), 0, LightCol(150,150,150));
  sceene.addRenderable(p1);

  sceene.addLight(light);
  */



  FixedSceene sceene(20, 4);

  
  //Light* light1 = new Light(Vector3(15,-10,-2), LightCol(0.2,0.9,0.1), 5);
  Light* light1 = new Light(Vector3(15,-10,-2),  5);
  sceene.addLight(light1);
  
  
  /*
  Light* light2 = new Light(Vector3(10,-5,20), LightCol(1,0,0.2), 0.5);
  sceene.addLight(light2);

  Light* light3 = new Light(Vector3(5,-7,-3), LightCol(0.1,1,0.2), 0.5);
  //Light* light3 = new Light(Vector3(0,-7,-3), 0.5);
  sceene.addLight(light3);
  */
 
  //Light* light4 = new Light(Vector3(0,-4,5), LightCol(0,0.1,0.9),6);
  Light* light4 = new Light(Vector3(0,-4,5), 6);
  sceene.addLight(light4);

  
  Plane* p1 = new Plane(Vector3(0,-1,0), 0, LightCol(0.59,0.59,0.59));
  p1->shade_pixel_col = LightCol(0.27,0.270,0.270);
  sceene.addRenderable(p1);
  

  Plane* p2 = new Plane(Vector3(-1,0,0), -20, LightCol(0.8,0.8,0.8));
  //p2->shade_pixel_col = LightCol(1,0,0);
  sceene.addRenderable(p2);

  Sphere* s1 = new Sphere2(Vector3(10,-1,0),0.5, LightCol(0.78,0,0), true, true);
  //s1->shade_pixel_col = LightCol(0.39,0,0);
  sceene.addRenderable(s1);

  Sphere* s1_1 = new Sphere2(Vector3(10,-2,-2),1, LightCol(0.9,0.9,0.05), true, true);
  //s1_1->shade_pixel_col = LightCol(0.39,0,0);
  sceene.addRenderable(s1_1);

  Sphere* s2 = new Sphere2(Vector3(15,-1,5),0.5, LightCol(0.78,0,0));
  s2->shade_pixel_col = LightCol(0.39,0,0);
  sceene.addRenderable(s2);

  Sphere* s3 = new Sphere2(Vector3(15,-1,-5),0.5, LightCol(0.78,0,0), false, false);
  s3->shade_pixel_col = LightCol(0.39,0,0);
  sceene.addRenderable(s3);

  Sphere* s4 = new Sphere2(Vector3(25,-1,0),0.5, LightCol(0.78,0,0));
  s4->shade_pixel_col = LightCol(0.39,0,0);
  sceene.addRenderable(s4);

  Sphere* s5 = new Sphere2(Vector3(15,-3,0),0.5, LightCol(0.78,0,0.78));
  s5->shade_pixel_col = LightCol(9.39,0,0.39);
  sceene.addRenderable(s5);

  Sphere* s6 = new Sphere2(Vector3(15,1,0),3, LightCol(0.39,0.78,0.78));
  s6->shade_pixel_col = LightCol(0.2,0.39,0.39);
  sceene.addRenderable(s6);

  Sphere* s7 = new Sphere2(Vector3(20,1,8),3, LightCol(0.39,0.78,0.78));
  s7->shade_pixel_col = LightCol(0.2,0.39,0.39);
  sceene.addRenderable(s7);

  Sphere* s8 = new Sphere2(Vector3(15,-4,-3),0.2, LightCol(0.78,0,0.78));
  s8->shade_pixel_col = LightCol(0.2,0,0.39);
  sceene.addRenderable(s8);

  Sphere* s9 = new Sphere2(Vector3(15,-10,-5),2, LightCol(0,0.78,0.39), true, true);
  s9->shade_pixel_col = LightCol(0,0.39,0.2);
  sceene.addRenderable(s9);

  Sphere* s10 = new RSphere(Vector3(10,1,4),3, LightCol(1,0.4,0.5));
  sceene.addRenderable(s10);

  Sphere* s11 = new RSphere(Vector3(10,-2,-6),3, LightCol(0.1,0.8,0.7));
  sceene.addRenderable(s11);

  Plane* p3 = new Plane(Vector3(0,0,1), -8, LightCol(0.78,0.78,0.58));
  p3->shade_pixel_col = LightCol(0.2,0.2,0.29);
  sceene.addRenderable(p3);


  /*

  FixedSceene sceene(5);
  Sphere* ts1 = new Sphere(Vector3(10,0,5), 1, LightCol(255,0,0));
  sceene.addRenderable(ts1);

  Plane* tp1 = new Plane(Vector3(0,1,0), 0, LightCol(150,150,150));
  sceene.addRenderable(tp1);

  Light* test_light = new Light(Vector3(10,-10,-10));
  sceene.setLight(test_light);

  Sphere* loc = new Sphere(Vector3(10,-1,3.5), 0.1, LightCol(255,0,0));
  sceene.addRenderable(loc);



  Intersection* test_inter = new Intersection(tp1, Vector3(10,0,3.5));

  cout << test_light->toString() << endl;

  cout << "starting intersection " << test_inter->toString() << endl;

  cout << "is in shade? " << sceene.isInShade(test_inter) << endl;

  delete test_inter;
  */

  std::cout << sceene.toString() << endl;

  Vector3 cam_pos = camera_start;

  LightCol** raw_colours = new LightCol*[img_width];

  Controler controler(sceene);
  controler.setCamPos(cam_pos);
  controler.setCamDirec(cam_direction);
  //controler.setSceene(&sceene);
  //
          //render(LightCol** raw_colours, int width, int height, float dy, float dz, int max_bounce, int rays_per_pixel, int difuse_rays) {

  controler.render(
      raw_colours,  /*LightCol** raw_colours */
      img_width, /* int width  */
      img_height, /* int height  */
      dy, /* float dy  */
      dz,/* float dz  */
      1,/* int max_bounce  */
      16,/* int rayx_per_pixel  */
      16);/* int difuse_rays  */


  //float max_brightness = -1000000.0;
  cout << "starting colour scaling" << endl;
  
  /*
  for(int i = 0; i < img_width; i++) {
    for(int j = 0; j < img_height; j++){
      if(raw_colours[i][j].red > max_brightness) {
        max_brightness = raw_colours[j][i].red;
      } 
      if(raw_colours[i][j].green > max_brightness) {
        max_brightness = raw_colours[j][i].green;
      } 
      if(raw_colours[i][j].blue > max_brightness) {
        max_brightness = raw_colours[j][i].blue;
      }

    }
  }
  */

  float max_brightness = 0;

  Light** lights = sceene.getLights();
  for(int i = 0; i< sceene.curr_num_lights; i++) {
    cout << lights[i]->brightness << endl;
    max_brightness += lights[i]->brightness;
  }


  cout << "max brightness is: " << max_brightness << endl;

  if(max_brightness > 1 ) {
    max_brightness = 1 / max_brightness;
  }


  for(int i = 0; i < img_width; i++) {
    for(int j = 0; j < img_height; j++){

      LightCol lc = raw_colours[i][j].scale(max_brightness * 255);
      //LightCol lc = raw_colours[i][j].scale(255);
      image[j][i] = rgb_pixel(lc.red, lc.green, lc.blue);
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
