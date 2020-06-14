CXX = g++

test : test.o ray.o sphere.o spheresceene.o plane.o
	$(CXX) -o test test.o ray.o sphere.o spheresceene.o plane.o `libpng-config --ldflags`

test.o : test.cpp
	$(CXX) -c test.cpp `libpng-config --cflags`

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

