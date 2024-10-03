#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include <limits>

#define MAX_COLUMN 3  ///< Defines the maximum number of columns in the game grid.
#define MAX_ROW 3     ///< Defines the maximum number of rows in the game grid.

/**
 * @brief Represents a player in the game.
 */
struct Player {
    char mark;          ///< The mark ('O' or 'X') assigned to the player.
    std::string turn;   ///< The turn order ("First" or "Second") of the player.
};

// Type aliases for managing players and game grid
using Players = std::array<Player, 2>;
using GameGrid = std::vector<std::vector<char>>;

// Function Prototypes
void play();
void flipCoin(Players& players);
bool isEmpty(const GameGrid& grid, int row, int column);
void setMark(GameGrid& grid, Player& player, int row, int column);
bool isDraw(const GameGrid& grid);
bool isRowAndColumnInRange(int maxRow, int maxCol, int row, int column);
bool doesWin(const GameGrid& grid, int row, int column, char playerMark);
bool horizontalLineWin(const GameGrid& grid, int row, char playerMark);
bool verticalLineWin(const GameGrid& grid, int col, char playerMark);
bool diagonalWin(const GameGrid& grid, char playerMark);
void showGrid(const GameGrid& grid);
void clearInput(); 

int main() {
    play();
    return 0;
}

/**
 * @brief Handles the coin flip and player setup before the game starts.
 *
 * This function randomly decides which player gets to choose their mark ('O' or 'X')
 * and whether they want to play first or second.
 *
 * @param players Reference to the array of players participating in the game.
 */
void flipCoin(Players& players) {
    int choice;
    std::srand(static_cast<unsigned int>(std::time(NULL))); // Seed random number generator
    int randomNumber = std::rand() % 2; // 0 or 1, used to determine which player goes first

    std::cout << "Flipping coin...\n";
    std::cout << "Player " << randomNumber + 1 << ", you get to choose your mark:\n"
        << "0. Play as O\n"
        << "1. Play as X\n";

    // Ensure valid input for player mark choice
    while (true) {
        std::cin >> choice;
        if (std::cin.fail()) {
            clearInput();
            std::cout << "Enter a valid option (0 or 1): ";
            continue;
        }
        if (choice == 0 || choice == 1) break;
    }

    // Assign marks based on player's choice
    if (choice == 0) {
        players[randomNumber].mark = 'O';
        players[!randomNumber].mark = 'X'; // Other player gets X
    }
    else {
        players[randomNumber].mark = 'X';
        players[!randomNumber].mark = 'O'; // Other player gets O
    }

    std::cout << "Player " << randomNumber + 1 << ", do you want to play first or second?\n"
        << "0. First\n"
        << "1. Second\n";

    // Ensure valid input for player turn choice
    while (true) {
        std::cin >> choice;
        if (std::cin.fail()) {
            clearInput();
            std::cout << "Enter a valid option (0 or 1): ";
            continue;
        }
        if (choice == 0 || choice == 1) break;
    }

    // Assign turn order based on player's choice
    if (choice == 0) {
        players[randomNumber].turn = "First";
        players[!randomNumber].turn = "Second";
    }
    else {
        players[randomNumber].turn = "Second";
        players[!randomNumber].turn = "First";
    }
}

/**
 * @brief Checks if a given row and column are within valid range.
 *
 * @param maxRow Maximum number of rows in the game grid.
 * @param maxCol Maximum number of columns in the game grid.
 * @param row Row index entered by the player.
 * @param column Column index entered by the player.
 * @return true if the row and column are within the valid range; false otherwise.
 */
bool isRowAndColumnInRange(int maxRow, int maxCol, int row, int column) {
    return (row >= 1 && row <= maxRow) && (column >= 1 && column <= maxCol);
}

/**
 * @brief Checks if a cell in the grid is empty.
 *
 * @param grid The game grid.
 * @param row Row index of the cell.
 * @param column Column index of the cell.
 * @return true if the cell is empty; false otherwise.
 */
bool isEmpty(const GameGrid& grid, int row, int column) {
    return grid[row - 1][column - 1] == ' '; // Adjust for 1-based input
}

/**
 * @brief Sets the player's mark in the specified grid cell.
 *
 * @param grid The game grid.
 * @param player The player making the move.
 * @param row Row index of the cell.
 * @param column Column index of the cell.
 */
void setMark(GameGrid& grid, Player& player, int row, int column) {
    grid[row - 1][column - 1] = player.mark; // Adjust for 1-based input
}

