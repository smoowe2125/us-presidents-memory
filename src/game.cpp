#include "game.hpp"

#include <SDL2/SDL.h>

SDL_Window *MemGame::createWindow(const char *title, int width, int height, u_int32_t windowFlags) {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Couldn't init SDL : %s\n", SDL_GetError());
        exit(1);
    }

    return SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, windowFlags);
}

SDL_Renderer *MemGame::initRenderer(SDL_Window *window) {

    u_int32_t rendererFlags = SDL_RENDERER_ACCELERATED;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    return SDL_CreateRenderer(window, -1, rendererFlags);

}