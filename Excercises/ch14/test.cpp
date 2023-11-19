#include "Deck.h"
#include <iostream>
using namespace std;

int main() {
    Deck deck;
    Card card(SPADES,KING);
    cout << deck.find_card(card) << endl;
}