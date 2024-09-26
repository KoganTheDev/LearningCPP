#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

/**
 * Summary:
 * Displays the current list of tasks with their respective indices.
 *
 * Arguments:
 * @param todoList - (const vector<string>& type): A reference to the list of tasks.
 *
 * Output:
 * Prints the task list to the console in the format: "Task No.\tTask Content".
 */
void showList(const vector<string>& todoList);

/**
 * Summary:
 * Manages the menu for the ToDo application and handles user input to perform various operations.
 *
 * Variables:
 * command - (int type): Represents the user's menu choice.
 * taskIndex - (int type): Stores the index of a task for insertion or removal operations.
 * task - (string type): Stores the user's input task.
 * userInput - (string type): Temporary storage for capturing full user input for processing.
 * todoList - (vector<string> type): The list of ToDo tasks.
 * isInputValid - (bool type): Flag indicating whether the input index and task have been parsed correctly.
 *
 * Output:
 * Prints the current state of the ToDo list and prompts the user for actions until they choose to quit.
 */
void menuManager();

/**
 * Summary:
 * Inserts a new task at the front of the ToDo list.
 *
 * Arguments:
 * @param todoList - (vector<string>& type): A reference to the list of tasks.
 * @param task - (const string& type): The task to be inserted at the front of the list.
 *
 * Variables:
 * todoList - (vector<string>& type): Modified by adding the task at the beginning.
 */
void pushFront(vector<string>& todoList, const string& task); 

/**
 * Summary:
 * Appends a new task to the end of the ToDo list.
 *
 * Arguments:
 * @param todoList - (vector<string>& type): A reference to the list of tasks.
 * @param task - (const string& type): The task to be added at the end of the list.
 *
 * Variables:
 * todoList - (vector<string>& type): Modified by adding the task at the end.
 */
void pushBack(vector<string>& todoList, const string& task);

/**
 * Summary:
 * Inserts a task at a specified index within the ToDo list.
 *
 * Arguments:
 * @param todoList - (vector<string>& type): A reference to the list of tasks.
 * @param index - (int type): The index at which the task should be inserted.
 * @param task - (const string& type): The task to be inserted.
 *
 * Output:
 * If the index is invalid, an error message is printed.
 *
 * Variables:
 * todoList - (vector<string>& type): Modified by adding the task at the specified index.
 */
void taskInsert(vector<string>& todoList, int index, const string& task);

/**
 * Summary:
 * Removes the first task from the ToDo list.
 *
 * Arguments:
 * @param todoList - (vector<string>& type): A reference to the list of tasks.
 *
 * Output:
 * Prints the removed task or an empty list message if the list is empty.
 *
 * Variables:
 * task - (string type): Stores the removed task content for display.
 */
void removeFront(vector<string>& todoList);

/**
 * Summary:
 * Removes the last task from the ToDo list.
 *
 * Arguments:
 * @param todoList - (vector<string>& type): A reference to the list of tasks.
 *
 * Output:
 * Prints the removed task or an empty list message if the list is empty.
 *
 * Variables:
 * task - (string type): Stores the removed task content for display.
 */
void removeBack(vector<string>& todoList);

/**
 * Summary:
 * Removes a task at a specified index within the ToDo list.
 *
 * Arguments:
 * @param todoList - (vector<string>& type): A reference to the list of tasks.
 * @param index - (int type): The index of the task to be removed.
 *
 * Output:
 * If the index is invalid or the list is empty, an error message is printed.
 *
 * Variables:
 * task - (string type): Stores the removed task content for display.
 */
void removeTask(vector<string>& todoList, int index);

/**
 * Summary:
 * Clears all tasks from the ToDo list.
 *
 * Arguments:
 * @param todoList - (vector<string>& type): A reference to the list of tasks.
 *
 * Output:
 * Prints a message indicating that the ToDo list has been cleared.
 *
 * Variables:
 * todoList - (vector<string>& type): Modified by removing all elements.
 */
void clearList(vector<string>& todoList);

int main() {
	menuManager();
	return 0;
}

void menuManager() {
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

		if (command == 0) { // User wants to quit.
			break;
		}

		if (command == 3) { // Insert task by index.
			while (!isInputValid) {
				cout << "Insert the index followed by the task:\n";

				getline(cin, userInput);

				// Parse user input to index and task.
				istringstream iss(userInput);
				if (iss >> taskIndex) {
					getline(iss, task); // grab the task to the task container.
					task = task.substr(1); // Remove leading space after the index.
					isInputValid = true; // Allow exiting the loop.
					taskIndex -= 1; // Convert to 0-based index.
				}
			}
			isInputValid = false; // Toggle on the flag for the next use.
		}
		else if (command == 6) {
			cout << "Insert the index of the task you want to remove.\n";
			cin >> taskIndex;
			taskIndex -= 1; // Convert to 0-based index.
		}
		else if (command == 1 || command == 2) {
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
			cout << "Please insert a valid command from the menu.\n";
			break;
		}
	}

	cout << "Goodbye!\n";
}

void showList(const vector<string>& todoList) {
	cout << "\nTask No.\t\tTask Content\n";
	cout << "--------------------------------------------\n";

	for (int i = 0; i < todoList.size(); i++) {
		cout << (i + 1) << ". " << todoList.at(i) << endl;
	}

	cout << "--------------------------------------------\n\n";
}

void pushFront(vector<string>& todoList, const string& task) {
	todoList.insert(todoList.begin(), task);
}

void pushBack(vector<string>& todoList, const string& task) {
	todoList.push_back(task);
}

void taskInsert(vector<string>& todoList, int index, const string& task) {
	if (0 > index || index > todoList.size()) {
		cout << "Invalid index, index must be a non negative number up to " <<
			todoList.size() << endl;
		return;
	}

	// Index is correct and it`s possible to insert the task.
	todoList.insert(todoList.begin() + index, task);
}

void removeFront(vector<string>& todoList) {
	if (!todoList.empty()) {
		string task = todoList.front();
		todoList.erase(todoList.begin());
		cout << endl << task << " Completed!\n";
	}
	else {
		cout << "The list is already empty!\n";
	}
}

void removeBack(vector<string>& todoList) {
	if (!todoList.empty()) {
		string task = todoList.back();
		todoList.pop_back();
		cout << endl << task << " Completed!\n";
	}
	else {
		cout << "The list is already empty!\n";
	}
}

void removeTask(vector<string>& todoList, int index) {
	if (todoList.empty()) {
		cout << "The list is empty! No task to remove.\n";
		return;
	}
	
	if (0 > index || index >= todoList.size()) {
		cout << "Invalid index, index must be a non negative number up to " << todoList.size() << endl;
		return;
	}

	string task = todoList.at(index);
	todoList.erase(todoList.begin() + index);
	cout << endl << task << " Completed!\n";
}

void clearList(vector<string>& todoList) {
	todoList.clear();
	cout << "ToDo list cleared!\n";
}