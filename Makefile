SDL2_LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
all:
	g++ -Iinclude -Llib -o main src/*.cpp $(SDL2_LIBS)