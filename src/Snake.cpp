#include "Snake.hpp"

Snake::Snake() { 
    // 뱀의 초기화
}

void Snake::SetDirection(SnakeDirection direction) {
    _direction = direction;
}

void Snake::Update(float dt) {
    switch (_direction) {
        case UP:
            _position.y -= _speed * dt;
            break;
        case DOWN:
            _position.y += _speed * dt;
            break;
        case LEFT:
            _position.x -= _speed * dt;
            break;
        case RIGHT:
            _position.x += _speed * dt;
            break;
    }
}