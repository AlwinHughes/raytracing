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
  FixedSceene sceene(10);

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

  Light* light = new Light(Vector3(10,-10,-10));

  Plane* p1 = new Plane(Vector3(0,1,0), 0, LightCol(150,150,150));
  sceene.addRenderable(p1);

  sceene.setLight(light);
  */



  FixedSceene sceene(20);

  Light* light = new Light(Vector3(15,-5,0));
  sceene.setLight(light);

  Plane* p1 = new CPlane(Vector3(0,-1,0), 0, LightCol(0.59,0.59,0.59));
  p1->shade_pixel_col = LightCol(0.27,0.270,0.270);
  sceene.addRenderable(p1);

  Sphere* s1 = new Sphere2(Vector3(10,-1,0),0.5, LightCol(0.78,0,0), true, true);
  s1->shade_pixel_col = LightCol(0.39,0,0);
  sceene.addRenderable(s1);

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

  Plane* p2 = new Plane(Vector3(0,0,1), -8, LightCol(0.78,0.78,0.58));
  p2->shade_pixel_col = LightCol(0.2,0.2,0.29);
  sceene.addRenderable(p2);

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

  controler.render(raw_colours, img_width, img_height, 0.001, 0.001);



  float max_brightness = -1000000.0;
  

  /*
      if(raw_colours[i][j].red > max_brightness) {
        max_brightness = raw_colours[j][i].red;
      } else if(raw_colours[i][j].green > max_brightness) {
        max_brightness = raw_colours[j][i].green;
      } else if(raw_colours[i][j].blue > max_brightness) {
        max_brightness = raw_colours[j][i].blue;
      }
      */

  //cout << "max brightness is: " << max_brightness << endl;

  max_brightness = 1 / max_brightness;

  cout << "starting colour scaling" << endl;

  for(int i = 0; i < img_width; i++) {
    for(int j = 0; j < img_height; j++){

      //LightCol lc = raw_colours[i][j].scale(max_brightness * 255);
      LightCol lc = raw_colours[i][j].scale(255);


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
