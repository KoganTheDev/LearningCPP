#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> // for initialize seed
#include <string>
#include <array>

#define MAX_COLUMN 3
#define MAX_ROW 3

struct Player {
	char mark;
	std::string turn;
};

using Players = std::array<Player&, 2>;
using GameGrid = std::vector<std::vector<char>>;

void play();
void flipCoin(Players player);
bool isEmpty(const GameGrid& grid, int row, int column);
void setMark(GameGrid& grid, int row, int column);
bool isDraw(const GameGrid& grid, int row, int column);
bool isColAndRowInRange(int maxRow, int maxCol, int row, int column);
bool doesWin(const GameGrid& grid, int row, int column);
bool horizontalLineWin(const GameGrid& grid, int col, char playerMark);
bool verticalLineWin(const GameGrid& grid, int row, char playerMark);
bool diagonalUpperLeftToLowerRightWin(const GameGrid& grid, int row, int col, char playerMark);
bool diagonalLowerLeftToUpperRight(const GameGrid& grid, int row, int col, char playerMark);


int main() {
	play();

	return 0;
}

void flipCoin(Players players) {
	int choice;

	std::srand(static_cast<unsigned int>(std::time(0))); // Seed a random number generator

	int randomNumber = std::rand() % 2; // Creates a random number which is either 0 or 1.

	std::cout << "Flipping coin.\n";
	std::cout << "Player No." << randomNumber + 1 << " You get to choose your mark:\n" <<
		"Menu:\n" << "0. Play as O.\n" << "1.Play as X.\n";
	std::cin >> choice;

	do {
		switch (choice)
		{
		case 0: // Choose O.
			players[randomNumber].mark = 'O';
			players[!randomNumber].mark = 'X'; // Other player`s mark.
			break;
		case 1: // Choose X.
			players[randomNumber].mark = 'X';
			players[!randomNumber].mark = 'O'; // Other player`s mark.
			break;
		default:
			std::cout << "Enter a valid command from the menu.\n";
			break;
		}

	} while (choice != 0 && choice != 1);

	std::cout << "Player No." << randomNumber + 1 << " Do you want to start first or second?\n" <<
		"Menu:\n" << "0. Play first.\n" << "1.Play second.\n";

	std::cin >> choice;

	do {
		switch (choice)
		{
		case 0: // Plays first.
			players[randomNumber].turn = "First";
			players[!randomNumber].turn = "Second"; // Other player`s mark.
			break;
		case 1: // Plays second.
			players[randomNumber].turn = "Second";
			players[!randomNumber].turn = "First"; // Other player`s mark.
			break;
		default:
			std::cout << "Enter a valid command from the menu.\n";
			break;
		}

	} while (choice != 0 && choice != 1);
}

bool isColAndRowInRange(int maxRow, int maxCol, int row, int column) 
{
	if (row < 0 || maxRow < row) // Row not in the right range.
	{
		return false;
	}

	if (column < 0 || maxCol < column) //  Column not in the right range.
	{ 
		return false;
	}

	return true; // In case the indices are in the range.
}

bool isEmpty(const GameGrid& grid, int row, int column) {
	{
		if (grid[row][column] == 0) // Place is empty.
		{
			return true;
		}
		return false; // Place is not empty.
	}
}

void setMark(GameGrid& grid, Player& player, int row, int column) 
{
	if (isEmpty(grid, row, column))
	{
		grid[row][column] = player.mark;
	}
	else
	{	
		throw std::runtime_error("Cannot set mark in grid[" + std::to_string(row) + "][" + std::to_string(column) + "].\n");
	}
}

bool isDraw(const GameGrid& grid, int row, int column)
{
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; grid.size(); j++) {
			if (grid[i][j] != 0) { // Meaning there`s a sqare in which there`s no element.
				return false;
			}
		}
	}

	return true; // The whole grid is full and no player`s declared as the winner.
}

bool doesWin(const GameGrid& grid, int row, int column, char playerMark)
{
	if (horizontalLineWin(grid, row, playerMark) ||
		verticalLineWin(grid, column, playerMark) ||
		diagonalUpperLeftToLowerRightWin(grid, row, column, playerMark) ||
		diagonalLowerLeftToUpperRight(grid, row, column, playerMark))
	{ // Player won
		return true;
	}

	return false; // Player didn`t win.
}

bool horizontalLineWin(const GameGrid& grid, int row, char playerMark)
{
	for (int j = 0; j < MAX_COLUMN; j++) {
		if (grid[row][j] != playerMark) {
			return false; // Found a mark on the grid`s horizontal line which is not the same as the player`s mark.
		}
	}

	return true; // There`s a horizontal line made of the player`s mark.
}

bool verticalLineWin(const GameGrid& grid, int col, char playerMark)
{
	for (int i = 0; i < MAX_ROW; i++) {
		if (grid[i][col] != playerMark) {
			return false; // Found a mark which is not the same as the player`s mark on the vertical line.
		}
	}

	return true; // The whole vertical line is made of the same mark.
}

bool diagonalUpperLeftToLowerRightWin(const GameGrid& grid, int row, int col, char playerMark) 
{
	if (row != 1 && col != 1) { // In Tic Tac Toe there`s a diagonal line form the middle.
		return false;
	}
	
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COLUMN; j++) {

			if (grid[i][j] != playerMark) {
				return false;
			}
		}
	}

	return true; // The whole diagonal line i smade of the same mark.
}

bool diagonalLowerLeftToUpperRight(const GameGrid& grid, int row, int col, char playerMark)
{
	if (row != 1 && col != 1) {
		return false; // Diagonal line is only possible in TicTacToe from the middle of the grid.
	}

	for (int i = MAX_ROW - 1; i >= 0; i--) {
		for (int j = 0; j < MAX_COLUMN; j++) {
			if (grid[i][j] != playerMark) {
				return false;
			}
		}
	}

	return true; // The whole diagonal line has the same player mark in it.
}

void play() {
	// create grid
	// create players
	// flip coin
	// grab input
	//  -- INPUT CHECK -- using function
	// check if empty
	// setMark - in try catch, catch throw if caused --> if thrown go back to grabbing input
	// check if doesWin
	// check isDraw
	// go back to grabbing input as the second player.

	

}