/**
 * @brief Checks if the game is a draw (i.e., the grid is full with no winner).
 *
 * @param grid The game grid.
 * @return true if the game is a draw; false otherwise.
 */
bool isDraw(const GameGrid& grid) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

/**
 * @brief Checks if a player has won the game by achieving a line of their mark.
 *
 * @param grid The game grid.
 * @param row The row of the last move made.
 * @param column The column of the last move made.
 * @param playerMark The mark of the player ('O' or 'X').
 * @return true if the player has won; false otherwise.
 */
bool doesWin(const GameGrid& grid, int row, int column, char playerMark) {
    return horizontalLineWin(grid, row - 1, playerMark) || // Adjust for 0-based index
        verticalLineWin(grid, column - 1, playerMark) ||
        diagonalWin(grid, playerMark);
}

/**
 * @brief Checks if there is a horizontal line of the given player's mark.
 *
 * @param grid The game grid.
 * @param row The row to check.
 * @param playerMark The mark of the player ('O' or 'X').
 * @return true if there is a horizontal line; false otherwise.
 */
bool horizontalLineWin(const GameGrid& grid, int row, char playerMark) {
    for (int col = 0; col < MAX_COLUMN; col++) {
        if (grid[row][col] != playerMark) return false;
    }
    return true;
}

/**
 * @brief Checks if there is a vertical line of the given player's mark.
 *
 * @param grid The game grid.
 * @param col The column to check.
 * @param playerMark The mark of the player ('O' or 'X').
 * @return true if there is a vertical line; false otherwise.
 */
bool verticalLineWin(const GameGrid& grid, int col, char playerMark) {
    for (int row = 0; row < MAX_ROW; row++) {
        if (grid[row][col] != playerMark) return false;
    }
    return true;
}

/**
 * @brief Checks if there is a diagonal line of the given player's mark.
 *
 * @param grid The game grid.
 * @param playerMark The mark of the player ('O' or 'X').
 * @return true if there is a diagonal line; false otherwise.
 */
bool diagonalWin(const GameGrid& grid, char playerMark) {
    // Check top-left to bottom-right diagonal
    if (grid[0][0] == playerMark && grid[1][1] == playerMark && grid[2][2] == playerMark) {
        return true;
    }
    // Check bottom-left to top-right diagonal
    if (grid[2][0] == playerMark && grid[1][1] == playerMark && grid[0][2] == playerMark) {
        return true;
    }
    return false;
}

/**
 * @brief Displays the current state of the game grid.
 *
 * @param grid The game grid to display.
 */
void showGrid(const GameGrid& grid) {
    std::cout << "---------\n";
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            std::cout << grid[i][j];
            if (j < MAX_COLUMN - 1) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < MAX_ROW - 1) std::cout << "---------\n";
    }
    std::cout << "---------\n";
}

/**
 * @brief Starts and manages the main gameplay loop.
 *
 * This function initializes the game grid and players, and handles alternating turns, checking for win conditions, and determining if the game ends in a draw.
 */
void play() {
    std::cout << "Game START\n";

    GameGrid grid(MAX_ROW, std::vector<char>(MAX_COLUMN, ' ')); // Create empty grid
    Players players = { Player(), Player() };
    flipCoin(players);

    int turn = (players[0].turn == "First") ? 0 : 1;
    int row;
    int column;

    // Main game loop
    while (true) {
        showGrid(grid);
        std::cout << "Player " << (turn + 1) << " (" << players[turn].mark << "), enter your move (row and column):\n";
        
        std::cout << "Row: ";
        std::cin >> row;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Row and column must be between 1 and 3.\n";
            clearInput();
            continue;
        }

        std::cout << "Column: ";
        std::cin >> column;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Row and column must be between 1 and 3.\n";
            clearInput();
            continue;
        }

        if (!isRowAndColumnInRange(MAX_ROW, MAX_COLUMN, row, column)) {
            std::cout << "Invalid input. Row and column must be between 1 and 3.\n";
            continue;
        }

        if (!isEmpty(grid, row, column)) {
            std::cout << "Cell is already occupied. Try again.\n";
            continue;
        }

        setMark(grid, players[turn], row, column);

        if (doesWin(grid, row, column, players[turn].mark)) {
            showGrid(grid);
            std::cout << "Player " << (turn + 1) << " wins!\n";
            break;
        }

        if (isDraw(grid)) {
            showGrid(grid);
            std::cout << "It's a draw!\n";
            break;
        }

        turn = !turn; // Toggle between 0 and 1
    }

    std::cout << "Game FINISH\n";
}

/**
 * @brief Clears invalid input from the input stream.
 */
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
