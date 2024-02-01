#include "musicman.hpp"

#include <SDL2/SDL_mixer.h>

void MusicManager::init() {
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize : %s\n", Mix_GetError());
    }
}

void MusicManager::play(const char *path) {

    this->toplay = Mix_LoadMUS(path);

    Mix_MasterVolume(32);

    if(!Mix_PlayingMusic()) {
        Mix_PlayMusic(this->toplay, 1000);   
    }

}
