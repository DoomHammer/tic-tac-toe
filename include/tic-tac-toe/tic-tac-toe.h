#pragma once

#include <array>
#include <iosfwd>
#include <optional>

enum class Player : char {
    None = ' ',
    O = 'O',
    X = 'X',
};

class TicTacToe {
public:
    static constexpr auto Size = 3;
    using Board = std::array<std::array<Player, Size>, Size>;

    [[nodiscard]] std::optional<Player> winner() const;

    [[nodiscard]] Player current_player() const {
        return current_;
    }

    // allows cheating, but trusts you play fair
    void mark(size_t row, size_t column);

    friend std::ostream &operator<<(std::ostream &out, const TicTacToe &game);

private:
    static Board prepare_board();

    Board board_{prepare_board()};
    Player current_ = Player::O;
};