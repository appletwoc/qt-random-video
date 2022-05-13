# Random Video
A Qt5 program that plays a video until a left click. Then, a new random video is selected.

## Prerequisites
Make sure you have qt5 installed. And locate the qt5 files. It should be the same as when we 
built the Duckstation program. (I do not remember the exact path)

## Building and Running
Create a build directory `mkdir build` and `cd build`. Then, run
```
cmake -DCMAKE_PREFIX_PATH=/path/to/qt5 ..
make
```
A program `main` is in the directory. Run it with
```
./main
```
