#pragma once
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Community.hpp"
#include <iostream>
#include <array>

using namespace std;

Card randomCard();
void resetSeenCards();
Card generateCard();
Player* generatePlayerHands(int numPlayers);
Community generateCommunityCards();