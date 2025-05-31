#include "Generate.hpp"
#include <unordered_set>
#include <random>

using namespace std;

// global random engine and distribution
static random_device rd;
static mt19937 gen(rd());
static uniform_int_distribution<> distr(0, 51); 

// set of cards already dealt
unordered_set<Card> seenCards;

Card randomCard() {
    return Card(distr(gen));
}

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

vector<Player> generatePlayerHands(int numPlayers) { // note:   change this from vector to array cause array faster :)
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