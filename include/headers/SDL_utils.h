#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

enum DIRECTION
{
    LEFT,
    UP,
    RIGHT,
    DOWN,
    TOTAL
};

extern SDL_Window* g_window ;
extern SDL_Renderer* g_renderer ;
extern SDL_Event g_event ;

const int START_X = 200;
const int START_Y = 200;
const int WALL_WIDTH = 20;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 322;

void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);

void initSDL(std::string WINDOW_TILTE);

void quitSDL();

void waitUntilKeyPressed();



