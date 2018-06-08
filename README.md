# fractals
A program that generates the various fractals using mouse position as parameter in complex plane

This is a project of the graphics branch of 42, coded in C.

## Features
* Dynamically displays complex fractols based on mouse hovering position as parameter
* Multiple preset color schemes & full rgb color adjustment with keyboard input
* Zoom (almost infinitly) with mousewheel, centereed at the mouse position
* Adjustment of number of iterations to compute and escape redius
* Hide and diaplay info on screen

## Compiling and running
Run `make`. An executable will compile. Currently only tested on OS X.

Run with `./fractol "Name of Fractal"`.
Supported fractals (all Julia sets changes with parameter c being the current mouse posision):
1. Julia set of <img src="https://latex.codecogs.com/gif.latex?f%28z%29%20%3D%20z%5E2%20&plus;%20c"/>

2. Mandelbrot set <img src="https://latex.codecogs.com/gif.latex?%5C%7B%20%5C%20c%20%5Cin%20%5Cmathbb%7BC%7D%20%5C%20%7C%20%5Clim_%7Bn%20%5Crightarrow%20%5Cinfty%7D%20%7Cf%5En%280%29%7C%20%3C%202%20%5C%7D"/> where <img src="https://latex.codecogs.com/gif.latex?f%28z%29%20%3D%20z%5E2%20&plus;%20c"/>

3. Julia set of <img src="https://latex.codecogs.com/gif.latex?f%28z%29%20%3D%20z%5E2%20-%20%5Cfrac%7Bc%7D%7Bz%7D"/> (known to be topologically a Sirpinski's carpet with appropoate parameter)

4. Julia set of <img src="https://latex.codecogs.com/gif.latex?f%28z%29%20%3D%20z%5E2%20-%20%5Cfrac%7Bc%7D%7Bz%5E2%7D"/> (resembles the Poincare metric when |c| is close to 1)

5. Julia set of <img src="https://latex.codecogs.com/gif.latex?f%28z%29%20%3D%20z%5E3%20-%20c"/>

6. Standard square julia set where we also cut-off when iterates of points gets close to 0. (hence forming different shaded dots inside the connected components of the filled Julis set)

![alt text](https://github.com/conanwu777/fractals/blob/master/1.png)
![alt text](https://github.com/conanwu777/fractals/blob/master/2.png)
![alt text](https://github.com/conanwu777/fractals/blob/master/3.png)
![alt text](https://github.com/conanwu777/fractals/blob/master/4.png)
![alt text](https://github.com/conanwu777/fractals/blob/master/5.png)
![alt text](https://github.com/conanwu777/fractals/blob/master/6.png)
![alt text](https://github.com/conanwu777/fractals/blob/master/7.png)
![alt text](https://github.com/conanwu777/fractals/blob/master/8.png)
