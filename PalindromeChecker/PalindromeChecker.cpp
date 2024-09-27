#include <iostream>
#include <string>
#include <vector>
#include <cctype>

/**
 * @enum MenuOption
 * @brief Enumeration representing menu options for the user.
 */
enum class MenuOption {
    STRING = 1, /**< Option for string input */
    VECTOR,     /**< Option for vector input */
    EXIT        /**< Option to exit the program */
};

/**
 * @enum VectorCommands
 * @brief Enumeration representing commands for vector operations.
 */
enum class VectorCommands {
    CONTINUE = 1, /**< Command to continue adding to the vector */
    STOP          /**< Command to stop adding to the vector */
};

/**
 * @brief Manages the menu system for the palindrome checker.
 *
 * This function displays the menu options and handles user input
 * to perform palindrome checks on strings and vectors. The program
 * continues until the user chooses to exit.
 */
void menuManager();

/**
 * @brief Converts a string to lowercase.
 *
 * @param str Reference to the string to be converted.
 */
void toLowerCase(std::string& str);

/**
 * @brief Gets user input for a string.
 *
 * Prompts the user to enter a string and converts it to lowercase.
 *
 * @return The lowercase string entered by the user.
 */
std::string getUserInput();

/**
 * @brief Gets user input for a vector of strings.
 *
 * Allows the user to input multiple strings, converting each to lowercase
 * before adding it to the vector. The user can stop adding strings based
 * on the provided menu commands.
 *
 * @return A vector containing the strings input by the user.
 */
std::vector<std::string> getUserVectorInput();

/**
 * @brief Checks if a given string is a palindrome.
 *
 * A palindrome is a string that reads the same backward as forward.
 * This function uses a recursive approach to check for palindrome properties.
 *
 * @param str The string to be checked.
 * @return True if the string is a palindrome, otherwise false.
 */
bool isPalindrome(const std::string& str);

/**
 * @brief Checks if all strings in a vector are palindromes.
 *
 * This function iterates through a vector of strings and checks each
 * string to determine if it is a palindrome.
 *
 * @param palindromeVector A vector containing strings to check.
 * @return True if all strings in the vector are palindromes, otherwise false.
 */
bool vectorPalindromeChecker(const std::vector<std::string>& palindromeVector);

/**
 * @brief Displays the current content of a vector.
 *
 * This function prints all elements in the vector in a formatted manner,
 * indicating the order of elements and using arrows to separate them.
 *
 * @param vector A vector of strings to display.
 */
void showVector(const std::vector<std::string>& vector);

int main() {
    menuManager();
    return 0;
}

bool isPalindrome(const std::string& str) {
    if (str.length() <= 1) { // str is a palindrome if its size is 0 when its initial size is even and 1 if it`s odd.
        return true;
    }
    if (str.at(0) != str.at(str.length() - 1)) { // check between the first and last characters.
        return false;
    }
    return isPalindrome(str.substr(1, str.length() - 2)); // returns the str recursively without the first and last characters.
}

bool vectorPalindromeChecker(const std::vector<std::string>& palindromeVector) {
    for (const std::string& str : palindromeVector) {
        if (!isPalindrome(str)) {
            return false;
        }
    }
    return true;
}

void menuManager() {
    int input;
    MenuOption command;
    std::string stringToCheck;
    std::vector<std::string> vectorToCheck;

    std::cout << "Palindrome Checker START." << std::endl << std::endl;

    while (true) {
        std::cout << "Menu\n1. String\n2. Vector\n3. Exit" << std::endl <<
            "Enter your choice: ";
        std::cin >> input;
        std::cin.ignore(); // Clear buffer.
        command = static_cast<MenuOption>(input); // convert from int to the different menu options.

        switch (command) {
        case MenuOption::STRING:
            stringToCheck = getUserInput();
            if (isPalindrome(stringToCheck)) {
                std::cout << "The string is a palindrome.\n";
            }
            else {
                std::cout << "The string is not a palindrome.\n";
            }
            break;
        case MenuOption::VECTOR:
            vectorToCheck = getUserVectorInput();
            if (vectorPalindromeChecker(vectorToCheck)) {
                std::cout << "The whole vector contains palindromes.\n";
            }
            else {
                std::cout << "There's an element in the vector which is not a palindrome.\n";
            }
            break;
        case MenuOption::EXIT:
            std::cout << "Goodbye!\n";
            return;
        default:
            std::cout << "Invalid command, please enter a command from the menu.\n";
            break;
        }
    }
}

std::string getUserInput() {
    std::string str;

    std::cout << "Enter the string you want to check if it's a palindrome: ";
    std::getline(std::cin, str);
    toLowerCase(str);
    return str;
}

std::vector<std::string> getUserVectorInput() {
    int input;
    VectorCommands command;
    std::string tempString;
    std::vector<std::string> vector;

    do {
        std::cout << "Insert a string you want to put in the vector: ";
        std::getline(std::cin, tempString);
        toLowerCase(tempString);
        vector.push_back(tempString);

        showVector(vector);

        std::cout << "\nMenu:\n1. Enter more elements to the vector.\n2. Stop\n";
        std::cin >> input;
        std::cin.ignore(); // Clear buffer
        command = static_cast<VectorCommands>(input);

        if (command != VectorCommands::CONTINUE && command != VectorCommands::STOP) {
            std::cout << "Please enter a valid command from the menu.\n";
        }

    } while (command != VectorCommands::STOP);

    return vector;
}

void toLowerCase(std::string& str) {
    for (char& c : str) {
        c = std::tolower(c); // Convert letter by letter to lower case.
    }
}

void showVector(const std::vector<std::string>& vector) {
    std::cout << "current vector:\n" <<
                 "---------------\n";
                 
    for (int i = 0; i < vector.size(); i++) {
        if (vector.size() == 1) { // Special case.
            std::cout << "[" << vector.at(i) << "]";
            return;
        }

        if (i == 0) { // First element.
            std::cout << "[" << vector.at(i) << "-->";
        }
        else if (i == (vector.size() - 1)) { // Last element.
            std::cout << vector.at(i) << "]\n";
        }
        else { // All of the other elements.
            std::cout << vector.at(i) << "-->";
        }
    }
}

