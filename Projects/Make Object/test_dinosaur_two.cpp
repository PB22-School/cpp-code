#include "Dinosaur.h"
#include <iostream>
using namespace std;

int main() {
    Dinosaur Donald("Donald", "GROWL", 400, 25,100);

    Dinosaur Mert("Mert", "YAP", 300, 50, 50);

    Donald.Roar();

    Donald.Eat();

    Mert.Eat();

    Donald.Fight(Mert);
}