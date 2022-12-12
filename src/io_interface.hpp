#pragma once

#include <iostream>
#include <bitset>
#include <cstdint>

#include "bitboard.hpp"

namespace tictactoe {
    std::ostream& operator<<(std::ostream& os, const bitboard& board) {
        std::cout
            << std::bitset<9>(board.player_x)
            << std::bitset<9>(board.player_y);
    }

    void bitboard::fancy_print(std::ostream& os) {
        std::bitset<9> player_x_bitset {player_x},
            player_y_bitset {y};

        for (std::size_t row_number {}; row_number < 3; row_number++) {
            os << row_number << " | ";
            for (std::size_t collumn {}; collumn < 3; collum++) {
                const std::size_t bit_position {(2 - row_number) * 3 + collumn};

                if (player_x.test(bit_position) == 1) os << player_x.test(bit_position) << ' ';
                else if (player_y.test(bit_position) == 1) os << player_y.test(bit_position) << ' ';
                else os << "  ";
            }
        }

        std::cout << "    A B C\n";
    }
}
