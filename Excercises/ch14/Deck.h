#include <vector>
#include <iostream>
#include "random.h"
#include "Card.h"
using namespace std;

struct Deck {
    vector<Card> cards;

    int find_card(const Card card) const;
    int find_lowest(int l, int h) const;
    void swap_cards(int swap1, int swap2);
    void sort();
    void print() const;
    Deck subdeck(int l, int h) const;
    Deck merge_sort() const;
    Deck merge(const Deck& d) const;
    void shuffle();

    Deck(int n);
    Deck();
};

Deck::Deck(int size)
{
    vector<Card> temp(size);
    cards = temp;
}

Deck::Deck()
{
    vector<Card> temp(52);
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = ACE; rank <= KING; rank = Rank(rank+1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

int Deck::find_card(const Card card) const
{
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i].equals(card)) return i;
    }
    return -1;
}

void Deck::swap_cards(int swap1, int swap2) {
    Card i = cards[swap1];
    cards[swap1] = cards[swap2];
    cards[swap2] = i;
}

int Deck::find_lowest(int l, int h) const {
    int max = 0;
    int x = 0;
    for (int i = l; i <= h; i++) {
        if (cards[i].rank >= max) {
            max = cards[i].rank;
            x = i;
        }
    }
    return x;
}

void Deck::sort() {
    for (int i = 0; i < cards.size() - 1; i++) {
        int c = find_lowest(i, cards.size());
        swap_cards(c,i);
    }
}

void Deck::print() const
{
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i].to_string() << endl;
    }
}

Deck Deck::subdeck(int l, int h) const
{
    Deck sub(h-l+1);

    for (int i = 0; i < sub.cards.size(); i++) {
        sub.cards[i] = cards[l+i];
    }
    return sub;
}

Deck Deck::merge(const Deck& d) const
{
    // creates a new deck big enough for all the cards
    Deck result(cards.size() + d.cards.size());

    // use index i for place in first deck, j for place in second deck
    int i = 0;
    int j = 0;

    // if this is empty, d wins, if d is empty, this wins;

    if (cards.size() == 0) {
        return d;
    }
    else if (d.cards.size() == 0) {
        return *this;
    }

    // k traverses the result deck
    for (int k = 0; k < result.cards.size(); k++) {

        // otherwise, compare the two cards on top
        // add winner to the new deck
        if (cards[i].suit > d.cards[j].suit) {
            result.cards[k] = cards[i];
            i++;
        }
        else if (cards[i].suit < d.cards[j].suit) {
            result.cards[k] = d.cards[j];
            j++;
        }
        else {
            if (rand() % 2 == 1) {
                result.cards[k] = cards[i];
                i++;
            }
            else {
                result.cards[k] = d.cards[j];
                j++;
            }
        }
    }
    return result;
}

void Deck::shuffle()
{
    for (int i = 0; i < cards.size(); i++) {
        int rand_card = random_between(0, cards.size() - 1);
        swap_cards(i, rand_card);
    }
}

Deck Deck::merge_sort() const
{
    // find the midpoint of the deck
    int midpoint = int(cards.size() / 2);

    // divide the deck into two subdecks
    Deck subdeck1 = subdeck(0, midpoint);
    Deck subdeck2 = subdeck(midpoint + 1, cards.size());
    
    // sort the subdecks using sort
    subdeck1.sort();
    subdeck2.sort();

    cout << "\n\nSPACE\n\n";

    subdeck1.print();

    cout << "\n\nSPACE\n\n";

    // merge the two halves and return the result
    return subdeck1.merge(subdeck2);
}