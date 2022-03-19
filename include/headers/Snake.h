#ifndef SNAKE_H
#define SNAKE_H

#include "Component.h"


struct snakeBody
{
    std::vector<SDL_Rect> body_;
    // int speedX = 0, speedY = 0;
    int length = 1;
    // int direction = 6;
};

class Snake
{
public: 
    Snake();
    void drawHead();
    void spawnSnake();
    void drawBody();
    void grow(int direction_);
    int getLength();
    void move(int direction_);
    int handleEvent();
    bool checkCollision();
    snakeBody returnBody();

private:
    snakeBody body;
};


#endif