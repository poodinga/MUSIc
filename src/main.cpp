#include <iostream>
#include "SDL_utils.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

//**************************************************************
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char WINDOW_TITLE[11] = "Games v1.0";

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};
//**************************************************************

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *windowSurface;
    SDL_Surface *imageSurface;
    initSDL(window, renderer, WINDOW_TITLE);
    bool gameRunning = true;
    SDL_Event e;
    while(gameRunning){
        while(SDL_PollEvent(&e)){
            if(e.type = SDL_QUIT){
                gameRunning = false;
            }
        }
    }

    // windowSurface = SDL_GetWindowSurface(window);
    // imageSurface = SDL_LoadBMP("res/VSCode.bmp");
    // if(imageSurface == NULL){
    //     logSDLError(std::cout, "imageSurface", true);
    // }
    // SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
    // SDL_UpdateWindowSurface(window);
    
    // waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
