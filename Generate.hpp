#pragma once
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Community.hpp"
#include <iostream>

using namespace std;

Card randomCard();
void resetSeenCards();
Card generateCard();
vector<Player> generatePlayerHands(int numPlayers);
Community generateCommunityCards();