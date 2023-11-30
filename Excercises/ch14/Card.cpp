#include "Card.h"
#include <string>

Card::Card() {
    rank = QUEEN; suit = HEARTS;
}
Card::Card(Suit s, Rank r) {
    this->rank = r; this->suit = s;
}
bool Card::equals(const Card& card) const {
    return card.rank == rank && card.suit == suit;
}

/*
enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
           NINE, TEN, JACK, QUEEN, KING};
*/

std::string Card::to_string() const {
    std::string out = "Card : ";
    switch (rank) {
        case ACE: out += "Ace"; break;
        case TWO: out += "Two"; break;
        case THREE: out += "Three"; break;
        case FOUR: out += "Four"; break;
        case FIVE: out += "Five"; break;
        case SIX: out += "Six"; break;
        case SEVEN: out += "Seven"; break;
        case EIGHT: out += "Eight"; break;
        case NINE: out += "Nine"; break;
        case TEN: out += "Ten"; break;
        case JACK: out += "Jack"; break;
        case QUEEN: out += "Queen"; break;
        case KING: out += "King"; break;
    }

    out += " of ";

    switch (suit) {
        case CLUBS: out += "Clubs"; break;
        case DIAMONDS: out += "Diamonds"; break;
        case HEARTS: out += "Hearts"; break;
        case SPADES: out += "Spades"; break;
    }

    return out;

}