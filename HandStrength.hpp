#pragma once
#include "Card.hpp"
#include "Community.hpp"
#include "Player.hpp"
#include <unordered_set>
#include <unordered_map>
#include <vector>

Community orderCommunityCards(Community communityCards);
void highCardWin(Player* playerHands, Community communityCards, int numPlayers);
std::unordered_set<int> checkPair(Player* playerHands, Community communityCards, int numPlayers);
std::vector<std::unordered_map<int, int>> createCardFrequencyTable(Player* playerHands, Community communityCards, int numPlayers);