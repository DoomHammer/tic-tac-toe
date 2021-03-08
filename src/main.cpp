#include <iostream>
#include <string>

#include "tic-tac-toe/tic-tac-toe.h"
#include "utility.h"

std::size_t read_an_index() {
    while (true) {
        std::size_t index;
        std::cin >> index;
        if (std::cin.good()) {
            return index;
        }

        std::cin.clear();
        std::string garbage;
        std::cin >> garbage;
        std::cout << "Whoops, I don't think " << garbage << " is a number. Try again:";
    }
}


int main() {
    auto game = TicTacToe{};

    while (!game.winner()) {
        auto current_player = game.current_player();
        std::cout << "Player '" << to_underlying(current_player) << "', what row and column is your next move? ";

        std::size_t row = read_an_index();
        std::size_t column = read_an_index();

        if (row >= TicTacToe::Size || column >= TicTacToe::Size) {
            std::cout << "Holy moly! Can't find that one on the board... ";
            continue;
        }

        game.mark(row, column);
        std::cout << game;
    }

    if (auto winner = game.winner(); *winner == Player::None) {
        std::cout << "Game ended in a draw" << std::endl;
    } else {
        std::cout << "The " << to_underlying(*winner) << "'s won!" << std::endl;
    }
}
