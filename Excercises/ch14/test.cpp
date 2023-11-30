#include "Deck.h"
#include <iostream>
using namespace std;

int main() {
   Deck deck;
   deck.shuffle();
   deck = deck.merge_sort();
   cout << "\n\nSPACE\n\n";
   deck.print();
}