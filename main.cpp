#include <iostream>
#include <array>
#include <string>
#include <random>
#include <unordered_set>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Community.hpp"
#include "Generate.hpp"
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

int main() {
    int handNumber = 1;
    while (1) {
        int playerAmount;
        cout << "Welcome to Matthew's Card Room!!" << endl << "Enter Your Player Amount(2-8) or Enter 0 to Exit the Game" << endl;
        cin >> playerAmount;
        if (playerAmount == 0) break;
        if (playerAmount < 2 || playerAmount > 8) {
        cout << "Invalid Player Amount. Try Again" << endl;
        continue;
        }

        runGame(playerAmount, handNumber);
        handNumber++;
    }
    return 0;    
}