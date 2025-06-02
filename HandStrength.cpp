#include "HandStrength.hpp"
#include <algorithm>
#include <initializer_list>

using namespace std;

Community orderCommunityCards(Community communityCards) {
    for (int i = 0; i < 5; i++) {
        int j = i;
        while (j > 0 && (communityCards.card[j - 1].card % 13) > (communityCards.card[j].card % 13)) {
            int temp = communityCards.card[j - 1].card;
            communityCards.card[j - 1].card = communityCards.card[j].card;
            communityCards.card[j].card = temp;
            j--;
        }
    }

    return communityCards;
}

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
    Community sortedCommunityCards = orderCommunityCards(communityCards);
    vector<int> maxCard = highestCard(playerHands, numPlayers);
    if (max(playerHands[maxCard.at(0)].card1.card, playerHands[maxCard.at(0)].card2.card) < sortedCommunityCards.card[0].card) {
        cout << "The Hand Chops" << endl;
        return;
    } else if (max(playerHands[maxCard.at(0)].card1.card, playerHands[maxCard.at(0)].card2.card) > sortedCommunityCards.card[0].card) {
        if (maxCard.size() == 1) {
            cout << "Player " << maxCard.at(0) + 1 << " Wins With High Card!" << endl;
            return;
        }
    } 

    vector<int> minCard = secondHighestCard(playerHands, maxCard, maxCard.size());
    int playerHandMin = min(playerHands[minCard.at(0)].card1.card % 13, playerHands[minCard.at(0)].card2.card % 13);
    bool relevant = (playerHandMin > sortedCommunityCards.card[0].card && playerHandMin > sortedCommunityCards.card[1].card);

    if (relevant && minCard.size() > 1) {
        cout << "The Hand Chops Between:" << endl;
        for (size_t i = 0; i < minCard.size(); ++i) {
            cout << "Player " << minCard.at(i) + 1 << endl; 
        }
        return;
    }

    if (relevant) {
        cout << "Player " << minCard.at(0) + 1 << " Wins With High Card!" << endl;
        return;
    }

    cout << "The Hand Chops Between:" << endl;
    for (size_t i = 0; i < maxCard.size(); ++i) {
        cout << "Player " << maxCard.at(i) + 1 << endl; 
    }

    return;
}

bool hasPocketPair(Player playerHand) {
    return playerHand.card1.card % 13 == playerHand.card2.card % 13;
}

array<int, 5> communityCardArray(Community communityCards) {
    array<int, 5> communityArray;
    for (int i = 0 ; i < 5; i++) {
        communityArray[i] = communityCards.card[i].card % 13;
    }
    return communityArray;
}

vector<unordered_map<int, int>> createCardFrequencyTable(Player* playerHands, Community communityCards, int numPlayers) {
    vector<unordered_map<int, int>> cardFrequencyTable;
    cardFrequencyTable.resize(numPlayers);
    array<int, 5> communityArray = communityCardArray(communityCards);

    for (int i = 0; i < numPlayers; ++i) {
        unordered_map<int, int> playerFrequencyTable;
        playerFrequencyTable.reserve(7);

        for (int card : communityArray) {
            ++playerFrequencyTable[card];
        }

        ++playerFrequencyTable[playerHands[i].card1.card % 13];
        ++playerFrequencyTable[playerHands[i].card2.card % 13];
        cardFrequencyTable[i] = playerFrequencyTable;  
    }

    return cardFrequencyTable;
}

unordered_set<int> checkPair(Player* playerHands, Community communityCards, int numPlayers) {
    unordered_set<int> pairIndex;
    for (int i = 0; i < numPlayers; i++) {
        if (hasPocketPair(playerHands[i])) {
            pairIndex.insert(i);
        } else {
            int actualValue1 = playerHands[i].card1.card % 13;
            int actualValue2 = playerHands[i].card2.card % 13;
            int actualValue3 = communityCards.card[0].card % 13;
            int j = 0;
            while (actualValue1 >= actualValue3 || actualValue2 >= actualValue3) {
                if (actualValue1 == actualValue3 || actualValue2 == actualValue3) {
                    pairIndex.insert(i);
                    break;
                }

                ++j;
                if (j == 5) break;
                actualValue3 = communityCards.card[j].card % 13;
            }
        }
    }

    return pairIndex;
}

unordered_set<int> checkFullHouse(Player* playerHands, Community communityCards, unordered_set<int> pairIndex) {
    unordered_set<int> fullHouseHands = pairIndex;

    return fullHouseHands;
}