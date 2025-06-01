#include "Community.hpp"
#include <iostream>

using namespace std;

Community::Community() {
    card[0] = Card();
    card[1] = Card();
    card[2] = Card();
    card[3] = Card();
    card[4] = Card();
}

Community::Community(Card card1, Card card2, Card card3, Card card4, Card card5) {
    card[0] = card1;
    card[1] = card2;
    card[2] = card3;
    card[3] = card4;
    card[4] = card5;
}

void Community::printCommunityCards() {
    cout << "The Flop:" << endl;
    card[0].printCard();
    card[1].printCard();
    card[2].printCard();

    cout << "Turn:" << endl;
    card[3].printCard();
    
    cout << "River:" << endl;
    card[4].printCard();
}