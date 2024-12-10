#include "GamePlay.hpp"
#include "Game.hpp"
#include "Snake.hpp"
#include <iostream>

GamePlay::GamePlay(GameDataRef data) : _data(data) { }

void GamePlay::Init() {
    // 초기화 코드
}

void GamePlay::HandleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _data->stateMan.Quit();
        }

        if (event.type == SDL_KEYDOWN) {
            SnakeDirection direction;

            if (event.key.keysym.sym == SDLK_UP) direction = UP;
            else if (event.key.keysym.sym == SDLK_DOWN) direction = DOWN;
            else if (event.key.keysym.sym == SDLK_LEFT) direction = LEFT;
            else if (event.key.keysym.sym == SDLK_RIGHT) direction = RIGHT;

            _snake.SetDirection(direction);
        }
    }
}

void GamePlay::Update(float dt) {
    _snake.Update(dt);
}

void GamePlay::Draw(float dt) {
    _data->window.clear();
    _snake.Draw();
    _data->window.display();
}