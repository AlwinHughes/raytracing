CXX = g++

entry : entry.o image_tracing.o ray.o  light.o fixedsceene.o renderable.o intersection.o  controler.o spheregeom.o planegeom.o basicshade.o fullshade.o difusemat.o
	$(CXX) -o entry entry.o ray.o light.o fixedsceene.o renderable.o intersection.o controler.o spheregeom.o planegeom.o basicshade.o fullshade.o difusemat.o `libpng-config --ldflags` -pthread

entry.o : entry.cpp image_tracing.o 
	$(CXX) -c entry.cpp `libpng-config --cflags` -pthread

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

intersection.o : intersection.cpp intersection.h 
	$(CXX) -c intersection.cpp

controler.o : controler.cpp controler.h
	$(CXX) -c controler.cpp -pthread

spheregeom.o : spheregeom.cpp spheregeom.h
	$(CXX) -c spheregeom.cpp

planegeom.o : planegeom.cpp planegeom.h
	$(CXX) -c planegeom.cpp

basicshade.o :  basicshade.cpp basicshade.h
	$(CXX) -c basicshade.cpp

fullshade.o :  fullshade.cpp fullshade.h
	$(CXX) -c fullshade.cpp

difusemat.o :  difusemat.cpp difusemat.h
	$(CXX) -c difusemat.cpp
