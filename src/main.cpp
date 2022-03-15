#include "Wall.h"
#include "Component.h"
#include "Snake.h"
#include "apple.h"

int main(int argc, char* argv[])
{
    Apple apple;
    Snake snake;
    initSDL("Game v0.1");
    bool isRunning = true;
    int event = -3, newEvent;
    while(isRunning)
    {
        while(SDL_PollEvent(&g_event))
        {
            if(g_event.type == SDL_QUIT) isRunning = false;
            newEvent = snake.handleEvent();
        }
        if(newEvent != -3 && newEvent != event && abs(newEvent - event) != 2) 
        {
            event = newEvent;
            snake.move(event);
        }
        else snake.move(event);
        if(snake.checkCollision() == true && snake.getLength() > 2)
        {
            isRunning = false;
        }
        if(apple.checkEaten(snake.returnBody(), snake.getLength() - 1))
        {
            snake.grow();
        }
        SDL_SetRenderDrawColor(g_renderer, 0 , 0 , 0, 255);
        SDL_RenderClear(g_renderer);
        apple.showApple(snake.getLength() - 1) ;
        snake.drawBody();
        SDL_RenderPresent(g_renderer);
        SDL_Delay(50);
    }
    quitSDL();
    return 0;
}

