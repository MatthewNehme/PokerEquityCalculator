#pragma once
#include "Card.hpp"

class Community {
    public:
        std::array<Card, 5> card;
    
        Community();
        Community(Card card1, Card card2, Card card3, Card card4, Card card5);

        void printCommunityCards();
};