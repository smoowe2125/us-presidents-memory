#pragma once

class GameObject;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum sprite_id {
    card1,
    card2,
    card3,
    card4,
    card5,
    card6,
    card7,
    card8,
    card9,
    card10,
    card11,
    card12,
    card13,
    card14,
    bg,
    question,
    checkmark
};

enum gameMode {
    president_mode,
    laughing_emoji_mode,
    meme_mode
};

class SpriteManager {
public:
    int gameMode;

    SpriteManager(int gamemode);

    SDL_Texture *get(sprite_id sprite, SDL_Renderer *renderer);

    SDL_Surface *getSurface(sprite_id sprite);
};

void draw(GameObject *object, SDL_Renderer *renderer);