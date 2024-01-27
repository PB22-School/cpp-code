#pragma once

#include "GameObject.h"
#include "TileSet.h"
#include "AnimationPlayer.h"
#include <SDL2/SDL.h>
#include <vector>
using namespace std;

class TileSet;

class CharacterController : public GameObject {
    protected:
    AnimationPlayer anim;
    SDL_Rect rect;
    public:
    vector<vector<int>> surroundTiles;
    enum {INDEX,DATA};
    enum {BOTTOM_LEFT,BOTTOM,BOTTOM_RIGHT,LEFT,MIDDLE,RIGHT,TOP_LEFT,TOP,TOP_RIGHT};
    CharacterController* bodyCollide;
    string name;
    double speed;
    double hsp = 0;
    double vsp = 0;
    CharacterController(vector<string> filenames, SDL_Renderer* renderer, double scale, double x, double y, double speed, string name);
    CharacterController copy(SDL_Renderer* renderer);
    CharacterController() {};
    void draw(SDL_Renderer* renderer);
    void update(double delta, vector<CharacterController> objects, TileSet tiles);
    void fps(int s);
    void setRect();
    bool collideRect(SDL_Rect rect);
    void place_meeting(double delta, TileSet tiles, double xOffset, double yOffset);
    CharacterController* ins_meeting(vector<CharacterController>& chars);
};