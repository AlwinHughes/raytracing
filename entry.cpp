#include "image_tracing.cpp"
#include <png++/png.hpp>

int main(int argc, char** argv) {

  bool write = true;
  bool preview = false;
  bool show = false;

  if(argc > 1) {
    for(int i = 1; i < argc; i++) {
      if(strcmp(argv[i],"-nw") == 0) {
        write = false;
        cout << "no write" << endl;
      } else if (strcmp(argv[i],"-p") == 0) { 
        preview = true;
        cout << "preview" << endl;
      } else if (strcmp(argv[i], "-s") == 0) {
        show = true;
        cout << "preview" << endl;
      }
    }
    imageTracing(write, preview, show);
  }
}
