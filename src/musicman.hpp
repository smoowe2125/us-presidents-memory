#pragma once

#include <SDL2/SDL_mixer.h>

class MusicManager {
private:
    Mix_Music *toplay;
public:
    void init();
    void play(const char *path);
};