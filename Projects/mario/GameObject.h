#pragma once

#include <SDL2/SDL.h>
#include <vector>

class GameObject {
    double x;
    double y;
    public:
    GameObject();
    GameObject(double x, double y);
    void setPosition(double x, double y);
    void addPosition(double xAdd, double yAdd);
    SDL_Point getPosition();
    void update(double delta, std::vector<char> keys);
    void draw(SDL_Renderer* renderer);
};