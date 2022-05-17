# Random Video
A Qt5 program that plays a video until the Randomize button is hit. Once clicked, a new random video is selected.

## Prerequisites
Make sure you have Qt5 installed. And locate the Qt5 files. Install Qt5 with `brew`
```
brew install qt5
```
And make sure you know the path of installation. The path should look something like
```
/opt/homebrew/opt/qt@5/lib/cmake/Qt5
```
But it could be different on your system.

## Building and Running
Run the command
```
git clone https://github.com/appletwoc/qt-random-video.git
```
to clone the repository into the current directory. Run `cd qt-random-video` to move into the
project directory.

### Choosing Videos
Click the Open... button and select one or more videos to play.

--- 

Create a build directory `mkdir build` and `cd build`. Then, run
```
cmake -DCMAKE_PREFIX_PATH=/path/to/qt5 ..
make
```
The `DCMAKE_PREFIX_PATH` should be the path where Qt5 is installed.<br>
A program `main` is in the directory. Run it with
```
./main
```
If you have more than one video the Randomize button will pick another video at random.
