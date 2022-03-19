#include "SDL_utils.h"

//*****************************************************
// Các hàm chung về khởi tạo và huỷ SDL
void logSDLError(std::ostream &os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(std::string WINDOW_TILTE)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    g_window = SDL_CreateWindow(WINDOW_TILTE.c_str(), SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (g_window == nullptr)
        logSDLError(std::cout, "CreateWindow", true);

    // Khi thông thường chạy với môi trường bình thường ở nhà
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    // renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (g_renderer == nullptr)
        logSDLError(std::cout, "CreateRenderer", true);

    if (TTF_Init() < 0)
    {
        logSDLError(std::cout, "Error intializing SDL_ttf", true);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
    {
        std::cout << "Error initializing SDL_mixer: " << Mix_GetError() << "\n";
        SDL_Quit();
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(g_renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL()
{
    SDL_DestroyRenderer(g_renderer);
    g_renderer = nullptr;

    SDL_DestroyWindow(g_window);
    g_window = nullptr;

    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    while (true)
    {
        if (SDL_WaitEvent(&g_event) != 0 &&
            (g_event.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}

void displayText(int score)
{
    std::string score_ = std::to_string(score);
    TTF_Font *font = TTF_OpenFont("fonts/CCOverbyteOn.ttf", 35);
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, score_.c_str(), color);
    SDL_Texture *text = SDL_CreateTextureFromSurface(g_renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = 20;
    textRect.y = 20;
    SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
    SDL_RenderCopy(g_renderer, text, NULL, &textRect);
}

void playMusic()
{
    Mix_Music *music = Mix_LoadMUS("music/background.mp3");
    if (!music)
    {
        std::cout << "Error loading music " << Mix_GetError() << "\n";
        SDL_Quit();
        exit(1);
    }
    Mix_PlayMusic(music, -1);
}

void playSound()
{
    Mix_Chunk *eaten = Mix_LoadWAV("music/appleEaten.wav");
    if (!eaten)
    {
        std::cout << "Error loading sound " << Mix_GetError() << "\n";
        SDL_Quit();
        exit(1);
    }
    Mix_PlayChannel(-1, eaten, 0);
}

void askPlayAgain()
{
    std::string t = "PRESS [SPACE] TO PLAY AGAIN";
    TTF_Font *font = TTF_OpenFont("fonts/CCOverbyteOn.ttf", 35);
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, t.c_str(), color);
    SDL_Texture *text = SDL_CreateTextureFromSurface(g_renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = 400;
    textRect.y = 250;
    SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
    SDL_RenderCopy(g_renderer, text, NULL, &textRect);

}
