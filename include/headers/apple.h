#ifndef APPLE_H
#define APPLE_H

#include "Component.h"
#include "Snake.h"

class Apple
{
public:
    Apple();
    void spawnApples();
    void showApple(int eaten);
    bool checkEaten(snakeBody snakebody_, int index);
    std::vector<SDL_Rect> apples;
};

#endif