# 📝 ToDo List Application in C++

Welcome to the **ToDo List Application** – a simple and effective task management tool built using C++. Whether you're organizing your daily chores, work tasks, or anything in between, this application has you covered with easy-to-use, console-based commands!

---

## 🚀 Features

- **Add Tasks**:  
  Easily add tasks to the beginning or end of your ToDo list.
  
- **Insert by Index**:  
  Want to prioritize something? Insert tasks at any specific position.

- **Remove Tasks**:  
  Remove tasks from the front, back, or any specific index of your list.

- **Clear the List**:  
  Start fresh at any time by clearing the entire list with one command.

- **Friendly Menu System**:  
  Simple menu options for smooth user interaction and task management.

---

## 📋 How to Use

### 1. Run the Program:
After compiling the program, the application will display your current task list and guide you with a menu for easy navigation.

### 2. Menu Options:
You will be prompted with a list of available commands to manage your tasks:

```
1. pushFront  -> Add task to the beginning
2. pushBack   -> Add task to the end
3. Insert by index -> Insert task at a specific position
4. removeFront -> Remove the first task
5. removeBack  -> Remove the last task
6. Remove by index -> Remove a task at a specific index
7. clearList   -> Clear all tasks
0. to quit     -> Exit the program
```

### 3. Example Walkthrough:
```
current ToDo list:
Task No.       Task Content
--------------------------------------------
1. Buy groceries
2. Finish C++ project
--------------------------------------------

Please enter a value:
1. pushFront  2. pushBack  3. Insert task by index
4. removeFront  5. removeBack  6. Remove task by index
7. clearList
0. to quit.

Insert a task:
> Water the plants

current ToDo list:
Task No.       Task Content
--------------------------------------------
1. Water the plants
2. Buy groceries
3. Finish C++ project
--------------------------------------------
```

### 4. Exiting:
When you're done managing your tasks, simply input `0` to quit, and the program will say goodbye.

---

## 🔧 Installation & Setup

### 1. Clone the Repository:
```bash
git clone https://github.com/your-username/todo-list-app.git
```

### 2. Compile the Program:
In your terminal, compile the C++ source file using `g++`:

- **Linux/Mac**:
    ```bash
    g++ -o todo todo.cpp
    ```
  
- **Windows**:
    ```bash
    g++ -o todo.exe todo.cpp
    ```

### 3. Run the Program:
- **Linux/Mac**:
    ```bash
    ./todo
    ```
  
- **Windows**:
    ```bash
    todo.exe
    ```

---

## 📚 Example Output

```bash
current ToDo list:
Task No.       Task Content
--------------------------------------------
1. Buy groceries
2. Finish C++ project
--------------------------------------------

Please enter a value:
1. pushFront  2. pushBack  3. Insert task by index
4. removeFront  5. removeBack  6. Remove task by index
7. clearList
0. to quit.

Insert a task:
> Water the plants

current ToDo list:
Task No.       Task Content
--------------------------------------------
1. Water the plants
2. Buy groceries
3. Finish C++ project
--------------------------------------------
```

---

**Enjoy managing your tasks!**  
✌️ 
