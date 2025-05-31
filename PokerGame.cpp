#include "PokerGame.hpp"

using namespace std;

void runGame(int numPlayers, int handNumber) {
    vector<Player> playerHands = generatePlayerHands(numPlayers);
    Community theBoard = generateCommunityCards();

    cout << "Player Cards:" << endl;
    int index = 1;
    for (auto x : playerHands) {
        cout << "Player Number: " << index << endl;
        x.printHand();
        index++;
    }

    cout << "Community Cards:" << endl;
    theBoard.printCommunityCards(); 
    
    cout << "Hand #" << handNumber << " has concluded." << endl;
}