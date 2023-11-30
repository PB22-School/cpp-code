#include <string>
enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
           NINE, TEN, JACK, QUEEN, KING};

struct Card
{
    Rank rank;
    Suit suit;

    bool equals(const Card&) const;
    std::string to_string() const;

    Card(Suit s, Rank r);
    Card();
};
