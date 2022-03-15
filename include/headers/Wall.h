#ifndef WALL_H
#define WALL_H

#include "Component.h"


class Wall : public Component
{
    public:
        void drawWall();
        void setWall(int x, int y, int w, int h);

    private:
        SDL_Rect rect_;

};

void setupWalls(Wall walls[TOTAL]);

#endif