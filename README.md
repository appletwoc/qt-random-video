# Reelz Simulator
A Qt5 program desiged to simulate Instagram Reels. A video plays on loop until the Next button is hit. Once
Next is hit, a new random video is selected.

## Prerequisites
### For Linux
Install Qt5 and Qt5 development files using the package manager. On Fedora, this is 
```
dnf install qt5-qtbase.x86_64
dnf install qt5-qtbase-devel.x86_64
dnf install qt5-qtmultimedia.x86_64
dnf install qt5-qtmultimedia-devel.x86_64
```
### For macOS
Make sure you have Qt5 installed. And locate the Qt5 files. Install Qt5 with `brew`
```
brew install qt5
```
And make sure you know the path of installation. For example, one path can look like
```
/opt/homebrew/opt/qt@5/lib/cmake/Qt5
```
But it could be different on your system.

### For Windows
For building in Windows, you will need
1. CMake and Git
2. Qt Creator and Qt 5.12.x from [here](https://www.qt.io/offline-installers). Install the minGW 64 bit versions.
3. The installer in the **Download** section in this [link](http://forum.doom9.org/showthread.php?t=156191).
When running the installer, keep hitting next. The default settings should be fine

## Building and Running

### Windows
Follow these steps withn Qt Creator
1. Go to File &#8594; New File or Project...
2. On the left panel under Import Project select Git Clone
3. In the Repository field, input
```
https://github.com/appletwoc/reelz-simulator.git
```
and click Finish
4. Set up a kit. In the kit select:
  - Device Type: Desktop
  - C++ Compiler: MinGW 64 bit
  - CMake tool	
5. Then click Configure the Project
6. Bottom left hit the play button to build the project

### Linux and macOS
Run the command
```
https://github.com/appletwoc/reelz-simulator.git
```
to clone the repository into the current directory. Run `cd reelz-simulator` to move into the
project directory.

Create a build directory `mkdir build` and `cd build`. Then, run
```
cmake -DCMAKE_PREFIX_PATH=/path/to/qt5 ..
make
```
The `DCMAKE_PREFIX_PATH` should be the path where Qt5 is installed.<br>
A program `Reelze Simulator` is in the directory. Run it with
```
./Reelz\ Simulator
```
If you have more than one video the Randomize button will pick another video at random.

# Choosing Videos
Click the Open... button and select one or more videos to play.
