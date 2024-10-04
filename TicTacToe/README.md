# 🎮 Tic-Tac-Toe Game

Welcome to the **Tic-Tac-Toe** game! 🧩 This is a classic two-player game where you can challenge your friends or family to see who dominates the grid! Get ready for some strategic gameplay and intense fun! 😎

---

## 🌟 Game Features

- **Two Players**: Play as `X` or `O`.
- **Intelligent Coin Flip** 🎲: Randomly decide who chooses their mark and turn order!
- **Beautiful Grid Display** 📊: Watch the grid update with every move.
- **Winning Logic** 🏆: Check for horizontal, vertical, and diagonal wins.
- **Draw Detection** 🤝: Know when the game ends in a draw.
- **Input Validation** 🔍: Ensure valid moves with clear prompts!

---

## 🛠️ How to Play

1. **Run the Game**: Compile and execute the `tictactoe.cpp` file.
2. **Coin Flip** 🎲: The game will flip a coin to decide who picks their mark and turn.
3. **Make Your Move**: Players take turns entering row and column numbers to place their mark.
4. **Winning** 🏆: Create a horizontal, vertical, or diagonal line with your mark to win!
5. **Draw** 🤝: If all cells are filled and no one wins, the game ends in a draw.

---

## 🎮 Game Flow

The game starts with a **coin flip** 🎲 to decide who will choose their mark and turn order. Players then alternate turns by entering their desired row and column, and the game checks for win conditions after each move.

- **Valid Moves**: Players must enter row and column numbers between `1` and `3` (inclusive).
- **Winning**: Players need to form a straight line (horizontal, vertical, or diagonal) to win. 🏆
- **Draw**: If no player wins and all cells are filled, it's a draw! 🤝

---

## 🏆 Victory Conditions

- **Horizontal Line** ➡️: Three consecutive marks in any row.
- **Vertical Line** ⬇️: Three consecutive marks in any column.
- **Diagonal Line** 🔄: Three consecutive marks diagonally.

---

## 🖥️ Sample Output

```
Game START
---------
  |   |  
---------
  |   |  
---------
  |   |  
---------
Player 1 (X), enter your move (row and column):
Row: 1
Column: 1
```

---

## 🔧 Installation & Usage

1. **Compile** the code using `g++ -o tictactoe tictactoe.cpp`.
2. **Run** the compiled file: `./tictactoe`.

Make sure you have a C++ compiler installed (like `g++`) and you're good to go! 🚀

---

## 📢 Additional Notes

- This game uses **basic I/O operations** to manage player inputs.
- The grid and game state are displayed after each move, ensuring players always know the current game status.
- All inputs are validated to prevent out-of-range moves or attempting to mark an already filled cell. 

If you have any suggestions, feel free to reach out! Happy playing! 😄
```
