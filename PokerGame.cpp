#include <iostream>
#include <array>
#include <string>
#include <random>
#include <unordered_set>
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

    Card() : card(-1) {}

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

    bool operator==(const Card& other) const {
        return card == other.card;
    }
};

namespace std {
    template <>
    struct hash<Card> {
        std::size_t operator()(const Card& c) const {
            return std::hash<int>()(c.card);
        }
    };
}

class playerHand {
    public:
        Card card1; // first card in a players hand
        Card card2; // second card in a players hand

        playerHand() {
            card1 = Card();
            card2 = Card();
        }

        playerHand(Card card1, Card card2) {
            this->card1 = card1;
            this->card2 = card2;
        }

        void printHand() {
            card1.printCard();
            card2.printCard();
        }
        
};

Card* randomCard() {
    Card* randomCard = new Card(distr(gen));
    return randomCard; 
}

unordered_set<Card> seenCards; // set of cards already dealt

void resetSeenCards() {
    if (!seenCards.empty()) {
        seenCards.clear();
    }
}

vector<playerHand> generatePlayerHands(int numPlayers) {
    int playerNumber;
    vector<playerHand> playerHands(numPlayers);
    Card firstCard, secondCard;
    resetSeenCards();

    for (playerNumber = 0; playerNumber < numPlayers; playerNumber++) {
        while (1) {
            Card* ptr = randomCard();
            firstCard = *ptr;
            if (seenCards.find(firstCard) == seenCards.end()) {
                seenCards.insert(firstCard);
                delete ptr;
                break;
            } else {
                delete ptr;
                continue;
            }
        }

        while (1) {
            Card* ptr = randomCard();
            secondCard = *ptr;
            if (seenCards.find(secondCard) == seenCards.end()) {
                seenCards.insert(secondCard);
                delete ptr;
                break;
            } else {
                delete ptr;
                continue;
            }
        }
        playerHands[playerNumber] = playerHand(firstCard, secondCard);
    }

    return playerHands;
}


void runGame(int numPlayers, int handNumber) {
    vector<playerHand> playerHands = generatePlayerHands(numPlayers);

    for (auto x : playerHands) {
        x.printHand();
    }
    
    cout << "Hand #" << handNumber << " has concluded." << endl;
}

int main() {
    int handNumber = 1;
    while (1) {
        int playerAmount;
        cout << "Welcome to Matthew's Card Room!!" << endl << "Enter Your Player Amount(1-8) or Enter 0 to Exit the Game" << endl;
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