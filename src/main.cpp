#include <iostream>
#include <fstream>
#include <string>
#include <SDL2/SDL.h>
#include "Game.hpp"

using namespace std;

bool quit = false;
SDL_Event e;

string readSerialData(const string& port) {
    ifstream serialInput(port);
    string data;

    if (serialInput.is_open()) {
        getline(serialInput, data);
    }

    return data;
}

void handleJoystickInput(SDL_Event* e) {
    string serialData = readSerialData("/dev/tty.usbmodem14101"); // macOS의 경우
    if (serialData.empty()) return;

    char direction = serialData[0];

    switch (direction) {
        case 'U':
            e->key.keysym.sym = SDLK_UP;  // 위쪽
            break;
        case 'D':
            e->key.keysym.sym = SDLK_DOWN; // 아래쪽
            break;
        case 'L':
            e->key.keysym.sym = SDLK_LEFT; // 왼쪽
            break;
        case 'R':
            e->key.keysym.sym = SDLK_RIGHT; // 오른쪽
            break;
        case 'B':
            // 조이스틱 버튼 입력 처리
            break;
        default:
            break;
    }
}

int main(int argc, char* argv[]) {
    Game game;
    game.Run();
    return 0;
}