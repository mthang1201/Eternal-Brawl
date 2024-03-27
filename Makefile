SDL2 = -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
SOURCES = \
    # GameCore
    src/main.cpp \
    src/game.cpp \
    src/renderWindow.cpp \
    src/inputHandler.cpp \
    # GameObject
    src/GameObject/entity.cpp \
    src/GameObject/player.cpp \
    src/GameObject/item.cpp \
    # Utils
    src/vector2f.cpp \
    src/loaderParams.cpp \      
    src/loaderAssets.cpp

all:
	g++ $(SDL2) $(SOURCES) -o bin/Game.exe

g++ src/*.cpp src/GameObject/*.cpp -Iinclude -Iinclude/SDL2 -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o bin/Game.exe