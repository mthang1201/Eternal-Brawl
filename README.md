# Game
A game written from scratch in C++ using the SDL2 development library. Apart from the core gameplay, the project also includes some extra features like a ghost block to reduce misdrops, a simple main menu, and support for multiple resolutions. All sprites were created by me.

<!-- ![](gallery/gameplay.gif) -->

<!-- ## Gallery
<img src="gallery/mainmenu.png" width = "310"> <img src="gallery/options.png" width = "310"> <img src="gallery/pausemenu.png" width = "310"> -->

## Installation
If you just want to try the game on your PC, go the [Releases](https://github.com/mthang1201/Game/releases) page and get the latest executable.
- You may need the [Microsoft Visual C++ Redistributables](https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0) if you don't have them already installed.

## Build Instructions
This is the first C++ SDL2 project where I use CMake to support multiple compilers, so to compile the game yourself you will need [CMake](https://cmake.org/download/) and [MinGW](https://www.mingw-w64.org/downloads/).
- First of all, clone the repository to your Windows machine.
```
git clone https://github.com/mthang1201/Game.git
```
Alternatively, you can install the zip file and extract it to a desired location.
- Secondly, install CMake and MinGW. Remember to install them using the installer, or you may need to add the environment variables manually.
- Open a terminal window in the root directory of the cloned repository and run this Powershell script:
```
./run
```
You will then find the Game executable in the bin directory.

NOTE: If the instruction above did not work, you may need to build manually from the source:
- Open Powershell, and change the directory to the cloned repository.
- Then, execute these commands:
```
cd build
rm * -rf
```
Confirm the deletion of all files and folder in the build directory.
```
cmake -G
```
This will display several generators such as Unix Makefiles, MinGW Makefiles, Ninja and etc. Choose the one you prefer. However, for this instruction, I will stick to MinGW:
```
cmake -G "MinGW Makefiles" ..
cmake --build .
```
And, voila, you have successfully built the source. Check the Game executable in the bin directory.

## Controls
- Pending...

## Features to add
- Pending...

## Third party tools
- [SDL 2.30.0](https://github.com/libsdl-org/SDL/releases/tag/release-2.30.0) to handle all the low-level stuff
- [SDL_image 2.8.2](https://github.com/libsdl-org/SDL_image/releases/tag/release-2.8.2) for loading images
- [SDL_ttf 2.22.0](https://github.com/libsdl-org/SDL_ttf/releases/tag/release-2.22.0) for rendering fonts
- [SDL_mixer 2.8.0](https://github.com/libsdl-org/SDL_mixer/releases/tag/release-2.8.0) for loading sounds

## Acknowledgements
[Lazy Foo's SDL tutorials](https://lazyfoo.net/tutorials/SDL/index.php) have been extremely helpful, look into them if you are interested in low-level game programming or just want a framework to handle basic graphics for your C/C++ programs.

[File structure and README.md layout example](https://github.com/mvlassis/pixeltetris)

[An Introduction to Modern CMake](https://www.willusher.io/sdl2%20tutorials/2014/03/06/lesson-0-cmake) is great for learning the basics of CMake and avoiding bad practices.

[Codergopher's tutorial](https://www.youtube.com/playlist?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS) was my initial inspiration for starting this project.

[SDL Game Development](https://books.google.com.vn/books/about/SDL_Game_Development.html?id=SbmfrHIlhK4C&source=kp_book_description&redir_esc=y) by Shaun Mitchell, 2013.

## License
- Still working on...
<!-- - The source code is licensed under the [MIT License](https://tldrlegal.com/license/mit-license).
- The Munro fonts are licensed under the [SIL Open Font License](http://scripts.sil.org/OFL). -->
