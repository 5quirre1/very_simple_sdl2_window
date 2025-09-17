#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void runGame(SDL_Window* window, SDL_Renderer* renderer)
{
    bool quit = false;
    SDL_Event e;

    // seed random so we get ACTUALLy randokm
    srand(static_cast<unsigned>(time(nullptr)));

    // last time
    Uint32 lastT = SDL_GetTicks();

    // start with a random color
    SDL_Color peak = {
        static_cast<Uint8>(rand() % 256),
        static_cast<Uint8>(rand() % 256),
        static_cast<Uint8>(rand() % 256),
        255
    };

    // main loop
    while (!quit)
    {
        // events
        while (SDL_PollEvent(&e) != 0)
        {
            // exit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        
        // check if one second passed by
        Uint32 now = SDL_GetTicks();
        if (now - lastT >= 1000)
        {
            peak.r = rand() % 256;
            peak.g = rand() % 256;
            peak.b = rand() % 256;
            peak.a = 255;

            lastT = now;
        }

        // clear screen with pretty colors
        SDL_SetRenderDrawColor(renderer, peak.r, peak.g, peak.b, peak.a);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
}
