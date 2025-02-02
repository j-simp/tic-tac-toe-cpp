#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <iostream>

class TicTacToe{
public: 
    void play();
    
private:
    void displayGame();
    void resetBoard();
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool first_player_turn = true;
};

#endif // TICTACTOE_HPP