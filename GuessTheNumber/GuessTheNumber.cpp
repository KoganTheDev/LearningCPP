#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int randomNumber;
	int upperLimit;
	int guess;

	cout << "Pick an integer:\n" <<
			"The integer must be greater than 0.\n";
	
	cin >> upperLimit; 
	randomNumber = rand() % upperLimit;

	cout << "Pick a number between 0 to " << upperLimit << endl;

	for (int i = 5; i > 0;) {
		cin >> guess; // Insert user`s guess.
		cout << endl;

		if (guess == randomNumber) {
			cout << "Congratsulations, YOU WIN!\n";
			return 0;
		}
		else if (guess < randomNumber) {
			cout << "Too low.\n";
		}
		else if (guess > randomNumber) {
			cout << "Too high.\n";
		}

		cout << "Wrong pick, tries left:" << --i << endl;
	}

	cout << "Better luck next time :)\n";
	return 0;
}

