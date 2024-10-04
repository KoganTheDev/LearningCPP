# 🧮 Basic Calculator in C++ 🧮

Welcome to **Basic Calculator**, a simple yet powerful C++ console program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division. With a user-friendly interface, you can perform operations on two numbers with ease. Let's dive into the details!

---

## ✨ Features
- Supports four arithmetic operations:
  - ➕ **Addition** (`+`)
  - ➖ **Subtraction** (`-`)
  - ✖️ **Multiplication** (`*`)
  - ➗ **Division** (`/`)
- **Error handling** for division by zero.
- Clean and structured function-based implementation.

---

## 📋 How to Use the Calculator
1. **Enter your equation**: Type in two numbers and an operator with spaces in between.
   - Example: `5 + 3`
2. **Supported operators**:
   - `+` for addition.
   - `-` for subtraction.
   - `*` for multiplication.
   - `/` for division.
3. **Receive the result** of the equation in a formatted output.

### 🛑 Important Notes
- Ensure that the operator is valid; otherwise, the program will notify you with an error message.
- The program does not support multiple operations in a single line (e.g., `5 + 3 - 2`). Enter one operation at a time.

---

## ⚙️ How to Compile and Run
1. **Compile the program** using a C++ compiler:
   ```bash
   g++ -o basic_calculator basic_calculator.cpp
   ```
2. **Run the executable**:
   ```bash
   ./basic_calculator
   ```
3. **Follow the instructions** displayed on the console to perform calculations.

---

## 💻 Example Run
```
Welcome to the Basic-Calculator:
Insert an equation that contains 2 numbers and an operator.
Make sure to insert space between each element.
e.g:
+ for addition.
- for substraction.
* for multiplication.
/ for division.

5 * 4

5.00 * 4.00 = 20.00
```

---

### 💡 Additional Tips
- **Input Validation**: While the program handles division by zero, additional validation checks for valid numbers and operators can improve robustness.
- **Enhancements**: Consider extending the program to support more complex calculations, such as exponentiation or modulus operations.

---

**Happy calculating!** 🧮✨
