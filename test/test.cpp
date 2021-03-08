#include "tic-tac-toe/tic-tac-toe.h"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
// this in one cpp file
#include <catch2/catch.hpp>

TEST_CASE("when the game starts there is no winner") {
    auto game = TicTacToe{};
    REQUIRE_FALSE(game.winner());
}

TEST_CASE("O is the first player") {
    auto game = TicTacToe{};
    REQUIRE(Player::O == game.current_player());
}

TEST_CASE("game continues after first move") {
    auto game = TicTacToe{};
    game.mark(0, 0);
    // O
    //
    //
    REQUIRE_FALSE(game.winner());
}

TEST_CASE("players take turns") {
    auto game = TicTacToe{};
    game.mark(0, 0);
    // O
    //
    //
    REQUIRE(Player::X  == game.current_player());

    game.mark(1, 0);
    // O
    // X
    //
    REQUIRE(Player::O == game.current_player());
}

TEST_CASE("game ends when a player completes a row") {
    auto game = TicTacToe{};
    game.mark(0, 0);
    game.mark(1, 0);
    game.mark(0, 1);
    game.mark(1, 1);
    // O O
    // X X
    //
    CHECK_FALSE(game.winner());

    game.mark(0, 2);
    // O O O
    // X X
    //
    REQUIRE(Player::O  == game.winner());
}
