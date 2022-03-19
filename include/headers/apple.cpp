#include "apple.h"

Apple::Apple()
{
    spawnApples();
    showApple(0);
}

void Apple::spawnApples()
{
    srand(time(0));
    for(int i = 0; i < 1000; i++)
    {
        SDL_Rect apple = {rand()%64*20, rand()%32*20, 20, 20};
        apples.push_back(apple);
    }
}

void Apple::showApple(int eaten)
{
    SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(g_renderer, &apples[eaten]);
}

bool Apple::checkEaten(snakeBody snakeBody_, int eaten)
{
    if(SDL_HasIntersection(&apples[eaten], &snakeBody_.body_[0]) == SDL_TRUE) return true;
    return false;
}
