#pragma once

#include <SDL2/SDL.h>

class MemGame {
public:
    SDL_Window *createWindow(const char *title, int width, int height, u_int32_t windowFlags);
    SDL_Renderer *initRenderer(SDL_Window *window);
};