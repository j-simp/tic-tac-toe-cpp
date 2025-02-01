#include "tictactoe.hpp"

void TicTacToe::displayGame(){
    std::cout << "\n";
    for (int i = 0; i < 9; i++){
        std::cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0){
            std::cout << "\n";
            if (i != 8){
                std::cout << "---+---+---" << "\n";
            }
        }
        else{
            std::cout << "|";
        }
    }
    std::cout << "\n";
}