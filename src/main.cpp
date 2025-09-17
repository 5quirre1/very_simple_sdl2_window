#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "hexrgbSDL.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  // init sdl
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    cerr << "sdl_init error: " << SDL_GetError() << "\n";
    return 1;
  }

  // create window
  const int screen_width = 500;
  const int screen_height = 500;

  SDL_Window *window = SDL_CreateWindow(
      "greg",
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      screen_width, screen_height,
      SDL_WINDOW_SHOWN
  );
  
  // error handle for if window no create
  if (!window)
  {
    cerr << "window didn't get created, error: " << SDL_GetError() << "\n";
    SDL_Quit();
    return 1;
  }

  // renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(
    window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );

  // renderer error
  if (!renderer)
  {
    cerr << "renderer was not created; error: " << SDL_GetError() << "\n";
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  bool quit = false;
  SDL_Event e;

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

    // clear screen and make with prettu color
    SDL_Color peak = fixColors("#0f3f67ff");
    SDL_SetRenderDrawColor(renderer, peak.r, peak.g, peak.b, peak.a);
    SDL_RenderClear(renderer);

    
    SDL_RenderPresent(renderer);
  }
  
  // cleanup the stuff
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
