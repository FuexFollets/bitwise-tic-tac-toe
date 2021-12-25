#include <iostream>

class TTT {
  public:
    int board[3][3];
    int turn = 1;

    TTT(int** set_to);

    void display();
    void display(int** board);
    int** moves()
    int** moves(int** board);
    int** make_move(int y, int x, int board);
};


void TTT::display() {
  b = this->board
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      cout << *(*(b + y) + x) << " ";
    }
    cout << endl;
  }
}


void TTT::display(int** board) {
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      cout << *(*(board + y) + x) << " ";
    }
    cout << endl;
  }
}

int** moves() {
  board = this->board;
  static int ml[9][2];
  int inst = 0;
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      if (board[y][x] == 0) {
        ml[inst][0] = y; ml[inst++][1] = x;
      }
    }
  }
  return ml
}



int main() {
  
} 