#include "Card.h"

Card::Card() {
    rank = QUEEN; suit = HEARTS;
}
Card::Card(Suit s, Rank r) {
    this->rank = r; this->suit = s;
}
bool Card::equals(const Card& card) const {
    return card.rank == rank && card.suit == suit;
}