#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "game.hpp"
#include <iostream>
using namespace std;

int main(void)
{
    // init sdl
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cerr << "sdl_init error: " << SDL_GetError() << "\n";
        return 1;
    }

    const int screen_width = 500;
    const int screen_height = 500;

    // create window
    SDL_Window *window = SDL_CreateWindow(
        "greg",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        screen_width, screen_height,
        SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        cerr << "window didn't get created, error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    // create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!renderer)
    {
        cerr << "renderer was not created; error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // run the game loop
    runGame(window, renderer);

    // cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
