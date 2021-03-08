#include <algorithm>
#include <iostream>
#include <iterator>
#include <optional>
#include <ranges>

#include "tic-tac-toe/tic-tac-toe.h"
#include "utility.h"

using namespace std::ranges;

std::ostream &operator<<(std::ostream &out, const Player player) {
    return out << to_underlying(player);
}

std::ostream &operator<<(std::ostream &out, const TicTacToe::Board &board) {
    for (const auto &row : board) {
        copy(row, std::ostream_iterator<Player>(out, " "));
        out << '\n';
    }
    return out;
}

std::ostream &operator<<(std::ostream &out, const TicTacToe &game) { return out << game.board_; }

std::optional<Player> TicTacToe::winner() const {
    auto equal_to = [](Player value) {
        return [=](Player elem) { return elem == value; };
    };

    for (auto player : {Player::O, Player::X}) {

        for (const auto &row : board_) {
            if (all_of(row, equal_to(player))) return player;
        }

        for (auto column = 0; column < Size; ++column) {
            auto elements_in_column = board_ | views::transform([column](const auto &row) { return row[column]; });
            if (all_of(elements_in_column, equal_to(player))) return player;
        }

        auto diagonal_win = true;
        for (auto x = 0; x < Size; ++x) {
            if (board_[x][x] != player) {
                diagonal_win = false;
            }
        }
        if (diagonal_win) return player;

        diagonal_win = true;
        for (auto x = 0; x < Size; ++x) {
            auto y = Size - x - 1;
            if (board_[x][y] != player) {
                diagonal_win = false;
            }
        }
        if (diagonal_win) { return player; }
    }

        for (const auto &row : board_) {
            if (any_of(row, equal_to(Player::None))) { return {}; }
        }

    return Player::None;
}

void TicTacToe::mark(size_t row, size_t column) {
    board_[row][column] = current_;
    current_ = (current_ == Player::O ? Player::X : Player::O);
}

TicTacToe::Board TicTacToe::prepare_board() {
    Board board{};
    for (auto &row : board) { row.fill(Player::None); }
    return board;
}
