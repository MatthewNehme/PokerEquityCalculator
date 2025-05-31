#include "Community.hpp"

using namespace std;

Community::Community() {
    card1 = Card();
    card2 = Card();
    card3 = Card();
    card4 = Card();
    card5 = Card();
}

Community::Community(Card card1, Card card2, Card card3, Card card4, Card card5) {
    this->card1 = card1;
    this->card2 = card2;
    this->card3 = card3;
    this->card4 = card4;
    this->card5 = card5;
}

void Community::printCommunityCards() {
    cout << "The Flop:" << endl;
    card1.printCard();
    card2.printCard();
    card3.printCard();

    cout << "Turn:" << endl;
    card4.printCard();
    
    cout << "River:" << endl;
    card5.printCard();
}