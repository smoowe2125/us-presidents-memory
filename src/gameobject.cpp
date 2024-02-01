#include "gameobject.hpp"

#include "spriteman.hpp"

#include <SDL2/SDL_image.h>

std::vector<GameObject *> objects;
int aID = 0;

GameObject::GameObject(SDL_Texture *sprite, int x, int y, int w, int h) {
    this->sprite = sprite;
    this->transform.x = x;
    this->transform.y = y;
    this->transform.w = w;
    this->transform.h = h;
    this->ID = aID;
    objects.push_back(this);
    aID++;
}

void GameObject::destroy() {
    delete this;
}

Card::Card(SDL_Texture *uncovered, SDL_Texture *covered, int x, int y, int w, int h, sprite_id card_id) : GameObject(covered, x, y, w, h) {
    this->uncovered = uncovered;
    this->covered = covered;
    this->card_id = card_id;
}

void Card::uncover() {
    this->sprite = uncovered;
}

void Card::cover() {
    this->sprite = covered;
}

BG::BG(SDL_Texture *texture) : GameObject(texture, 0, 0, 1280, 720) {};