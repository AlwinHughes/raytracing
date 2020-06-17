#include "console_tracing.cpp"
#include "image_tracing.cpp"
#include <png++/png.hpp>

int main(int argc, char** argv) {

  if(argc > 1) {
    imageTracing(strcmp(argv[1],"-nw"));
  } else {
    imageTracing();
  }
  
}
