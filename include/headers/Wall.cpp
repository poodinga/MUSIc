#include "Wall.h"



// Draw one wall with brown
void Wall::drawWall()
{
    SDL_SetRenderDrawColor(g_renderer, 209, 255, 15, 255);
    SDL_RenderFillRect(g_renderer, &rect_);
}


// Set the width and location of wall
void Wall::setWall(int x, int y, int w, int h)
{
    rect_.h = h;
    rect_.w = w;
    rect_.x = x;
    rect_.y = y;
}


// Setup an array of Wall objects
void setupWalls(Wall walls[TOTAL])
{
    walls[LEFT].setWall(0, 0, WALL_WIDTH, SCREEN_HEIGHT);
    walls[RIGHT].setWall(SCREEN_WIDTH - WALL_WIDTH, 0,  WALL_WIDTH, SCREEN_HEIGHT);
    walls[UP].setWall(0, 0, SCREEN_WIDTH, WALL_WIDTH);
    walls[DOWN].setWall(0, SCREEN_HEIGHT- WALL_WIDTH, SCREEN_WIDTH, WALL_WIDTH);
    for(int i = 0; i< 4; i++)
    {
        walls[i].drawWall();
    }
}