# Game
A game written from scratch in C++ using the SDL2 development library. Apart from the core gameplay, the project also includes some extra features like a ghost block to reduce misdrops, a simple main menu, and support for multiple resolutions. All sprites were created by me.

<!-- ![](gallery/gameplay.gif) -->

<!-- ## Gallery
<img src="gallery/mainmenu.png" width = "310"> <img src="gallery/options.png" width = "310"> <img src="gallery/pausemenu.png" width = "310"> -->

## Installation
If you just want to try the game on your Windows machine, go the [Releases](https://github.com/mthang1201/Game/releases) page and get the latest executable.
- You may need the [Microsoft Visual C++ Redistributables](https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0) if you don't have them already installed.

## Build Instructions
This is the first project where I use CMake to support multiple compilers, so to compile the game yourself you will need [CMake](https://cmake.org/overview/).
- First of all, clone the repository to your PC.
- Open a terminal window in the root directory of the cloned repository and run this powershell script:
```
./run
```
You will then find the Game executable in bin.

## Controls
- Pending...

## Features to add
- Pending...

## Third party tools
- [SDL2 framework](https://www.libsdl.org/) to handle all the low-level stuff
- [SDL_image 2.0](https://www.libsdl.org/projects/SDL_image/) for loading images
- [SDL_ttf 2.0](https://www.libsdl.org/projects/SDL_ttf/) for rendering fonts
- [SDL_mixer 2.0](https://www.libsdl.org/projects/SDL_mixer/) for loading sounds

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
