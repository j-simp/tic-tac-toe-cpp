#include "tictactoe.hpp"

#include <chrono>
#include <thread>

void TicTacToe::play(){
    bool win = false;
    std::cout << "\nWelcome to TicTacToe!\n"
    << "Player 1 will use 'X' and Player 2 will use 'O'.\n";
    while (true){
        for (int i = 0; i < 9; i++){
            placePiece();
            win = checkWin(first_player_turn ? first_player_char : second_player_char);
            first_player_turn = !first_player_turn;
            if (win){
                break;
            }
        }
        displayGame();
        if (win){
            std::cout << (!first_player_turn ? "Player 1 wins!!!" : "Player 2 Wins!!!") << "\n";
        }else{
            std::cout << "It's a draw!!!" << "\n";
        }
        char response;
        while (true){
            std::cout << "Would you like to play again? (y/n): ";
            std::cin >> response;
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter either 'y' or 'n'!\n\n";
            }else if (response != 'y' && response != 'n'){
                std::cout << "Invalid input. Please enter either 'y' or 'n'!\n\n";
            }else{
                break;
            }
        }
        if (response == 'y'){
            resetBoard();
        }else{
            std::cout << "Thanks for playing!";
            return;
        }
    }
}   


bool TicTacToe::checkWin(const char& player_char){
    int win_patterns[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}};

    for (int i = 0; i < 8; i++){
        if (board[win_patterns[i][0]] == player_char &&
            board[win_patterns[i][1]] == player_char &&
            board[win_patterns[i][2]] == player_char){
                return true;
        }
    }
    return false;
}

void TicTacToe::displayGame() const{
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

void TicTacToe::placePiece(){
    int input_num;
    while (true){
        displayGame();
        std::cout << "Player " << (first_player_turn ? "1's " : "2's ") << "turn!\n"
        << "Enter a number (1-9) to place your piece: ";
        std::cin >> input_num;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number from 1 to 9!\n\n";
        }else if ((input_num < 1) || (input_num > 9)){
            std::cout << "Please enter a number from 1 to 9!\n\n";
        }else if (input_num != board[input_num - 1] - '0'){
            std::cout << static_cast<int>(board[input_num - 1]) << "\n\n";
            std::cout << "Please choose an empty spot on the board!\n\n";
        }
        else{
            board[input_num - 1] = first_player_turn ? 'X' : 'O';
            return;
        }
    }
}

void TicTacToe::resetBoard(){
    for (int i = 0; i < 9; i++){
        board[i] = i + '1';
    }
}