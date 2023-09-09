#include "tic-tac-toe.h"

TicTacToe::TicTacToe() : board(3, vector<char>(3, ' ')) {}

#include <iomanip> // Include the header for setw

void TicTacToe::GameInterface()
{
    TicTacToe game;
    char currentPlayer = 'X';
    
    while (true) {
        int position;
        game.DisplayBoard(); // Print the actual game board
        
        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> position;
        
        if (game.playerInput(position, currentPlayer)) {
            char winner = game.checkforWin();
            if (winner != ' ') {
                game.DisplayBoard();
                cout << "Player " << winner << " wins!\n";
                game.playAgain();
                break;
            } else if (game.isBoardFull()) {
                game.DisplayBoard();
                cout << "It's a draw!\n";
                game.playAgain(); //prompts the user to play again
                break;
            }
            
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "\033[2J\033[1;1H"; //clearing screen
            TicTacToe:: typewriterEffect("\n\n\033[31mInvalid move. Try again.\n\033[0m", 100);
        }
    }

  
}

void TicTacToe::DisplayBoard() const {
  
    cout << "\033[2J\033[1;1H"; //clearing screen
    // Display the actual game board with symbols or numbers
    cout << "\n\n";
    for (int i = 0; i < 3; ++i) {
        cout << "       |       |       \n";
        for (int j = 0; j < 3; ++j) {
            cout << "   ";
            if (board[i][j] == 'X')
                cout << "\033[1;31mX\033[0m "; // Red X
            else if (board[i][j] == 'O')
                cout << "\033[1;34mO\033[0m "; // Blue O
            else
                cout << " " << i * 3 + j + 1; // Display the number
            cout << "  ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "_______|_______|_______\n";
        else cout << "       |       |       \n";
    }
    cout << "\n\n";
}


bool TicTacToe::playerInput(int position, char playerSymbol) {
    if (position < 1 || position > 9)
        return false; // Invalid position
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (board[row][col] != ' ')
        return false; // Position already taken
    board[row][col] = playerSymbol;
    return true;
}

char TicTacToe::checkforWin() const {
    // Check rows, columns, and diagonals for a win
    // Rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' '; // No winner yet
}

bool TicTacToe::isBoardFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // Found an empty cell
        }
    }
    return true; // Board is full
}

void TicTacToe::playAgain()
{
  char option;
  cout<< "Would you like to play again? (y/n): "<<endl;
  cin>> option;
  if (option =='y' || option =='Y')
  {
    GameInterface();
  }
  else if (option =='n' || option =='N')
  {
    typewriterEffect( "\nIt was fun playing with you. Goodbye!", 100 );
  }
  else
  {
    cout<<"\n\033[31mInvalid option. ";
    playAgain();
  }
  
}
void TicTacToe::typewriterEffect(const string& text, int time) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(time)); // Adjust the delay as desired
    }
}