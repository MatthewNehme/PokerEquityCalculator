#include <iostream>
#include <array>
#include <string>
#include <random>
using namespace std;

// global random engine and distribution
static random_device rd;
static mt19937 gen(rd());
static uniform_int_distribution<> distr(0, 51);

array<string, 52> cards = {
    "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "10c", "Jc", "Qc", "Kc", "Ac",
    "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "10d", "Jd", "Qd", "Kd", "Ad",
    "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "10h", "Jh", "Qh", "Kh", "Ah",
    "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "10s", "Js", "Qs", "Ks", "As"
}; 

class Card {
    public:
    int card;
    Card(int cardNum) {
        if (cardNum >= 0) {
            this->card = cardNum; // carNum is the value of a card from 2 - 14 ex. ace = 14 + base suit values ex. club = 0, diamond = 14, heart = 28, spade = 42   
        } else {
            this->card = -1;
        };
    }
    
    void printCard() {
        if (card < 0 || card >= cards.size()) {
            cout << "Invalid Card" << endl;
        } else {
            cout << cards[card] << endl;
        }
    }
};

class playerHand {
    public:
        Card card1; // first card in a players hand
        Card card2; // second card in a players hand
};

Card* randomCard() {
    Card* randomHand = new Card(distr(gen));
    return randomHand; 
}


void runGame(int numPlayers) {
    if (numPlayers < 2 || numPlayers > 8) {
        cout << "Invalid Player Ammount." << endl;
        return;
    }
    cout << "Game was ran" << endl;
}

int main() {
    Card* testHand2 = randomCard();
    testHand2->printCard();
    delete testHand2;
    return 0;    
}