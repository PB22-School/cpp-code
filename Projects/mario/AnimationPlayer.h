#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include "Sprite.h"
#include "GameObject.h"

class AnimationPlayer : public GameObject {
    int animationLength;
    std::vector<SDL_Texture*> animation;
    std::vector<std::string> filenames;
    int start = 0;
    int end;
    int sizeX;
    int sizeY;
    double scale;
    public:
    double frame = 0;
    int fps = 1;
    bool flip_h = false;
    AnimationPlayer();
    AnimationPlayer(std::vector<std::string> filenames,SDL_Renderer* renderer, double scale, double x, double y);
    AnimationPlayer copy(SDL_Renderer* renderer);
    void update(double delta);
    void draw(SDL_Renderer* renderer, double x, double y);
    void updateScripted(int start, int end);
    SDL_Point getSize(int index);
};