#include "PokerGame.hpp"

using namespace std;

void printFrequencyTable(const std::vector<std::unordered_map<int, int>>& freqTable) {
    for (size_t playerIdx = 0; playerIdx < freqTable.size(); ++playerIdx) {
        std::cout << "Player " << playerIdx << " frequency table:\n";
        for (const auto& [cardRank, count] : freqTable[playerIdx]) {
            std::cout << "  Card rank " << cardRank << " -> Count: " << count << '\n';
        }
        std::cout << "--------------------------\n";
    }
}


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

    theBoard = orderCommunityCards(theBoard);
    vector<unordered_map<int, int>> frequencyTable = createCardFrequencyTable(playerHands, theBoard, numPlayers);
    printFrequencyTable(frequencyTable);
    unordered_set<int> pairIndex = checkPair(frequencyTable, numPlayers);
    // for (auto x : pairIndex) {
    //      cout << x << endl;
    // }

    findBestHand(frequencyTable, pairIndex, playerHands, theBoard, numPlayers);
    
    // highCardWin(playerHands, theBoard, numPlayers);    
    cout << "Hand #" << handNumber << " has concluded." << endl;
    delete[] playerHands;
}