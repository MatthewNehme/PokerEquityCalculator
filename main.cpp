#include <iostream>
#include <array>
#include <string>
#include <random>
#include <unordered_set>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Community.hpp"
using namespace std;

// global random engine and distribution
static random_device rd;
static mt19937 gen(rd());
static uniform_int_distribution<> distr(0, 51); 

Card randomCard() {
    return Card(distr(gen)); 
}

unordered_set<Card> seenCards; // set of cards already dealt

void resetSeenCards() {
    if (!seenCards.empty()) {
        seenCards.clear();
    }
}

Card generateCard() {
    Card card;
    do {
        card = randomCard();
    } while (seenCards.find(card) != seenCards.end());
    seenCards.insert(card);
    return card;
}

vector<Player> generatePlayerHands(int numPlayers) {
    vector<Player> playerHands(numPlayers);
    Card firstCard, secondCard;
    resetSeenCards();

    for (int playerNumber = 0; playerNumber < numPlayers; playerNumber++) {
        firstCard = generateCard();
        secondCard = generateCard();
        playerHands[playerNumber] = Player(firstCard, secondCard);
    }

    return playerHands;
}

Community generateCommunityCards() {
    return Community(generateCard(), generateCard(), generateCard(), generateCard(), generateCard());
}

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