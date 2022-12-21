#pragma once

#include <iostream>
#include <cstdint>
#include <exception>
#include <array>
#include <string>
#include <cstring>

namespace tictactoe {
    struct bitboard {
        enum turn_values {
            x = 'X', y = 'Y', none = static_cast<char>(0)
        };

        static constexpr const std::array<std::uint64_t, 8> bitwise_win_checks {
            0x111'000'000,
            0x000'111'000,
            0x000'000'111,
            0x100'100'100,
            0x010'010'010,
            0x001'001'001,
            0x100'010'001,
            0x001'010'100
        };

        struct not_valid_move : std::exception {
            using std::exception::what;

            const char* what() {
                std::string std_exception_string {};

                char* exception_string {new char[std_exception_string.size()]};

                return std::strcpy(exception_string, std_exception_string.c_str());
            }
        };

        /* Bit positoins as representations on tic-tac-tow board
         * 8 7 6
         * 5 4 3
         * 2 1 0
         */

        std::uint64_t player_x {};
        std::uint64_t player_y {};

        char turn {turn_values::x};

        [[nodiscard]] bool is_valid_move(std::uint64_t move_square) const {
            const std::uint64_t bit_position {std::uint64_t {1} << move_square};

            return 
                ((player_x & bit_position) == 0) &&
                ((player_y & bit_position) == 0);
        }

        bitboard& make_move(int move_square) {
            if (!is_valid_move(move_square)) {
                throw not_valid_move {};
            }

            const std::uint64_t bit_position {std::uint64_t{1} << move_square};

            switch (turn) {
                case turn_values::x:
                    player_x |= bit_position;
                    break;
                case turn_values::y:
                    player_y |= bit_position;
                    break;
            }

            return *this;
        }

        char winner() {
            int player_number {}; // 0 = X, 1 = O;
            for (const auto player : {player_x, player_y}) {
                for (const auto check_mask : bitwise_win_checks) {
                    if ((player & check_mask) == player) {
                        return (player_number == 0) ?
                            (turn_values::x) :
                            (turn_values::y);
                    }
                }

                player_number++;
            }

            return turn_values::none;
        }

        friend std::ostream& operator<<(std::ostream&, const bitboard&);
        void fancy_print();
    };
}

