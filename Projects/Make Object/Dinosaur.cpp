#include "Dinosaur.h"
#include <iostream>
#include <string>
using namespace std;

/*
    double weight;
    int health;
    string growlSound;
    string name;
    int strength;

    void Roar() const;
    string to_string() const;
    bool Fight(Dinosaur) const;
    void Eat();

    Dinosaur(string, string, double, int, int);
*/

Dinosaur::Dinosaur(string name, string growlSound, double weight, int strength, int health) {
    this->name = name; this->growlSound = growlSound; this->weight = weight; this->strength = strength; this->health = health;
}

void Dinosaur::Eat() {
    srand((unsigned) time(NULL));
    int r = rand() % 10;
    weight += r*5.125;
    strength += int(r*1.5);
    health += int(r*2.25);
    cout << name << " eats " << r << " plants and gains:\n" << r*5.125 << " weight\n" << int(r*1.5) << " strength\n" << int(r*2.25) << " health\n";
}

void Dinosaur::Roar() const {
    cout << name << " Lets out a roar:\n" << growlSound << endl;
}

bool Dinosaur::Fight(Dinosaur dino2) {
    while (! (dino2.health <= 0 && health <= 0)) {
        dino2.health -= strength / (dino2.weight/100);
        health -= dino2.strength / (weight/100);
    }
    if(dino2.health <= 0) {
        dino2.health = 0;
        return true;
    }
    else {
        health = 0;
        return false;
    }
}

string to_string_float(double x) {
    return std::to_string(int(x)) + '.' + std::to_string(int((x - int(x)) * 100));
}

string Dinosaur::to_string() const {
    return "Dinosaur " + name + ": Health = " + std::to_string(health) + " Weight = " + to_string_float(weight) + " Strength = " + std::to_string(strength) + " Growl Sound = " + growlSound;
}