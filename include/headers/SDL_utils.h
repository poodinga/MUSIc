#include <iostream>
#include <SDL2/SDL.h>
#include <string>

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, const char* WINDOW_TILTE) ;

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect);

SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* &renderer);