#ifndef COMPONENT_H
#define COMPONENT_H

#include "SDL_utils.h"

class Component
{
public:
    Component();
    ~Component();
    void setRect(const int& x, const int& y) {rect_.x = x, rect_.y = y;}
    SDL_Rect getRect() const { return rect_; }
    SDL_Texture* getComponent() const {return component;}

    bool loadImage(std::string path, SDL_Renderer* rennderer);
    void Render(SDL_Renderer* renderer, SDL_Rect* clip);
    void free();


private:
    SDL_Texture* component;
    SDL_Rect rect_;
};

#endif