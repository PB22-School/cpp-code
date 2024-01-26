// On linux compile with:
// g++ -std=c++17 main.cpp -o prog -lSDL2

// C++ Standard Libraries
#include <iostream>

// Third-party library
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include "AnimationPlayer.h"
#include "CharacterController.h"
#include "TileSet.h"
using namespace std;

float getDelta(Uint64 current, Uint64 previous) {
    return static_cast<float>(current - previous) / static_cast<float>(SDL_GetPerformanceFrequency());
}

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void updateGoomba(double delta, CharacterController& goomba, CharacterController& mario, TileSet* tiles) {
    SDL_Point p = goomba.getPosition();
    //goomba.place_meeting();
    goomba.update(delta,{});
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow( "Super Skrope Bros", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    
    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // SDL_Surface* screenSurface = SDL_GetWindowSurface( window );
    // SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );
    // SDL_UpdateWindowSurface( window );

    // the sprite prefix and .png suffix is done for you

    vector<string> filenames = {"blocks/questionmark","blocks/hitE","blocks/ground","blocks/2","blocks/3"};
    vector<int> animations =   {          3          ,     -1      ,       -1      ,     4    ,     0    };

    Uint64 previousTime = SDL_GetPerformanceCounter();

    TileSet tiles(filenames, animations, renderer, 1.75);
    tiles.readData("level");
    SDL_Point point;
    vector<SDL_Point> goombasP;
    vector<SDL_Point> coinsP;
    tiles.ready(renderer,point,goombasP,coinsP);

    vector<CharacterController> goombas;

    CharacterController mario({"Mario/1","Mario/2","Mario/3"},renderer, 4, point.x, point.y,5);

    for (int i = 0; i < goombasP.size(); i++) {
        SDL_Point p = goombasP[i];
        CharacterController c({"Goomba/1","Goomba/2"},renderer, 4, p.x,p.y,5);
        goombas.push_back(c);
    }

    SDL_Event e; 
    bool quit = false; 
    while( quit == false ){
        Uint64 currentTime = SDL_GetPerformanceCounter();
        float delta = getDelta(currentTime,previousTime);
        previousTime = currentTime;

        while( SDL_PollEvent( &e ) ){
            if( e.type == SDL_QUIT ) quit = true; 
        }

        tiles.update(delta,renderer);
        vector<char> c = {'n'};
        for (int i = 0; i < goombas.size(); i++) {
            updateGoomba(delta, goombas[i],mario,&tiles);
        }
        mario.update(delta,c);
        //anim.update(delta);
        
        SDL_RenderClear(renderer);

        tiles.draw(renderer);
        mario.draw(renderer);
        //anim.draw(renderer);

        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyWindow( window );
    SDL_Quit();
    IMG_Quit();
    return 0;
}