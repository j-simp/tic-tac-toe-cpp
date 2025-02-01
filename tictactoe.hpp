#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <iostream>

class TicTacToe{
public:   
    void displayGame();
    
private:
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};

#endif // TICTACTOE_HPP