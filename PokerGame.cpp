#include "PokerGame.hpp"

using namespace std;

void runGame(int numPlayers, int handNumber) {
    Player* playerHands = generatePlayerHands(numPlayers);
    Community theBoard = generateCommunityCards();

    cout << "Player Cards:" << endl;
    int index = 1;
    for (int i = 0; i < numPlayers; i++) {
        cout << "Player Number: " << index << endl;
        playerHands[i].printHand();
        index++;
    }

    cout << "Community Cards:" << endl;
    theBoard.printCommunityCards(); 
    
    cout << "Hand #" << handNumber << " has concluded." << endl;
    delete[] playerHands;
}