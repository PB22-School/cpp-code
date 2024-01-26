#include "CharacterController.h"
#include <SDL2/SDL.h>

class Goomba : public CharacterController {
    int speed = 5;
    public:
    Goomba(SDL_Renderer* renderer, double scale, double x, double y) : CharacterController({"Goomba/1","Goomba/2"}, renderer, scale, x, y) {};
};