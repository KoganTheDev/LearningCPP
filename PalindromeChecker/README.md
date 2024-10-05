---

# 🔄 Palindrome Checker

Welcome to the **Palindrome Checker**! This C++ program allows you to check if a string or a collection of strings (stored in a vector) are palindromes. A palindrome is a word, phrase, or sequence that reads the same backward as forward. 

This program features both string and vector palindrome checking with a user-friendly interface. Let's dive in! 🚀

---

## 🌟 Features

- **String Palindrome Check**: Easily check if a single string is a palindrome.
- **Vector Palindrome Check**: Check if all strings in a vector are palindromes.
- **User Input**: Enter custom strings or a collection of strings.
- **Input Validation**: Ensures proper user commands for both strings and vectors.
- **Case Insensitive**: Automatically converts all inputs to lowercase for accurate palindrome checking.
- **Recursive Check**: Uses recursion to verify if a string is a palindrome.

---

## 🛠️ How to Use

### 1. **Running the Program**

- **Compile**: Compile the program using the following command:
  ```bash
  g++ -o palindromeChecker palindromeChecker.cpp
  ```
- **Run**: Run the compiled program:
  ```bash
  ./palindromeChecker
  ```

### 2. **Menu Options**

Once the program is running, you’ll be presented with the following menu:

```
Menu
1. String
2. Vector
3. Exit
Enter your choice:
```

- **Option 1 - String**: Check if a single string is a palindrome.
- **Option 2 - Vector**: Check if all the strings in a vector are palindromes.
- **Option 3 - Exit**: Quit the program.

---

## 🧩 How to Play

### **Option 1: String Palindrome Check**

- After selecting the "String" option, you'll be prompted to enter a string.
- The program will convert the string to lowercase and check if it’s a palindrome.
- You will see a message indicating whether or not the string is a palindrome.

### **Option 2: Vector Palindrome Check**

- After selecting the "Vector" option, you can start entering multiple strings to form a vector.
- Each string will be converted to lowercase and added to the vector.
- Once you're done entering strings, the program will check if each string is a palindrome and display the result.

---

## 🏆 Example Output

### **String Palindrome Check**
```
Menu
1. String
2. Vector
3. Exit
Enter your choice: 1
Enter the string you want to check if it's a palindrome: Radar
The string is a palindrome.
```

### **Vector Palindrome Check**
```
Menu
1. String
2. Vector
3. Exit
Enter your choice: 2
Insert a string you want to put in the vector: Racecar
current vector:
---------------
[Racecar]
Insert a string you want to put in the vector: Level
current vector:
---------------
[Racecar-->Level]
Menu:
1. Enter more elements to the vector.
2. Stop
2
The vector is a palindrome.
```

---

## 📦 Installation & Setup

1. Ensure you have a C++ compiler (like `g++`) installed on your system.
2. Compile the program:
   ```bash
   g++ -o palindromeChecker palindromeChecker.cpp
   ```
3. Run the program:
   ```bash
   ./palindromeChecker
   ```

---

## 🔍 Additional Information

- **Recursive Palindrome Check**: This program uses a recursive approach to check if a string is a palindrome.
- **Case Insensitive**: Strings are automatically converted to lowercase to avoid case mismatches.
- **Menu Commands**: Input is validated to ensure the user enters valid commands.

Feel free to contribute or report any issues! 😊

---

## 📧 Contact

If you have any questions or suggestions, feel free to reach out!

Enjoy using the Palindrome Checker! 🎉
