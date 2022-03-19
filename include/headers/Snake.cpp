#include "Snake.h"

Snake::Snake()
{
    spawnSnake();
    drawHead();
}

void Snake::spawnSnake()
{
    SDL_Rect head = {START_X, START_Y, WALL_WIDTH, WALL_WIDTH};
    SDL_Rect& r_head = head;
    body.body_.push_back(r_head);
    drawHead();
} 

void Snake::drawHead()
{
    SDL_SetRenderDrawColor(g_renderer, 40, 200, 60, 255);
    SDL_RenderFillRect(g_renderer, &body.body_[0]);
}

void Snake::drawBody()
{
    drawHead();
    SDL_SetRenderDrawColor(g_renderer, 255, 180, 30, 255);
    for(int i = 1; i < body.length; i++)
    {
        SDL_RenderFillRect(g_renderer, &body.body_[i]);
    }
}

int Snake::getLength()
{
    return body.length;
}

snakeBody  Snake::returnBody()
{
    return body;
}

void Snake::grow(int direction_)
{
    SDL_Rect newPart ;
    int x = 0, y = 0;
    switch (direction_)
    {
        case UP:
            y -= 20; break;
        case DOWN:
            y += 20; break;
        case LEFT:
            x -= 20; break;
        case RIGHT:
            x += 20; break;
    }
    newPart = {body.body_[getLength()-1].x + x, body.body_[getLength()-1].y + y, WALL_WIDTH, WALL_WIDTH};
    SDL_Rect& temp = newPart;
    body.body_.push_back(temp);
    body.length ++;
}

void Snake::move(int eDirection)
{
    if(eDirection != -3)
    {
        if(body.body_[0].y < 0) 
            body.body_[0].y += SCREEN_HEIGHT ;
        if(body.body_[0].x < 0)
            body.body_[0].x += SCREEN_WIDTH ;
        if(body.body_[0].y > SCREEN_HEIGHT)
            body.body_[0].y -= SCREEN_HEIGHT;
        if(body.body_[0].x > SCREEN_WIDTH)
            body.body_[0].x -= SCREEN_WIDTH ;
        for(int i = body.length - 1; i > 0; i--)
            body.body_[i] = body.body_[i-1];
        switch(eDirection)
        {
            case UP:
                body.body_[0].y -= 20; break;
            case DOWN:
                body.body_[0].y += 20; break;
            case LEFT:
                body.body_[0].x -= 20; break;
            case RIGHT:
                body.body_[0].x += 20; break;
        }
    }
    
}

int Snake::handleEvent()
{
    if(g_event.type == SDL_KEYDOWN )
    {
        switch (g_event.key.keysym.sym)
        {
            case SDLK_UP:    
                // body.speedY -= 20;
                // body.speedX = 0;
                return UP; 
                break;
            case SDLK_DOWN:  
                // body.speedY += 20;
                // body.speedX = 0;
                return DOWN; 
                break;
            case SDLK_LEFT:  
                // body.speedX -= 20;
                // body.speedY = 0;
                return LEFT; 
                break;
            case SDLK_RIGHT: 
                // body.speedX += 20;
                // body.speedY = 0;
                return RIGHT; 
                break;
        }
    }
    return -3;
}

bool Snake::checkCollision()
{
    SDL_bool collied;
    for(int i = body.length - 1; i > 0; i--)
    {
        collied = SDL_HasIntersection(&body.body_[0], &body.body_[i]);
        if(collied == SDL_TRUE) return true;
    }
    return false;
    
}

