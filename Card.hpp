#pragma once
#include "Deck.hpp"
#include <iostream>
#include <functional>
#include <array>

class Card {
    public:
        int card;

        Card();
        Card(int cardNum);
        void printCard();
        bool operator==(const Card& other) const;
};

namespace std{
    template<>
    struct hash<Card> {
        std::size_t operator()(const Card& c) const {
            return std::hash<int>()(c.card);
        }
    };
}