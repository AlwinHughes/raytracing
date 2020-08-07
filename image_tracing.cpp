#include "ray.h"
#include "intersectable.h"
#include "material.h"
#include "vector3.h"
#include "fixedsceene.h"
#include "light.h"
#include "light_col.h"
#include "controler.h"
#include "spheregeom.h"
#include "planegeom.h"
#include "flatmat.h"
#include "basicshade.h"
#include "fullshade.h"
#include "difusemat.h"
#include "mirror.h"
#include "checkeredmat.h"
#include "shinymat.h"
#include "metalicmat.h"
#include "previewer.h"

#include <math.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace png;
using namespace std;

void imageTracing(bool write, bool preview, bool show) {

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

  //Vector3 camera_start(0,-4,0);
  Vector3 camera_start(0,-1,0);

  Vector3 cam_direction(1,0,0);

  image<rgb_pixel> image (img_width, img_height);

  /*

  FixedSceene sceene(10,3);

  //Sphere sphere(sphere_center, sphere_rad, LightCol(0,255,0));
  //sceene.addRenderable(&sphere);


  SphereGeom s1_g = SphereGeom(Vector3(10,0,5), 1);
  FullShade s1_m = FullShade(LightCol(1,0,0));
  Renderable s1 = Renderable(&s1_g, &s1_m);
  sceene.addRenderable(s1);


  SphereGeom s2_g = SphereGeom(Vector3(12,0,-2), 0.5);
  FullShade s2_m = FullShade(LightCol(0,1,0));
  Renderable s2 = Renderable(&s2_g, &s2_m);
  sceene.addRenderable(s2);

  SphereGeom s3_g = SphereGeom(Vector3(20,0,2), 2);
  FullShade s3_m = FullShade(LightCol(0,0,0.8));
  Renderable s3 = Renderable(&s3_g, &s3_m);
  sceene.addRenderable(s3);

  SphereGeom s4_g = SphereGeom(Vector3(20,0,-5), 0.5);
  FullShade s4_m = FullShade(LightCol(0.8,0.8,0));
  Renderable s4 = Renderable(&s4_g, &s4_m);
  sceene.addRenderable(s4);

  SphereGeom s5_g = SphereGeom(Vector3(20,-3,-5), 0.5);
  FullShade s5_m = FullShade(LightCol(0.8,0,0.4));
  Renderable s5 = Renderable(&s5_g, &s5_m);
  sceene.addRenderable(s5);

  SphereGeom s6_g = SphereGeom(Vector3(15.5,-3,-2), 0.5);
  Renderable s6 = Renderable(&s6_g, &s5_m);
  sceene.addRenderable(s6);


  PlaneGeom p_g = PlaneGeom(Vector3(0,-1,0), 0);
  FullShade p_m = FullShade(LightCol(0.6,0.6,0.6));
  Renderable p1 = Renderable(&p_g, &p_m);
  sceene.addRenderable(p1);


  Light light1 = Light(Vector3(10,-10,4));

  Light light2 = Light(Vector3(3,-10,-10));

  sceene.addLight(light1);
  sceene.addLight(light2);
  */


  /*
  FixedSceene sceene(20, 4);

  //Light* light1 = new Light(Vector3(15,-10,-2), LightCol(0.2,0.9,0.1), 2);
  Light light1 = Light(Vector3(15,-10,-2), 2);
  sceene.addLight(light1);

  //Light light2 = Light(Vector3(10,-5,20), LightCol(1,0,0.2), 0.5);
  Light light2 = Light(Vector3(10,-5,20),2);
  sceene.addLight(light2);

  Light light3 = Light(Vector3(10,5,0), LightCol(0,0,1), 2);
  sceene.addLight(light3);
  */

  /*
  Light* light3 = new Light(Vector3(5,-7,-3), LightCol(0.1,1,0.2), 0.5);
  //Light* light3 = new Light(Vector3(0,-7,-3), 0.5);
  sceene.addLight(light3);

  //Light* light4 = new Light(Vector3(0,-4,5), LightCol(0,0.1,0.9),6);
  Light* light4 = new Light(Vector3(0,-4,5), 6);
  sceene.addLight(light4);
  */

  /*
  PlaneGeom p1_g = PlaneGeom(Vector3(0,-1,0), 0);
  FullShade p1_m = FullShade(LightCol(0.59,0.59,0.59));
  Renderable p1 = Renderable(&p1_g, &p1_m);
  sceene.addRenderable(p1);
  */

  /*
  PlaneGeom p2_g = PlaneGeom(Vector3(-1,0,0), -20);
  FullShade p2_m = FullShade(LightCol(0.8,0.8,0.8));
  Renderable p2(&p2_g, &p2_m);
  sceene.addRenderable(p2);

  SphereGeom s1_g = SphereGeom(Vector3(10,-1,0),0.5);
  FullShade s1_m = FullShade(LightCol(0.78,0,0));
  Renderable s1(&s1_g, &s1_m);
  sceene.addRenderable(s1);

  SphereGeom s1_1_g(Vector3(10,-2,-2),1);
  FullShade s1_1_m(LightCol(0.9,0.9,0.05), 2);
  Renderable s1_1 = Renderable(&s1_1_g, &s1_1_m);
  sceene.addRenderable(s1_1);

  SphereGeom s2_g = SphereGeom(Vector3(15,-1,5),0.5);
  FullShade s2_m(LightCol(0.78,0,0), 2);
  Renderable s2(&s2_g, &s2_m);
  sceene.addRenderable(s2);

  SphereGeom s3_g = SphereGeom(Vector3(15,-1,-5),0.5);
  FullShade s3_m(LightCol(0.78,0,0));
  Renderable s3(&s3_g, &s3_m);
  sceene.addRenderable(s3);

  SphereGeom s4_g(Vector3(25,-1,0),0.5);
  FullShade s4_m(LightCol(0.78,0,0), 2);
  Renderable s4(&s4_g, &s4_m);
  sceene.addRenderable(s4);

  SphereGeom s5_g(Vector3(15,-3,0),0.5);
  FullShade s5_m(LightCol(0.78,0,0.78), 0.2);
  Renderable s5 = Renderable(&s5_g, &s5_m);
  sceene.addRenderable(s5);

  SphereGeom s6_g(Vector3(15,1,0),3);
  FullShade s6_m(LightCol(0.39,0.78,0.78),0.5);
  Renderable s6(&s6_g, &s6_m);
  sceene.addRenderable(s6);

  SphereGeom s7_g(Vector3(20,1,8),3);
  FullShade s7_m(LightCol(0.39,0.78,0.78), 0.2);
  Renderable s7(&s7_g, &s7_m);
  sceene.addRenderable(s7);

  SphereGeom s8_g(Vector3(15,-4,-3),0.2);
  FullShade s8_m(LightCol(0.78,0,0.78));
  Renderable s8(&s8_g, &s8_m);
  sceene.addRenderable(s8);

  SphereGeom s9_g(Vector3(15,-10,-5),2);
  FullShade s9_m(LightCol(0,0.78,0.39),2);
  Renderable s9(&s9_g, &s9_m);
  sceene.addRenderable(s9);

  SphereGeom s10_g(Vector3(10,1,4),3);
  FullShade s10_m(LightCol(1,0.4,0.5));
  Renderable s10(&s10_g, &s10_m);
  sceene.addRenderable(s10);

  SphereGeom s11_g(Vector3(10,-2,-6),3);
  FullShade s11_m(LightCol(0.1,0.8,0.7));
  Renderable s11(&s11_g, &s11_m);
  sceene.addRenderable(s11);

  PlaneGeom p3_g(Vector3(0,0,1), -8);
  FullShade p3_m(LightCol(0.78,0.78,0.58));
  Renderable p3(&p3_g, &p3_m);
  sceene.addRenderable(p3);

 */ 

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

   //cout << "RAND MAX " << RAND_MAX << endl;
 

  FixedSceene sceene(6,2);

  int max_bounce = 6;
  int difuse_rays = 1;

  ShinyMat flat_mat(LightCol(1,0,0), 10, max_bounce, difuse_rays, 40);
  SphereGeom s_geom_1 = SphereGeom(Vector3(5,-0.8,2), 1);
  Renderable r1(&s_geom_1, &flat_mat);
  sceene.addRenderable(r1);

  ShinyMat flat_mat_2(LightCol(0,1,0), 10, max_bounce, difuse_rays, 20);
  SphereGeom s_geom_2 = SphereGeom(Vector3(8,-2,2), 3);
  Renderable r2(&s_geom_2, &flat_mat_2);
  sceene.addRenderable(r2);

  //DifuseMat flat_mat_white = DifuseMat(LightCol(1,1,1), 1, max_bounce, difuse_rays);
  CheckeredMat checkered_mat = CheckeredMat(LightCol(1,1,1), 1, max_bounce, difuse_rays);
  PlaneGeom p_geom = PlaneGeom(Vector3(0,-1,0),0);
  Renderable r3(&p_geom, &checkered_mat );
  sceene.addRenderable(r3);

  /*
  DifuseMat flat_mat_white2 = DifuseMat(LightCol(1,1,1), 1, max_bounce, difuse_rays);
  PlaneGeom p_geom2 = PlaneGeom(Vector3(0,0,-1),-5);
  Renderable r4(&p_geom2, &flat_mat_white2);
  sceene.addRenderable(r4);
  */

  //MirrorMat mirror_mat = MirrorMat(LightCol(0.5,1,0.3));
  MetalicMat mirror_mat(LightCol(0.5,0.5,0.5), 0.05, 20);
  SphereGeom s_geom_3(Vector3(10,-3,-5),3.5);
  Renderable r5(&s_geom_3, &mirror_mat);
  sceene.addRenderable(r5);

  
  Light light(Vector3(3, -4, -3));
  sceene.addLight(light);
  
  Light light3(Vector3(3, -2, 5), LightCol(1,0.2,0.2));
  sceene.addLight(light3);

  /*
  Light light2(Vector3(10, -16, 3), 2);
  sceene.addLight(light2);
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

  
  //controler.render(
  //   raw_colours,  /*LightCol** raw_colours */
  //  img_width, /* int width  */
  //    img_height, /* int height  */
  //    dy, /* float dy  */
  //    dz,/* float dz  */
  //    1/* int rayx_per_pixel  */
  //    );

  if(preview) {

    LightCol** raw_colours = new LightCol*[img_width/2];
    controler.preview(raw_colours, img_width/2, img_height/2, dz * 2, dy * 2);

    Previewer::get().view(raw_colours, img_height/2, img_width/2);
    cout << "Do you want to do the full render? [Y/n]" << endl;

    string input;
    cin >> input;
    if(input == "n") {
      cout << "Canceling" << endl;
      return;
    }
  }

  cout << "Starting full render" << endl;

  controler.start(
      1, // # threads /
      raw_colours,  // LightCol** raw_colours /
      img_width, // int width  /
      img_height, // int height  /
      dy, // float dy  /
      dz,// float dz  /
     1// int rayx_per_pixel  /
      );


  /*
  controler.render(
      raw_colours,  // LightCol** raw_colours /
      img_width, // int width  /
      img_height, // int height  /
      dy, // float dy  /
      dz,// float dz  /
      4// int rayx_per_pixel  /
      );
      */


  float max_brightness = 0;
  cout << "starting colour scaling" << endl;
  
  for(int i = 0; i < img_width; i++) {
    for(int j = 0; j < img_height; j++){
      if(raw_colours[i][j].red > max_brightness) {
        max_brightness = raw_colours[i][j].red;
      } 
      if(raw_colours[i][j].green > max_brightness) {
        max_brightness = raw_colours[i][j].green;
      } 
      if(raw_colours[i][j].blue > max_brightness) {
        max_brightness = raw_colours[i][j].blue;
      }

    }
  }




  /*
  float max_brightness = 0;

  Light* lights = sceene.getLights();
  for(int i = 0; i< sceene.curr_num_lights; i++) {
    cout << lights[i].brightness << endl;
    max_brightness += lights[i].brightness;
  }

  */

  cout << "max brightness is: " << max_brightness << endl;

  
  if(max_brightness == 0) {
    max_brightness = 1;
  } else if(max_brightness > 1 ) {
    max_brightness = 1 / max_brightness;
  }
  

  if(show) {
    Previewer::get().view(raw_colours, img_height, img_width, max_brightness);

    if(write) {
      cout << "Do you want to write the image? [Y/n]" << endl;
      string input;
      cin >> input;
      if(input == "n") {
        return;
      }
    }
  }

  

  for(int i = 0; i < img_width; i++) {
   for(int j = 0; j < img_height; j++){
      //LightCol lc = raw_colours[i][j].scale(max_brightness * 255);
      LightCol lc = raw_colours[i][j].scale(max_brightness);
      //LightCol lc = raw_colours[i][j].scale(255);
      image[j][i] = rgb_pixel(sqrt(lc.red) *255, sqrt(lc.green)*255, sqrt(lc.blue)*255);
    }
  }


  if(write){

    image.write("./images/image" + count + ".png");

    ofstream ofile;
    ofile.open("count", ofstream::trunc);
    ofile << count;
    ofile.close();

    cout << "./images/image" << count << ".png" << endl;
  }

  cout << "Created " << Ray::num << " Rays" << endl;
  cout << "Created " << Intersection::num << " Intersections " << endl;

};
