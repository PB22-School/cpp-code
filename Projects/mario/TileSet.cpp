#include "TileSet.h"
#include "CharacterController.h"
#include <fstream>
#include <ios>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

TileSet::TileSet(vector<string> filenames, SDL_Renderer* renderer, double scale) {
    for(int i = 0; i < filenames.size(); i++) {
        Sprite spr;
        spr.updateVars(filenames[i], renderer, scale);
        tiles.push_back(spr);
    }
    this->tileSize = tiles[0].rect.w;
    this->scale = scale;
}

TileSet::TileSet(vector<string> filenames, vector<int> animations, SDL_Renderer* renderer, double scale) {
    this->animationLength = filenames.size();
    this->animData = animations;
    this->animated = true;
    for (int i = 0; i < filenames.size(); i++) {
        Sprite spr;
        spr.updateVars(filenames[i], renderer, scale);
        tiles.push_back(spr);
    }
    this->tileSize = tiles[0].rect.w;
    this->scale = scale;
}

void TileSet::readData(string filename) {
    ifstream file;
    file.open(filename);
    if (file.is_open()) {
        int curByte;
        vector<int> indexRow;
        vector<int> customRow;
        bool odd = true;
        while (file) {
            /*
            
                tctctc\n

                t = index data
                c = custom data

            */
            curByte = file.get();
            if (curByte == '\n') {
                indexData.push_back(indexRow);
                customData.push_back(customRow);
                indexRow.clear();
                customRow.clear();
                odd = true;
            }
            else {
                if (odd) {
                    indexRow.push_back(curByte - 48);
                }
                else {
                    customRow.push_back(curByte - 48);
                }
                odd = !odd;
            }
        }
    }
}

void TileSet::ready(SDL_Renderer* renderer, SDL_Point& mario, vector<SDL_Point>& goombas, vector<SDL_Point>&coins) {
    for (int row = 0; row < customData.size(); row++) {
        for (int i = 0; i < customData[row].size(); i++) {
            if (customData[row][i] == 3) {
                //makes Mario
                mario.x = row * tileSize * scale;
                mario.y = i * tileSize * scale;
            }
            else if(customData[row][i] == 4) {
                //makes a Goomba
                SDL_Point p;
                p.x = row * tileSize * scale;
                p.y = i * tileSize * scale;
                goombas.push_back(p);
            }
            else if(customData[row][i] == 5) {
                // makes a Coin
                SDL_Point p;
                p.x = row * tileSize * scale;
                p.y = i * tileSize * scale;
                coins.push_back(p);
            }
        }
    }
}

void TileSet::draw(SDL_Renderer* renderer) {
    SDL_Rect rect;
    rect.h = int(tileSize * scale);
    rect.w = int(tileSize * scale);
    rect.x = 0;
    rect.y = 0;
    for(int row = 0; row < indexData.size(); row++) { 
        for(int i = 0; i < indexData[row].size(); i++) {
            if (indexData[row][i] != 0) {
                tiles[indexData[row][i] - 1].draw(renderer, &rect);
            }
            rect.x += tileSize * scale;
        }
        rect.x = 0;
        rect.y += tileSize * scale;
    }
}

void TileSet::update(double delta, SDL_Renderer* renderer) {
    if (animated) {
        frame = frame + (delta * fps);
        if (frame >= 1) {
            frame = 0;
            int* map = new int[animationLength]();
            for (int i = 0; i < animationLength; i++) {
                if (animData[i] != -1 && animData[i] != i && map[i] != 1) {
                    Sprite spr = tiles[animData[i]];
                    tiles[animData[i]] = tiles[i];
                    tiles[i] = spr;
                    map[animData[i]] = 1;
                }
            }
        }
    }
}

bool TileSet::getCollide(SDL_Rect rect) {
    /*
    takes a rect and gets the 4 tiles it overlaps on
    */
    SDL_Point p;
    p.x = int( rect.x / (scale * tileSize));
    p.y = int( rect.y / (scale * tileSize));
    for (int i = -1; i < 2; i++) {
        for(int q = -1; q < 2; q++) {
            if (indexData[p.x + i][p.y + q] != 0) {
                return true;
            }
            else if(customData[p.x + i][p.y + q] == 6) {
                customData[p.x + i][p.y + q] = 0;
            }
        }
    }

}