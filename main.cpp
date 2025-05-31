#include <iostream>
#include "PokerGame.hpp"

using namespace std;

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