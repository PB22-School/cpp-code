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

void TileSet::ready(SDL_Renderer* renderer, SDL_Point& mario, vector<SDL_Point>& goombas) {
    for (int row = 0; row < customData.size(); row++) {
        for (int i = 0; i < customData[row].size(); i++) {
            if (customData[row][i] == 3) {
                //makes Mario
                mario.x = i * tileSize * scale;
                mario.y = row * tileSize * scale;
            }
            else if(customData[row][i] == 4) {
                //makes a Goomba
                SDL_Point p;
                p.x = i * tileSize * scale;
                p.y = row * tileSize * scale;
                goombas.push_back(p);
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

vector<vector<int>> TileSet::getCollide(SDL_Rect rect) {
    /*
    takes a rect and gets the 9 tiles around it
    */
    SDL_Point p;
    vector<vector<int>> v;
    vector<int> index;
    vector<int> data;
    SDL_Point br;
    br.x = rect.x + rect.w;
    br.y = rect.y + rect.h;
    p.x = int( br.x / (scale * tileSize));
    p.x = int( br.y / (scale * tileSize));
    //p.x = int(int((rect.x + rect.w) / (scale * tileSize)) + int((rect.x) / (scale * tileSize)) / 2);
    //p.x = int(int((rect.y + rect.h) / (scale * tileSize)) + int((rect.y) / (scale * tileSize)) / 2);
    //for(int z = 0; z < 1; z++) {
        /*if (z != 0) {
            p.x = int( rect.x / (scale * tileSize));
            p.y = int( rect.y / (scale * tileSize));
        }*/
    for (int i = -1; i < 2; i++) {
        // (-1,)
        for(int q = -1; q < 2; q++) {
            if (p.y + q < indexData.size() && p.x + i < indexData[0].size()) {
                //if (!z) {
                index.push_back(indexData[p.y + q][p.x + i]);
                data.push_back(customData[p.y + q][p.y + i]);
                /*}
                else {
                    if (index[(i+1)*3 + (q+1)] == 0) {
                        cout << "original : " << index[(i+1)*3 + (q+1)];
                        index[(i+1)*3 + (q+1)] = indexData[p.y + q][p.x + i];
                        cout << "altered : " << index[(i+1)*3 + (q+1)];
                    }
                }*/
            }
            else {
                index.push_back(0);
                data.push_back(0);
            }
        }
    }
    //}
    v.push_back(index);
    v.push_back(data);
    return v;
}