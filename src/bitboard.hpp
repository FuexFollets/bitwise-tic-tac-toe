#pragma once

#include <iostream>
#include <cstdint>
#include <exception>

namespace tictactoe {
    struct bitboard {
        enum turn_values {
            x = 'X', y = 'Y'
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

        std::ostream& operator<<(std::ostream&, const bitboard&);
    };
}

