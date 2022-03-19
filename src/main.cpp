#include "Component.h"
#include "Snake.h"
#include "apple.h"

int main(int argc, char *argv[])
{
    bool isRunning = true, isPlaying = true;
    int event = -3, newEvent;
    const Uint32 FPS = 25;
    const Uint32 frameDelay = 1000 / FPS;

    initSDL("Game v0.1");
    playMusic();

    while (isRunning)
    {
        Apple apple;
        Snake snake;

        while (isPlaying)
        {
            Uint32 start = SDL_GetTicks();
            while (SDL_PollEvent(&g_event))
            {
                if (g_event.type == SDL_QUIT)
                {
                    isPlaying = false;
                    isRunning = false;
                }
                newEvent = snake.handleEvent();
            }
            if (newEvent != -3 && newEvent != event && abs(newEvent - event) != 2)
            {
                event = newEvent;
                snake.move(event);
            }
            else
                snake.move(event);
            if (snake.checkCollision() == true && snake.getLength() > 2)
            {
                isPlaying = false;
            }
            if (apple.checkEaten(snake.returnBody(), snake.getLength() - 1))
            {
                snake.grow(event);
                playSound();
            }
            SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
            SDL_RenderClear(g_renderer);
            apple.showApple(snake.getLength() - 1);
            snake.drawBody();
            displayText(snake.getLength());
            SDL_RenderPresent(g_renderer);

            Uint32 end = SDL_GetTicks() - start;
            if (frameDelay > end)
            {
                SDL_Delay(frameDelay - end);
            }
        }
        
        if (isRunning)
        {
            SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
            SDL_RenderClear(g_renderer);
            askPlayAgain();
            SDL_RenderPresent(g_renderer);
            while (true)
            {
                SDL_WaitEvent(&g_event);
                if (g_event.type == SDL_KEYDOWN)
                {
                    switch (g_event.key.keysym.sym)
                    {
                    case SDLK_SPACE:
                        isPlaying = true;
                        break;

                    default:
                        isRunning = false;
                        break;
                    }
                }
                else if (g_event.type == SDL_QUIT)
                {
                    isRunning = false;
                }
                break;
            }
        }
    }

    quitSDL();
    return 0;
}
