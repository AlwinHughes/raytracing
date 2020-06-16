CXX = g++

entry : entry.o console_tracing.o image_tracing.o ray.o sphere.o spheresceene.o plane.o light.o fixedsceene.o renderable.o
	$(CXX) -o entry entry.o ray.o sphere.o spheresceene.o plane.o light.o fixedsceene.o renderable.o `libpng-config --ldflags`

entry.o : entry.cpp image_tracing.o console_tracing.o
	$(CXX) -c entry.cpp `libpng-config --cflags`


console_tracing.o : console_tracing.cpp
	$(CXX) -c console_tracing.cpp `libpng-config --cflags`


image_tracing.o : image_tracing.cpp
	$(CXX) -c image_tracing.cpp `libpng-config --cflags`

renderable.o : renderable.cpp renderable.h
	$(CXX) -c renderable.cpp

fixedsceene.o : fixedsceene.h fixedsceene.cpp
	$(CXX) -c fixedsceene.cpp

light.o : light.cpp light.h
	$(CXX) -c light.cpp

ray.o : ray.cpp ray.h
	$(CXX) -c ray.cpp

sphere.o : sphere.cpp sphere.h
	$(CXX) -c sphere.cpp

plane.o : plane.cpp plane.h
	$(CXX) -c plane.cpp

spheresceene.o : spheresceene.cpp spheresceene.h 
	$(CXX) -c spheresceene.cpp

intersection.o : intersection.cpp intersection.h 
	$(CXX) -c intersection.cpp

