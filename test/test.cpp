#include "tic-tac-toe/tic-tac-toe.h"

#include <cassert>

#ifdef NDEBUG
#undef NDEBUG
#include <cassert>
#define NDEBUG
#endif

int main() {
    auto game = TicTacToe{};
    assert(!game.winner());
    assert(game.current_player() == Player::O);

    game.mark(0, 0);
    // O
    //
    //
    assert(!game.winner());
    assert(game.current_player() == Player::X);

    game.mark(1, 0);
    // O
    // X
    //
    assert(game.current_player() == Player::O);

    game.mark(0, 1);
    game.mark(1, 1);
    // O O
    // X X
    //
    assert(!game.winner());

    game.mark(0, 2);
    // O O O
    // X X
    //
    assert(game.winner() == Player::O);
}