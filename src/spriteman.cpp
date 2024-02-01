#include "spriteman.hpp"
#include "gameobject.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SpriteManager::SpriteManager(int gamemode) {
    this->gameMode = gamemode;
}

SDL_Texture *SpriteManager::get(sprite_id sprite, SDL_Renderer *renderer) {

    return SDL_CreateTextureFromSurface(renderer, this->getSurface(sprite));

}

SDL_Surface *SpriteManager::getSurface(sprite_id sprite) {
    
    switch(sprite) {
        case card1: return IMG_Load("src/resources/biden.jpg");
        case card2: return IMG_Load("src/resources/carter.jpg");
        case card3: return IMG_Load("src/resources/eisenhower.jpg");
        case card4: return IMG_Load("src/resources/ford.jpg");
        case card5: return IMG_Load("src/resources/johnson.jpg");
        case card6: return IMG_Load("src/resources/kennedy.jpg");
        case card7: return IMG_Load("src/resources/lincoln.jpg");
        case card8: return IMG_Load("src/resources/nixon.jpg");
        case card9: return IMG_Load("src/resources/obama.jpg");
        case card10: return IMG_Load("src/resources/roosevelt.jpg");
        case card11: return IMG_Load("src/resources/truman.jpg");
        case card12: return IMG_Load("src/resources/trump.jpg");
        case card13: return IMG_Load("src/resources/washington.jpg");
        case card14: return IMG_Load("src/resources/wilson.jpg");
        case bg: return IMG_Load("src/resources/us.jpg");
        case question: return IMG_Load("src/resources/question.png");
        case checkmark: return IMG_Load("src/resources/checkmark.jpg");
        default: return NULL;
    }

}

void draw(GameObject *object, SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, object->sprite, NULL, &object->transform);
}