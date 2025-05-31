#include "Card.hpp"
#include "Deck.hpp"
#include <array>

using namespace std;

Card::Card() : card(-1) {}

Card::Card(int cardNum) {
    if (cardNum >= 0) {
        this->card = cardNum; // carNum is the value of a card from 2 - 14 ex. ace = 14 + base suit values ex. club = 0, diamond = 14, heart = 28, spade = 42   
    } else {
        this->card = -1;
    };
}

void Card::printCard() {
    if (card < 0 || card >= cards.size()) {
        cout << "Invalid Card" << endl;
    } else {
        cout << cards[card] << endl;
    }
}

bool Card::operator==(const Card& other) const {
    return card == other.card;
}