#include "CharacterController.h"
#include "TileSet.h"
#include "AnimationPlayer.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

CharacterController::CharacterController(vector<string> filenames, SDL_Renderer* renderer, double scale, double x, double y, double speed = 5, string name = "Undefined") : anim(filenames, renderer, scale, x, y){
    setPosition(x,y);
    this->speed = speed;
    this->name = name;
    // after this constructor is called, the anim variable just deletes itself and is re-made blankly for some reason
}

void CharacterController::draw(SDL_Renderer* renderer) {
    SDL_Point p = getPosition();
    SDL_SetRenderDrawColor(renderer,0,255,0,255);
    SDL_RenderDrawRect(renderer,&rect);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
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

void CharacterController::update(double delta, vector<CharacterController> objects, TileSet tiles) {
    anim.update(delta);
    addPosition(hsp * delta * speed, vsp * delta);
    setRect();
    surroundTiles = tiles.getCollide(rect);
    bodyCollide = ins_meeting(objects);
}

void CharacterController::fps(int s) {
    anim.fps = s;
}

void CharacterController::place_meeting(double delta, TileSet tiles, double xOffset, double yOffset) {
    // gets the next frame's surroundTiles early 
    // (to see if something is about to collide)
    SDL_Rect cur;
    cur.x = rect.x + xOffset;
    cur.y = rect.y + yOffset;
    cur.w = rect.w;
    cur.h = rect.h;
    surroundTiles = tiles.getCollide(rect);
}

CharacterController CharacterController::copy(SDL_Renderer* renderer) {
    CharacterController character(*this);
    character.speed = speed;
    character.anim = anim.copy(renderer);
    return character;
}

CharacterController* CharacterController::ins_meeting(vector<CharacterController>& chars) {
    for (int i = 0; i < chars.size(); i++) {
        if (chars[i].collideRect(rect)) {
            return &chars[i];
        }
    }
    return nullptr;
}

bool CharacterController::collideRect(SDL_Rect other) {
    return bool(SDL_IntersectRect(&rect,&other,NULL));
}