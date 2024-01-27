#include <string>
#include "Sprite.h"
#include "GameObject.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

void Sprite::setPos(double x = 0.0, double y = 0.0) {
    rect.x = x;
    rect.y = y;
}

void Sprite::addPos(double x = 0.0, double y = 0.0) {
    rect.x += x;
    rect.y += y;
}

Sprite::Sprite() {
    
}

void Sprite::updateVars(string filepath, SDL_Renderer* renderer, double scale = 4) {
    setPos();
    string end = "sprites/" + filepath + ".png";
    this->image = IMG_LoadTexture(renderer, end.c_str());
    if (!image) {
        cout << "it's not working." << endl;
    }
    SDL_QueryTexture(image,NULL,NULL,&rect.w,&rect.h);
    this->sizeX = rect.w;
    this->sizeY = rect.h;
    rect.w = int(scale * rect.w);
    rect.h = int(scale * rect.h);
    this->filename = filepath;
}

void Sprite::updateVars(string filepath, SDL_Renderer* renderer, double x, double y, double scale = 4) {
    setPos(x,y);
    string end = "sprite/" + filepath + ".png";
    this->image = IMG_LoadTexture(renderer, end.c_str());
    if (!image) {
        cout << "it's not working." << endl;
    }
    SDL_QueryTexture(image,NULL,NULL,&rect.w,&rect.h);
    this->sizeX = rect.w;
    this->sizeY = rect.h;
    this->filename = filepath;
    rect.w = int(scale * rect.w);
    rect.h = int(scale * rect.h);
}

void Sprite::draw(SDL_Renderer* renderer) {
    if (image != 0) {
        SDL_RenderCopy(renderer, image, NULL, &rect);
    }
    else {
        //cerr << "THINGS NOT LOADED" << endl;
    }
}

void Sprite::draw(SDL_Renderer* renderer, const SDL_Rect* rect) {
    if (image != 0) {
        SDL_RenderCopy(renderer, image, NULL, rect);
    }
    else {
        //cerr << "THINGS NOT LOADED" << endl;
    }
}

void Sprite::setTexture(SDL_Texture* texture) {
    this->image = texture;
}

void Sprite::updateScale(double scale) {
    rect.w = sizeX * scale;
    rect.h = sizeY * scale;
}

Sprite Sprite::copy(SDL_Renderer* renderer) {
    Sprite spr;
    spr.updateVars(filename,renderer,scale);
    return spr;
}