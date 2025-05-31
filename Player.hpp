#pragma once
#include "Card.hpp"


class Player {
    public:
        Card card1; // first card in a players hand
        Card card2; // second card in a players hand

        Player();
        Player(Card card1, Card card2);

        void printHand();
};