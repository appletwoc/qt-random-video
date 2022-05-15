# Random Video
A Qt5 program that plays a video until a left click. Then, a new random video is selected.

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
*This is a temporary solution to get videos playing until I complete the file dialog*<br>
Open the `src` directory to find `main.cpp`. Open `main.cpp` in a text editor. In the file
there will be a section that you will modify to add the paths of videos. Delete **all** the paths
already there (Since those videos are only on my computer), and add your own paths. The path should be
of the form
```
"/home/dcruz/Videos/.../video.mp4",
```
Don't forget the comma after the path. Make sure to also set the variable `n_videos` 
appropriately to the number of videos added.

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
Maximize the window with the menu buttons, and if you have more than one video the
Randomize button should pick another video at random.
