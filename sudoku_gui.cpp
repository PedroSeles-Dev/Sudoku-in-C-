
#include <iostream>
using namespace std;
// A simple Sudoku game in C++

// Sudoku board: 0 means an empty space
int board[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Keep a copy of the original puzzle
int originalBoard[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Display the Sudoku board
void displayBoard() {
    cout << "\n";

    for (int row = 0; row < 9; row++) {

        if (row % 3 == 0) {
            cout << "-------------------------\n";
        }

        for (int col = 0; col < 9; col++) {

            if (col % 3 == 0) {
                cout << "| ";
            }

            if (board[row][col] == 0) {
                cout << ". ";
            } else {
                cout << board[row][col] << " ";
            }
        }

        cout << "|\n";
    }

    cout << "-------------------------\n";
}

// Check whether a number follows Sudoku rules
bool isValidMove(int row, int col, int number) {

    // Check the row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == number) {
            return false;
        }
    }

    // Check the column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == number) {
            return false;
        }
    }

    // Find the top-left corner of the 3x3 square
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    // Check the 3x3 square
    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (board[r][c] == number) {
                return false;
            }
        }
    }

    return true;
}

// Check whether the board is complete
bool isComplete() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int row, col, number;

    cout << "Welcome to Sudoku!\n";
    cout << "Fill the board using numbers 1 to 9.\n";
    cout << "Enter 0 as the row to quit.\n";

    while (!isComplete()) {

        displayBoard();

        cout << "\nEnter row (1-9, or 0 to quit): ";
        cin >> row;

        if (row == 0) {
            cout << "Thanks for playing!\n";
            return 0;
        }

        cout << "Enter column (1-9): ";
        cin >> col;

        cout << "Enter number (1-9): ";
        cin >> number;

        // Check that the input is within the allowed range
        if (row < 1 || row > 9 ||
            col < 1 || col > 9 ||
            number < 1 || number > 9) {

            cout << "Invalid input! Use numbers from 1 to 9.\n";
            continue;
        }

        // Convert the position to array indexes
        row--;
        col--;

        // Do not allow changes to the original numbers
        if (originalBoard[row][col] != 0) {
            cout << "You cannot change an original number!\n";
            continue;
        }

        // Check whether the move follows the rules
        if (isValidMove(row, col, number)) {
            board[row][col] = number;
            cout << "Good move!\n";
        } else {
            cout << "Invalid move! Check the row, column and square.\n";
        }
    }

    displayBoard();
    cout << "Congratulations! You completed Sudoku!\n";

    return 0;
}
// g++ -std=c++20 sudoku_gui.cpp -o sudoku_gui
// to run: ./sudoku_gui