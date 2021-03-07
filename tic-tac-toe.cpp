#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <optional>
#include <ranges>

#if __cpp_lib_to_underlying
using std::to_underlying;
#else
template<class Enum>
constexpr auto to_underlying(Enum e) noexcept {
    return static_cast<std::underlying_type_t<Enum>>(e);
}
#endif

using namespace std::ranges;

enum class Player : char {
    None = ' ',
    O = 'O',
    X = 'X',
};

class TicTacToe {
public:
    static constexpr auto Size = 3;
    using Board = std::array<std::array<Player, Size>, Size>;

    [[nodiscard]] std::optional<Player> winner() const {
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

    [[nodiscard]] Player current_player() const {
        return current_;
    }

    // allows cheating, but trusts you play fair
    void mark(size_t row, size_t column) {
        board_[row][column] = current_;
        current_ = (current_ == Player::O ? Player::X : Player::O);
    }

    friend std::ostream &operator<<(std::ostream &out, const TicTacToe &game);

private:
    static Board prepare_board() {
        Board board{};
        for (auto &row : board) { row.fill(Player::None); }
        return board;
    }

    Board board_{prepare_board()};
    Player current_ = Player::O;
};

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
