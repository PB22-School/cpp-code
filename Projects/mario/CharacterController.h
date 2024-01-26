#pragma once

#include "GameObject.h"
#include "TileSet.h"
#include "AnimationPlayer.h"
#include <SDL2/SDL.h>
#include <vector>
using namespace std;

class CharacterController : public GameObject {
    protected:
    AnimationPlayer anim;
    double hsp = 0;
    double vsp = 0;
    double speed;
    SDL_Rect rect;
    public:
    CharacterController(vector<string> filenames, SDL_Renderer* renderer, double scale, double x, double y, double speed);
    CharacterController copy(SDL_Renderer* renderer);
    CharacterController() {};
    void draw(SDL_Renderer* renderer);
    void update(double delta, vector<char> keys);
    bool searchKeys(char key, vector<char> keys);
    //bool tile_meeting(TileSet tiles);
    void setRect();
    bool collideRect(SDL_Rect rect);
    CharacterController ins_meeting(vector<CharacterController> chars);
};