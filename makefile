CXX = g++

entry : entry.o  console_tracing.o ray.o sphere.o spheresceene.o plane.o
	$(CXX) -o entry entry.o ray.o sphere.o spheresceene.o plane.o `libpng-config --ldflags`

entry.o : entry.cpp 
	$(CXX) -c entry.cpp `libpng-config --cflags`


console_tracing.o : console_tracing.cpp
#	$(CXX) -c console_tracing.cpp `libpng-config --cflags`

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

