# Raytracing

This is a software based ray tracing engine written in cpp. It depends on xlib, and libpng. 

## Compiling 

It can be compiled on linux using `make entry`

## Usage
Running `./entry` will run the program rendering the curren scene that is hard coded into image_tracing.cpp. 
Supplying `-nw` will stop the program writing the image to file, `-p` will show a preview before rendering and
`-s` will show the full version of the image once it has been completed.

## How it works. 
This is a fairly simple implementation of the ray tracing algorithm. Rays are emitted from a camera point in a grid pattern, 
the intersection of these rays are then calculated with the objects in the scene. The closest intersection is then used to shade that pixel. 

## Current Features 

There are classes to represent intersections, renderable objects, lights, scenes, materials and geometries. 
Current geometries include spheres and plains, current materials include mat, phong, mirrors and metallic. 
These can be combined to get a wide variety of visually distinct object. Shadows and multiple lights are supported by the scene. 

## Work in progress (and thing I'd like to add)

* Add triangle geometry
* Add mesh geometry
* Add model loading
* Fix multi threading
* Add additional shaders for transparent materials
* Add support for lights that aren't points
