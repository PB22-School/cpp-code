#include "CharacterController.h"
#include "TileSet.h"
#include "AnimationPlayer.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

CharacterController::CharacterController(vector<string> filenames, SDL_Renderer* renderer, double scale, double x, double y, double speed = 5) : anim(filenames, renderer, scale, x, y){
    setPosition(x,y);
    this->speed = speed;
    // after this constructor is called, the anim variable just deletes itself and is re-made blankly for some reason
}

void CharacterController::draw(SDL_Renderer* renderer) {
    SDL_Point p = getPosition();
    anim.draw(renderer, p.x, p.y);
}

void CharacterController::setRect() {
    SDL_Point p = getPosition();
    SDL_Point r = anim.getSize(int(anim.frame));
    rect.x = p.x;
    rect.y = p.y;
    rect.w = r.x;
    rect.h = r.y;
}

void CharacterController::update(double delta, vector<char>) {
    anim.update(delta);
    setRect();
    addPosition(hsp * delta * speed, vsp * delta * speed);
}

bool CharacterController::searchKeys(char key, vector<char> keys) {
    for (int i = 0; i < keys.size(); i++) {
        if (key == keys[i]) {
            return true;
        }
    }
    return false;
}

CharacterController CharacterController::copy(SDL_Renderer* renderer) {
    CharacterController character(*this);
    character.speed = speed;
    character.anim = anim.copy(renderer);
    return character;
}

CharacterController CharacterController::ins_meeting(vector<CharacterController> chars) {
    for (int i = 0; i < chars.size(); i++) {
        if (chars[i].collideRect(rect)) {
            return chars[i];
        }
    }
    return CharacterController();
}

bool CharacterController::collideRect(SDL_Rect other) {
    return bool(SDL_IntersectRect(&rect,&other,NULL));
}