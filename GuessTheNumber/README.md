# 🎯 Guess the Number Game 🎯

Welcome to **Guess the Number**, a simple and fun C++ console game that tests your ability to guess a randomly generated number. Sharpen your guessing skills as you try to identify the secret number within a limited number of attempts. Are you up for the challenge? 😎

---

## 📋 How It Works
1. **Pick an Upper Limit**: Choose an upper limit greater than zero for the random number range.
2. **Make a Guess**: Try to guess the random number generated within that range.
3. **Get Feedback**:
   - 🔻 **Too Low**: Your guess was lower than the secret number.
   - 🔺 **Too High**: Your guess was higher than the secret number.
4. **Win or Lose**: You have up to **five attempts** to guess correctly. If you guess right, you win! Otherwise, better luck next time!

---

## ⚙️ How to Run the Program
1. **Compile the program** using a C++ compiler:
   ```bash
   g++ -o guess_the_number guess_the_number.cpp

2. **Run the executable**:
   ```bash
   ./guess_the_number
   ```
3. **Play the game**:
   - Enter an upper limit for the random number (e.g., `10`).
   - Try to guess the number within `5` attempts.

---

## 🚀 Example Run
```
Pick an integer:
The integer must be greater than 0.
10
Pick a number between 0 to 10
5

Too high.
Wrong pick, tries left:4
3

Too low.
Wrong pick, tries left:3
7

Congratsulations, YOU WIN!
```

---

**Enjoy the game and happy guessing!** 🎉
