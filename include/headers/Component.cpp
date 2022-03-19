#include "Component.h"

SDL_Window *g_window = NULL;
SDL_Renderer *g_renderer = NULL;
SDL_Event g_event;

Component::Component()
{
    component = nullptr;
    rect_ = {0, 0, 0, 0};
}

Component::~Component()
{
    free();
}

bool Component::loadImage(std::string path, SDL_Renderer *renderer)
{
    SDL_Texture *newTexture = nullptr;

    SDL_Surface *loadSurface = IMG_Load(path.c_str());
    if (loadSurface != nullptr)
    {
        SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, 167, 175, 180));
        newTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
        if (newTexture != nullptr)
        {
            rect_.w = loadSurface->w;
            rect_.h = loadSurface->h;
            SDL_FreeSurface(loadSurface);
        }
    }

    component = newTexture;
    return component != nullptr;
}

void Component::Render(SDL_Renderer *renderer, SDL_Rect *clip)
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(renderer, component, clip, &renderquad);
}

void Component::free()
{
    if (component != nullptr)
    {
        SDL_DestroyTexture(component);
        component = nullptr;
        rect_.h = 0;
        rect_.w = 0;
    }
}
