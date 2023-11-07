#include "Time.h"
#include "Card.h"
#include <iostream>
using namespace std;

bool equals(Card c, Card c1) {
    return c.rank == c1.rank && c.suit == c1.suit;
}

Card* build_deck() {
    Card deck[52];
    int i = 0;
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }

    srand(time(0));

    for(int i = 0; i < 52; i++) {
        int a = rand() % 52;
        Card aAt = deck[a];
        deck[a] = deck[i];
        deck[i] = aAt;
    }
}

int main() {
    /*Time time(1012313.0);
    std::cout << time.to_string() << endl;*/

}