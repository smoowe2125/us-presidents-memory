#pragma once

#include <vector>
#include <SDL2/SDL_image.h>

#include "spriteman.hpp"

class GameObject {
public:
    SDL_Texture *sprite;
    SDL_Rect transform;
    GameObject(SDL_Texture *sprite, int x, int y, int w, int h);
    void destroy();
    bool show = true;
    int ID;
};

class Card : public GameObject {
public:
    SDL_Texture *uncovered;
    SDL_Texture *covered;

    bool isCovered = true;

    sprite_id card_id;

    Card(SDL_Texture *uncovered, SDL_Texture *covered, int x, int y, int w, int h, sprite_id card_id);

    void uncover();

    void cover();
};

class BG : public GameObject {
public:
    BG(SDL_Texture *texture);
};