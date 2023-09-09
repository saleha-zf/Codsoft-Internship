#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

class TicTacToe {
public:
    TicTacToe();
    static void GameInterface();
    void DisplayBoard() const;
    bool playerInput(int position, char playerSymbol);
    char checkforWin() const;
    bool isBoardFull() const;
    static void typewriterEffect(const string& text, int time);
    void playAgain();
private:
    vector<vector<char>> board;
};

#endif
