#pragma once

#include <SDL2/SDL.h>
#include "GameObject.h"
#include <string>

class Sprite : public GameObject {
    SDL_Texture* image;
    int sizeX;
    int sizeY;
    std::string filename;
    public:
    double scale;
    SDL_Rect rect;
    Sprite();
    Sprite copy(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer, const SDL_Rect *rect);
    void updateVars(std::string filepath, SDL_Renderer* renderer, double x, double y, double scale);
    void updateVars(std::string filepath, SDL_Renderer* renderer, double scale);
    void setPos(double x, double y);
    void addPos(double x, double y);
    void setTexture(SDL_Texture* texture);
    void updateScale(double scale);
};