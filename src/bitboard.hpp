#pragma once

#include <iostream>
#include <cstdint>
#include <exception>
#include <array>

namespace tictactoe {
    struct bitboard {
        enum turn_values {
            x = 'X', y = 'Y', none = static_cast<char>(0)
        };

        const static std::array<std::uint16_t, 8> bitwise_win_checks {
            0x111'000'000,
            0x000'111'000,
            0x000'000'111,
            0x100'100'100,
            0x010'010'010,
            0x001'001'001,
            0x100'010'001,
            0x001'010'100
        };

        struct not_valid_move : std::exception {};

        /* 8 7 6
         * 5 4 3
         * 2 1 0
         */

        std::uint16_t player_x {};
        std::uint16_t player_y {};

        char turn {turn_values::x};

        bool is_valid_move(int move_square) {
            const std::uint_16 bit_position {1 << move_square};

            return 
                (player_x & bit_position == 0) &&
                (player_y & bit_position == 0);
        }

        bool make_move(int move_square) {
            if (!is_valid_move(move_square)) throw not_valid_move;

            const std::uint16_t bit_position {1 << move_square};

            switch (turn) {
                case turn_values::x:
                    player_x |= bit_position;
                    break;
                case turn_values::y:
                    player_y |= bit_position;
                    break;
            }
        }

        char winner() {
            int player_number {}; // 0 = X, 1 = O;
            for (const auto player : {player_x, player_y}) {
                for (const auto check_mask : bitwise_win_checks) {
                    if (player & check_mask == player) {
                        return (player_number == 0) ?
                            (turn_values::x) :
                            (turn_values::y);
                    }
                }

                player_number++;
            }

            return turn_values::none;
        }

        std::ostream& operator<<(std::ostream&, const bitboard&);
        void fancy_print();
    };
}

