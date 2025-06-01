#include "HandStrength.hpp"
#include <algorithm>
#include <initializer_list>

using namespace std;

vector<int> highestCard(Player* playerHands, int numPlayers) {
    vector<int> playerIndex;
    int highestCard = max(playerHands[0].card1.card % 13, playerHands[0].card2.card % 13);
    playerIndex.push_back(0);

    for(int i = 1; i < numPlayers; i++) {
        int currIndexMax = max(playerHands[i].card1.card % 13, playerHands[i].card2.card % 13);
        if (currIndexMax > highestCard) {
            playerIndex.clear();
            playerIndex.push_back(i);
            highestCard = currIndexMax;
        } else if (currIndexMax == highestCard) {
            playerIndex.push_back(i);
        }
    }

    return playerIndex;
}

vector<int> secondHighestCard(Player* playerHands, vector<int> playerIndex, int tied) {
    vector<int> maxPlayerIndex;
    int maxMinCard = min(playerHands[playerIndex.at(0)].card1.card % 13, playerHands[playerIndex.at(0)].card2.card % 13);
    maxPlayerIndex.push_back(playerIndex.at(0));

    for (int i = 1; i < tied; i++) {
        int currIndexMin = min(playerHands[i].card1.card % 13, playerHands[i].card2.card % 13);
        if (currIndexMin > maxMinCard) {
            maxPlayerIndex.clear();
            maxPlayerIndex.push_back(playerIndex.at(i));
        } else if (currIndexMin == maxMinCard) {
            maxPlayerIndex.push_back(playerIndex.at(i));
        }
    }

    return maxPlayerIndex;
}


void highCardWin(Player* playerHands, Community communityCards, int numPlayers) {
    int minimum = min({communityCards.card[0].card % 13, communityCards.card[1].card % 13, communityCards.card[2].card % 13,
                  communityCards.card[3].card % 13, communityCards.card[4].card % 13});
    vector<int> maxCard = highestCard(playerHands, numPlayers);
    if (max(playerHands[maxCard.at(0)].card1.card, playerHands[maxCard.at(0)].card2.card) < minimum) {
        cout << "The Hand Chops" << endl;
        return;
    } else if (max(playerHands[maxCard.at(0)].card1.card, playerHands[maxCard.at(0)].card2.card) > minimum) {
        if (maxCard.size() == 1) {
            cout << "Player " << maxCard.at(0) + 1 << " Wins With High Card!" << endl;
            return;
        }
    } 

    vector<int> minCard = secondHighestCard(playerHands, maxCard, maxCard.size());

    int playerHandMin = min(playerHands[minCard.at(0)].card1.card % 13, playerHands[minCard.at(0)].card2.card % 13);
    int numGreater = 0;
    for (size_t i = 0; i < communityCards.card.size(); ++i) {
        if (playerHandMin > communityCards.card[i].card % 13) {
            numGreater++;
        }
    }

    if (numGreater > 1 && minCard.size() > 1) {
        cout << "The Hand Chops Between:" << endl;
        for (size_t i = 0; i < minCard.size(); ++i) {
            cout << "Player " << minCard.at(i) + 1 << endl; 
        }
        return;
    }

    if (numGreater > 1) {
        cout << "Player " << minCard.at(0) + 1 << " Wins With High Card!" << endl;
        return;
    }

    cout << "The Hand Chops Between:" << endl;
    for (size_t i = 0; i < maxCard.size(); ++i) {
        cout << "Player " << maxCard.at(i) + 1 << endl; 
    }

    return;
}