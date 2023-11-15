#include <string>
using namespace std;
struct Dinosaur {
    double weight;
    int health;
    string growlSound;
    string name;
    int strength;

    void Roar() const;
    string to_string() const;
    void Fight(Dinosaur);
    void Eat();

    Dinosaur(string, string, double, int, int);
};