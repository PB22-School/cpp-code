#include "AnimationPlayer.h"
#include "Sprite.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
using namespace std;

AnimationPlayer::AnimationPlayer(vector<string> filenames,SDL_Renderer* renderer, double scale = 4, double x = 0, double y = 0) {
    this->animationLength = filenames.size();
    this->scale = scale;
    this->end = animationLength;
    for(int i = 0; i < animationLength; i++) {
        string end = "sprites/" + filenames[i] + ".png";
        animation.push_back(IMG_LoadTexture(renderer, end.c_str()));
        if (!animation[i]) {
            cout << "image not loaded" << endl;
        }
    }
    SDL_QueryTexture(animation[0],NULL,NULL,&this->sizeX,&this->sizeY);
    cout << sizeY << endl;
}

AnimationPlayer::AnimationPlayer() {

}

SDL_Point AnimationPlayer::getSize(int index) {
    SDL_Point p;
    SDL_QueryTexture(animation[index],NULL,NULL,&p.x,&p.y);
    p.x *= scale;
    p.y *= scale;
    return p;
}

void AnimationPlayer::updateScripted(int start, int end) {
    this->start = start;
    this->end = end;
}

void AnimationPlayer::update(double delta) {
    if (fps) {
        frame = fmod(start + frame + (delta * fps), end);
    }
    if ((flip_h && scale > 0 ) || (!flip_h && scale < 0)){
        scale *= -1;
    }
}

void AnimationPlayer::draw(SDL_Renderer* renderer, double x, double y) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = int(sizeX * scale);
    rect.h = int(sizeY * scale);
    SDL_Texture* tex = animation[int(frame)];
    if (frame >= 0 && frame < animation.size()) {
        if (tex) {
            SDL_RenderCopy(renderer,tex,NULL,&rect);
        }
        else {
            cout << "Null texture" << endl;
        }
    }
    else {
        cout << "Invalid Frame Index" << endl;
    }
}

AnimationPlayer AnimationPlayer::copy(SDL_Renderer* renderer) {
    SDL_Point p = getPosition();
    return AnimationPlayer(filenames,renderer,scale,p.x,p.y);
}