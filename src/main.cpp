#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <unistd.h>
#include <thread>
#include <future>
#include <string>

#include "game.hpp"
#include "gameobject.hpp"
#include "spriteman.hpp"
#include "musicman.hpp"

int randInRange(int smallest, int max) {
    return smallest - 1 + (rand() % max + 1);
}

std::vector<Card *> initCards(SpriteManager sman, int *freeX, int *freeY, SDL_Renderer *renderer, int matches) {
    std::vector<Card *> result;

    int tempID;

    for(int i = 0; i < matches * 2; i++) {
        tempID = randInRange(card1, card14);
        result.push_back(new Card(sman.get(tempID, renderer), sman.get(question, renderer), result.size() % 4 == 0 ? *freeX = 160 : *freeX += 160, *freeY += result.size() % 4 == 0 ? 160 : 0, 128, 128, tempID));
    }

    return result;
}

void resetCards(std::vector<Card *> &cards, int &freeX, int &freeY) {
    for(int i = 0; i < cards.size(); i++) {
        cards[i]->transform.x = i % 4 == 0 ? freeX = 160 : freeX += 160;
        cards[i]->transform.y = i % 4 == 0 ? freeY += 160 : freeY += 0;
        if(i < 16) cards[i]->show = true;
    }
}

int main(int argc, char *argv[]) {
    
    MemGame *game = new MemGame();

    SDL_Window *window = game->createWindow("pamięć gra", 1280, 720, 0);

    SDL_Renderer *renderer = game->initRenderer(window);

    SDL_Event event;

    // printf("Input the gamemode: \n1. US Presidents \n2. Laughing emoji mode \n3. Meme mode \n");

    // int mode;

    // std::cin >> mode;

    // mode--;

    SpriteManager sman(president_mode);

    BG *background = new BG(sman.get(bg, renderer));

    MusicManager musicman;

    musicman.init();

    musicman.play("src/resources/theme.mp3");

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    time_t current_time = time(NULL);

    srand(current_time);

    int matches = randInRange(20, 40);

    std::vector<Card *> cards;

    int freeX = 0, freeY = -64;

    int mouseX, mouseY;

    cards = initCards(sman, &freeX, &freeY, renderer, matches);

    Card *card1 = NULL, *card2 = NULL;

    int index1, index2;

    GameObject *checkmarkObject = new GameObject(sman.get(checkmark, renderer), 256, 256, 256, 256);

    int matched = 0;

    std::string cmd;

    while(true) {

        SDL_RenderClear(renderer);

        while(SDL_PollEvent(&event)) {

            switch(event.type) {

                case SDL_QUIT: Mix_HaltMusic(); exit(0); break;

                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT) {
                        SDL_GetMouseState(&mouseX, &mouseY);

                        for(int i = 0; i < cards.size(); i++) {
                            if(cards[i]->show) {
                                if(mouseX >= cards[i]->transform.x && mouseX <= cards[i]->transform.x + cards[i]->transform.w && mouseY >= cards[i]->transform.y && mouseY <= cards[i]->transform.y + cards[i]->transform.h) {
                                    cards[i]->uncover();

                                    draw(background, renderer);
                                    
                                    for(int j = 0; j < cards.size(); j++) {
                                        if(cards[j]->show) draw(cards[j], renderer);
                                    }

                                    SDL_RenderPresent(renderer);

                                    if(card1 != NULL) {
                                        if(!card1->isCovered) {
                                            index2 = i;
                                            if(index2 != index1) {
                                                card2 = cards[i];
                                                card2->isCovered = false;
                                                if(card2->card_id == card1->card_id) {
                                                    matched++;
                                                    sleep(1);
                                                    for(int j = 0; j < cards.size(); j++) {
                                                        if(cards[j]->card_id == card1->card_id && cards[j]->ID == card1->ID || cards[j]->card_id == card2->card_id && cards[j]->ID == card2->ID)
                                                        {
                                                            cards.erase(cards.begin() + j);
                                                        }
                                                    }

                                                    freeX = 0;
                                                    freeY = -64;

                                                    resetCards(cards, freeX, freeY);
                                                    
                                                } else {
                                                    sleep(1);
                                                    cards[index1]->cover();
                                                    cards[index2]->cover();
                                                }
                                                card1 = NULL;
                                                card2 = NULL;
                                                index1 = 0;
                                                index2 = 0;
                                            } else {
                                                index2 = 0;
                                                sleep(1);
                                                cards[index1]->cover();
                                                cards[index2]->cover();
                                            }
                                        }
                                    } else {
                                        card1 = cards[i];
                                        card1->isCovered = false;
                                        index1 = i;
                                    }
                                }
                            }
                        }
                    }
                    break;

                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_c)
                    {
                        printf("console > ");
                        std::getline(std::cin, cmd);

                        if(cmd == "game->simulate->win") { matched = matches; }
                        else if(cmd == "game->simulate->crash") { throw 1; }
                        else if(cmd == "game->cards->mode->all-are-the-same") { for(int i = 0; i < cards.size(); i++) { cards[i]->card_id = cards[0]->card_id; cards[i]->uncovered = cards[0]->uncovered; } }
                        else if(cmd == "game->cards->all->erase") { for(int i = 0; i < cards.size(); i++) { cards.erase(cards.begin() + i); } }
                    }

                default: break;

            }

        }

        // do update stuff here
        draw(background, renderer);

        for(int i = 0; i < cards.size(); i++) {
            if(i > 15) cards[i]->show = false;
            if(cards[i]->show) draw(cards[i], renderer);
        }

        if(matched == matches) {
            draw(checkmarkObject, renderer);
        }

        SDL_RenderPresent(renderer);
    }

    return 0;

}