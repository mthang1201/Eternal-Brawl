SDL2_LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# SOURCE = src/main.cpp
SOURCE = src/*.cpp

all:
	g++ -Iinclude -Llib -o bin/main $(SOURCE) $(SDL2_LIBS)