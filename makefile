CXX = g++

OPTIONS = -pthread -O3

entry : entry.o image_tracing.o ray.o  light.o fixedsceene.o renderable.o intersection.o  controler.o spheregeom.o planegeom.o basicshade.o fullshade.o difusemat.o mirror.o checkeredmat.o shinymat.o  metalicmat.o
	$(CXX) -o  entry entry.o ray.o light.o fixedsceene.o renderable.o intersection.o controler.o spheregeom.o planegeom.o basicshade.o fullshade.o difusemat.o mirror.o checkeredmat.o shinymat.o metalicmat.o $(OPTIONS) `libpng-config --ldflags` 

entry.o : entry.cpp image_tracing.o 
	$(CXX) -c $(OPTIONS) entry.cpp `libpng-config --cflags` 

image_tracing.o : image_tracing.cpp
	$(CXX) -c  image_tracing.cpp $(OPTIONS) `libpng-config --cflags`

renderable.o : renderable.cpp renderable.h
	$(CXX) -c renderable.cpp $(OPTIONS)

fixedsceene.o : fixedsceene.h fixedsceene.cpp
	$(CXX) -c fixedsceene.cpp $(OPTIONS)

light.o : light.cpp light.h
	$(CXX) -c light.cpp $(OPTIONS)

ray.o : ray.cpp ray.h
	$(CXX) -c ray.cpp $(OPTIONS)

intersection.o : intersection.cpp intersection.h 
	$(CXX) -c intersection.cpp $(OPTIONS)

controler.o : controler.cpp controler.h
	$(CXX) -c controler.cpp $(OPTIONS)

spheregeom.o : spheregeom.cpp spheregeom.h
	$(CXX) -c spheregeom.cpp $(OPTIONS)

planegeom.o : planegeom.cpp planegeom.h
	$(CXX) -c planegeom.cpp $(OPTIONS)

basicshade.o :  basicshade.cpp basicshade.h
	$(CXX) -c basicshade.cpp $(OPTIONS)

fullshade.o :  fullshade.cpp fullshade.h
	$(CXX) -c fullshade.cpp $(OPTIONS)

difusemat.o :  difusemat.cpp difusemat.h
	$(CXX) -c difusemat.cpp $(OPTIONS)

mirror.o :  mirror.cpp mirror.h
	$(CXX) -c mirror.cpp $(OPTIONS)

checkeredmat.o :  checkeredmat.cpp checkeredmat.h
	$(CXX) -c checkeredmat.cpp $(OPTIONS)

shinymat.o :  shinymat.cpp shinymat.h
	$(CXX) -c shinymat.cpp $(OPTIONS)

metalicmat.o :  metalicmat.cpp metalicmat.h
	$(CXX) -c metalicmat.cpp $(OPTIONS)
