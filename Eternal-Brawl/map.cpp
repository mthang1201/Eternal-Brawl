#include <SDL.h>
#include <vector>

#include "map.hpp"

std::vector<SDL_Rect> tiles =
{
	/*{ 80, 508, 100, 100 },
	{ 400, 350, 100, 80 }*/
	{82, 170, 24, 550},
	{106, 170, 93, 24},
	{106, 194, 73, 62},
	{106, 256, 314, 250},
	{106, 506, 68, 62},
	{106, 568, 50, 192},
	{156, 631, 264, 89 },
	{397, 506, 23, 49},

	{463, 230, 240, 4},
	{420, 510, 56, 4},

	{537, 459, 23, 108},
	{537, 459, 129, 22},
	{537, 643, 110, 77},

	// stair
	{647, 649, 9 , 71},
	{656, 655, 8 , 65},
	{664, 661, 8 , 59},
	{672, 668, 8 , 52},
	{680, 674, 3 , 46},
	{683, 677, 5 , 43},

	{666, 459, 128, 8},
	{688, 680, 432, 40},

	{794, 459, 46, 22},
	{840, 459, 128, 8},
	{968, 459, 152, 22},
	{1030, 374, 115, 25},
	{1048, 399, 72, 60},
	{1030, 481, 90, 148},
	{1048, 629, 72, 51},
	
	{1120, 374, 25, 346}
};

int worldMap[45][80];

void Map::init()
{
    for (int y = 0; y < 45; y++)
    {
        for (int x = 0; x < 80; x++)
        {
            worldMap[y][x] = 0;
        }
    }
}

void Map::print()
{
    for (int y = 0; y < 45; y++)
    {
        for (int x = 0; x < 80; x++)
        {
            if (worldMap[y][x] == 0)
            {
                std::cout << ".";
            }
            else if (worldMap[y][x] == 1)
            {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }
}

void Map::modify()
{
    //topLeftElevator
    for (int y = 11; y <= 15; y++)
    {
        for (int x = 5; x <= 11; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //leftSideWall
    for (int y = 16; y <= 30; y++)
    {
        for (int x = 5; x <= 25; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //bottomLeftElevator
    for (int y = 31; y <= 39; y++)
    {
        for (int x = 5; x <= 10; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //leftRoomFloor
    for (int y = 40; y <= 44; y++)
    {
        for (int x = 5; x <= 25; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //leftRoomBalcony
    for (int y = 32; y <= 32; y++)
    {
        for (int x = 26; x <= 29; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //rightWall of leftRoom
    for (int y = 31; y <= 34; y++)
    {
        for (int x = 25; x <= 25; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //advertise board
    for (int y = 14; y <= 14; y++)
    {
        for (int x = 29; x <= 43; x++)
        {
            worldMap[y][x] = 1;
        }
    }





    //topLeftCorner of rightRoom
    for (int y = 29; y <= 34; y++)
    {
        for (int x = 34; x <= 34; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //bottomLeftCorner of rightRoom
    for (int y = 40; y <= 44; y++)
    {
        for (int x = 34; x <= 39; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //rightRoomCeil
    for (int y = 29; y <= 29; y++)
    {
        for (int x = 34; x <= 64; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //stair
    for (int y = 41; y <= 44; y++)
    {
        for (int x = 40; x <= 41; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    for (int y = 42; y <= 44; y++)
    {
        for (int x = 42; x <= 42; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //rightRoomFloor
    for (int y = 43; y <= 44; y++)
    {
        for (int x = 43; x <= 65; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //bottomRightElevator
    for (int y = 39; y <= 44; y++)
    {
        for (int x = 66; x <= 70; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //rightSideWall
    for (int y = 29; y <= 38; y++)
    {
        for (int x = 65; x <= 70; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //topRightElevatorRoof
    for (int y = 24; y <= 24; y++)
    {
        for (int x = 65; x <= 70; x++)
        {
            worldMap[y][x] = 1;
        }
    }
    //topRightElevator
    for (int y = 25; y <= 28; y++)
    {
        for (int x = 66; x <= 70; x++)
        {
            worldMap[y][x] = 1;
        }
    }
}

void Map::calculateMap()
{
    init();
    modify();
}