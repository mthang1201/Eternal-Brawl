## Allow script execution
`Set-ExecutionPolicy RemoteSigned`

# Install Git (Hope it is installed already)

## Clone the project
`cd C:\; mkdir code; cd code; git clone https://github.com/mthang1201/Game.git`

## ~~Install MSYS2~~
`pacman -S --needed base-devel git mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make`

## Install CMake
Run the installer.

## Install extensions for vscode
`code --install-extension "C:\code\Game\installEnvTools\ms-vscode.cpptools-extension-pack-1.3.0.vsix"`

## Set environment variables
```
setx Path "%Path%;C:\msys64\ucrt64\bin;C:\msys64\usr\bin;%USERPROFILE%\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\CMake\bin"
```
add /M for system environment variables

## Important Notice
ATTENTION: These instructions are tailored specifically for my school machine. Do not attempt to follow them. The proper instructions are provided in the README.md file located in the root folder of this project.
