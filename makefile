CXX = g++

entry : entry.o console_tracing.o image_tracing.o ray.o sphere.o spheresceene.o plane.o light.o fixedsceene.o renderable.o intersection.o sphere2.o rsphere.o mplane.o checkered_plane.o controler.o
	$(CXX) -o entry entry.o ray.o sphere.o spheresceene.o plane.o light.o fixedsceene.o renderable.o intersection.o sphere2.o rsphere.o mplane.o checkered_plane.o controler.o `libpng-config --ldflags`

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

fixedsceene2.o : fixedsceene2.cpp fixedsceene2.h
	$(CXX) -c fixedsceene2.cpp

light.o : light.cpp light.h
	$(CXX) -c light.cpp

ray.o : ray.cpp ray.h
	$(CXX) -c ray.cpp

sphere.o : sphere.cpp sphere.h
	$(CXX) -c sphere.cpp

rsphere.o : rsphere.cpp rsphere.h
	$(CXX) -c rsphere.cpp

sphere2.o : sphere2.cpp sphere2.h
	$(CXX) -c sphere2.cpp

plane.o : plane.cpp plane.h
	$(CXX) -c plane.cpp

mplane.o : mplane.cpp mplane.h
	$(CXX) -c mplane.cpp

checkered_plane.o : checkered_plane.cpp checkered_plane.h
	$(CXX) -c checkered_plane.cpp

spheresceene.o : spheresceene.cpp spheresceene.h 
	$(CXX) -c spheresceene.cpp

intersection.o : intersection.cpp intersection.h 
	$(CXX) -c intersection.cpp

controler.o : controler.cpp controler.h
	$(CXX) -c controler.cpp
