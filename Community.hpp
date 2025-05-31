#pragma once
#include "Card.hpp"

class Community {
    public:
        Card card1;
        Card card2;
        Card card3;
        Card card4;
        Card card5;

        Community();
        Community(Card card1, Card card2, Card card3, Card card4, Card card5);

        void printCommunityCards();
};