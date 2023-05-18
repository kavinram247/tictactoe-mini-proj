#include <iostream>
using namespace std;

class TicTacToe {
    private:
        char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        char player = 'X';

        void drawBoard() {
            cout << "Tic Tac Toe\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }

        void getPlayerMove() {
            int x, y;
            cout << "Player " << player << ", enter your move (row [1-3] column [1-3]): ";
            cin >> x >> y;
            x--;
            y--;
            if (board[x][y] == 'X' || board[x][y] == 'O') {
                cout << "That square is already taken. Try again.\n";
                getPlayerMove();
            } else {
                board[x][y] = player;
            }
        }

        bool checkForWin() {
            // Check rows
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                    return true;
                }
            }
            // Check columns
            for (int j = 0; j < 3; j++) {
                if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                    return true;
                }
            }
            // Check diagonals
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                return true;
            }
            if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                return true;
            }
            return false;
        }

        bool checkForTie() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] != 'X' && board[i][j] != 'O') {
                        return false;
                    }
                }
            }
            return true;
        }

        void switchPlayer() {
            if (player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }
        }

    public:
        void play() {
            drawBoard();
            while (!checkForWin() && !checkForTie()) {
                getPlayerMove();
                drawBoard();
                switchPlayer();
            }
            if (checkForWin()) {
                switchPlayer();
                cout << "Player " << player << " wins!\n";
            } else {
                cout << "Tie game!\n";
            }
        }
};

int main() {
TicTacToe game;
    game.play();
    return 0;
}