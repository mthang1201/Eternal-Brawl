## Clone the project
`cd C:\; mkdir code; cd code; git clone https://github.com/mthang1201/Game.git`

## Install MSYS2
pacman -S --needed base-devel git mingw-w64-ucrt-x86_64-toolchain

## Move SDL folder
Move-Item -Path "C:\code\Game\installEnvTools\SDL_mingw" -Destination "C:\code\SDL_mingw"

## Install extensions for vscode
code --install-extension "C:\code\Game\installEnvTools\ms-vscode.cpptools-extension-pack-1.3.0.vsix"

## Install vcpkg (Optional)
cd "C:\msys64\ucrt64\bin"
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
vcpkg install sdl2 sdl2_image sdl2_ttf sdl2_mixer

## Set environment variables
```
setx CMAKE_PREFIX_PATH "C:\code\SDL_mingw"
setx VCPKG_DEFAULT_BINARY_CACHE "C:\msys64\ucrt64\bin\vcpkg\archives"
setx VCPKG_DEFAULT_TRIPLET "x64-windows"
```

```
setx Path "%Path%;C:\msys64\ucrt64\bin"
setx Path "%Path%;C:\Users\Minh Thang Bui\AppData\Local\Programs\Microsoft VS Code\bin"
setx Path "%Path%;C:\code\SDL_mingw\SDL2-2.29.2\lib\x64"
setx Path "%Path%;C:\code\SDL_mingw\SDL2_image-2.8.2\lib\x64"
setx Path "%Path%;C:\Program Files\CMake\bin"
```
add /M for system environment variables

## Directory tree
```
C:/
│
├── msys2/
│   ├── ucrt64/
│   │   ├── bin/
│   │       ├── bin/
│   └── ...
├── code/
    ├── SDL_mingw/
    ├── Game/
```

## Important Notice
ATTENTION: These instructions are tailored specifically for my school machine. Do not attempt to follow them. The proper instructions are provided in the README.md file located in the root folder of this project.