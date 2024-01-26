#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "GameObject.h"
using namespace std;

GameObject::GameObject() {
    this->x = 0;
    this->y = 0;
}

GameObject::GameObject(double x, double y) {
    this->x = x;
    this->x = x;
}

void GameObject::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

void GameObject::addPosition(double xAdd, double yAdd) {
    this->x += xAdd;
    this->y += yAdd;
}

SDL_Point GameObject::getPosition() {
    SDL_Point point;
    point.x = x;
    point.y = y;
    return point;
}