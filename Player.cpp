#include "Player.hpp"

Player::Player() {
    card1 = Card();
    card2 = Card();
}

Player::Player(Card card1, Card card2) {
    this->card1 = card1;
    this->card2 = card2;
}

void Player::printHand() {
    card1.printCard();
    card2.printCard();
}



