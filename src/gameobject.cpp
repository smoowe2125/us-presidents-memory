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

Card::Card(SDL_Texture *uncovered, SDL_Texture *covered, int x, int y, int w, int h, int card_id) : GameObject(covered, x, y, w, h) {
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

// void Grid::add(Card *card) {

//     this->elements.push_back(card);
//     puts("pusz bak dwa");

//     if(this->elements.size() > this->size) {
//         puts("wieksze");
//         this->elements[i]->show = false;
//     } else {

//         puts("mniejsze");

//         this->elements[i]->transform.x = this->freeX;
//         this->elements[i]->transform.y = this->freeY;

//         puts("card strzalka transform rowna sie dys strzalka fri");

//         this->freeX += 64;

//         puts("inkrement");
        
//         if(this->elements.size() % 3 == 0) {
//             this->freeY += 64;
//         }

//     }

//     i++;
// }

// Grid::Grid(int size) : GameObject(NULL, 1280 / size, 720 / size, 0, 0) {
//     this->freeX = this->transform.x;
//     this->freeY = this->transform.y;
//     this->size = size;
// }