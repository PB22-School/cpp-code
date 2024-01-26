#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameObject.h"
#include "CharacterController.h"
#include "Sprite.h"
#include <vector>
#include <string>
using namespace std;

class TileSet : public GameObject {
    vector<vector<int>> indexData;
    vector<vector<int>> customData;
    vector<int> animData;
    int tileSize;
    double scale;
    vector<Sprite> tiles;
    bool animated = false;
    int fps = 1;
    int animationLength;
    double frame = 0;
    public:
    TileSet(vector<string> filenames, SDL_Renderer* renderer, double scale);
    TileSet(vector<string> filenames, vector<int> animations, SDL_Renderer* renderer, double scale);
    void readData(string filename);
    void draw(SDL_Renderer* renderer);
    void update(double delta, SDL_Renderer* renderer);
    void ready(SDL_Renderer* renderer, SDL_Point& mario, vector<SDL_Point>& goombas, vector<SDL_Point>& coins);
    bool getCollide(SDL_Rect rect);
};