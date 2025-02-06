#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <iostream>

class TicTacToe{
public: 
    void play();
    
private:
    void displayGame() const;
    void takeTurn();
    void resetBoard();
    void placePiece();
    bool checkWin(const char& player_char);
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool first_player_turn = true;
    char first_player_char = 'X';
    char second_player_char = 'O';
};

#endif // TICTACTOE_HPP