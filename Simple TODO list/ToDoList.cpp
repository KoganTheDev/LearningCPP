#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>


using namespace std;

// Utility functions.
void showList(vector<string> todoList);
void menuManger();

// Push functions
void pushFront(vector<string>& todoList, string task); 
void pushBack(vector<string>& todoList, string task);
void taskInsert(vector<string>& todoList, int index, string task);

// Pop functions.
void removeFront(vector<string>& todoList);
void removeBack(vector<string>& todoList);
void removeTask(vector<string>& todoList, int index);
void clearList(vector<string>& todoList, string task);


int main() {
	menuManger();
	return 0;
}


void menuManger() {
	int command;
	int taskIndex;
	string task;
	string userInput;
	vector<string> todoList;
	bool isInputValid = false;

	while (true) {
		cout << "current ToDo list:\n";
		showList(todoList);

		cout << "Please enter a value:\n1. pushFront\t2. pushBack\t3. Insert task by index.\n" <<
			"4. removeFront\t5. removeBack\t6. Remove task by index.\n" <<
			"7. clearList\n0. to quit.\n\n";
		cin >> command;
		cin.ignore(); // ignore leftover new line character.

		if (command == 8) { // User wants to quit.
			break;
		}

		if (command == 3 || command == 6) { // Insert or remove by index.
			while (!isInputValid) {
				cout << "Insert the index followed by the task:\n";

				getline(cin, userInput);

				// Parse user input to index and task.
				istringstream iss(userInput);
				if (iss >> taskIndex) {
					getline(iss, task); // grab the task to the task container.
					task = task.substr(1); // Remove leading space after the index.
					isInputValid = true; // Allow exiting the loop.
				}
			}
			isInputValid = false; // Toggle on the flag for the next use.
		}
		else { // Grab input without index.
			cout << "Insert a task:\n";
			getline(cin, task);
		}


		switch (command)
		{
		case 1:
			pushFront(todoList, task);
			break;
		case 2:
			pushBack(todoList, task);
			break;
		case 3:
			taskInsert(todoList, taskIndex, task);
			break;
		case 4:
			removeFront(todoList);
			break;
		case 5:
			removeBack(todoList);
			break;
		case 6:
			removeTask(todoList, taskIndex);
			break;
		case 7:
			clearList(todoList);
			break;
		default:
			cout << "Please insert a valid list from the menu.\n";
			break;
		}
	}

	cout << "Goodbye!\n";
}


void showList(vector<string> todoList) {
	cout << "Task No.\t\tTask Content\n";		

	for (int i = 0; i < todoList.size(); i++) {
		cout << (i + 1) << ". " << todoList.at(i) << endl;
	}
}


// Push functions
void pushFront(vector<string>& todoList, string task) {
	todoList.insert(todoList.begin(), task);
}


void pushBack(vector<string>& todoList, string task) {
	todoList.push_back(task);
}

void taskInsert(vector<string>& todoList, int index, string task) {
	if (0 > index || index > todoList.size()) {
		cout << "Invalid index, index must be a non negative number up to " <<
			todoList.size() << endl;
		return;
	}

	// Index is correct and it`s possible to insert the task.
	todoList.insert(todoList.begin() + index, task);
}

// Pop functions.

void removeFront(vector<string>& todoList) {
	if (!todoList.empty()) {
		string task = todoList.front();
		todoList.erase(todoList.end());

		cout << task << " Completed!\n";
	}
}


void removeBack(vector<string>& todoList) {
	string task = todoList.back();
	todoList.pop_back();

	cout << task << " Completed!\n";
}

void removeTask(vector<string>& todoList, int index) {
	if (0 > index || index > todoList.size()) {
		cout << "Invalid index, index must be a non negative number up to " << todoList.size() << endl;
		return;
	}

	string task = todoList.at(index);
	todoList.erase(todoList.begin() + index);
}

void clearList(vector<string>& todoList) {
	todoList.clear();
	cout << "ToDo list cleared!\n";
}