/*
    ===========================================
     CONSOLE TO-DO LIST MANAGER  (Version B)
    ===========================================
    Features:
      - Add Task
      - View Tasks (with status: Pending / Completed)
      - Mark Task as Completed
      - Remove Task
      - Persistent storage using file handling (tasks.txt)
      - Clean, menu-driven UI

    Author : Ananya
    Language: C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

const string FILE_NAME = "tasks.txt";

// ---------- Task Structure ----------
struct Task {
    string description;
    bool isCompleted;
};

// ---------- Function Prototypes ----------
void loadTasksFromFile(vector<Task> &tasks);
void saveTasksToFile(const vector<Task> &tasks);
void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks);
void removeTask(vector<Task> &tasks);
void showMenu();
void clearInputBuffer();
void printHeader(const string &title);

// ---------- Main ----------
int main() {
    vector<Task> tasks;
    loadTasksFromFile(tasks);

    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            cout << "\nInvalid input! Please enter a number.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                saveTasksToFile(tasks);
                cout << "\nTasks saved. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select 1-5.\n";
        }
        cout << endl;

    } while (choice != 5);

    return 0;
}

// ---------- Show Menu ----------
void showMenu() {
    printHeader("TO-DO LIST MANAGER");
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Save & Exit\n";
    cout << "----------------------------------\n";
}

// ---------- Print Header ----------
void printHeader(const string &title) {
    cout << "\n====================================\n";
    cout << "        " << title << "\n";
    cout << "====================================\n";
}

// ---------- Add Task ----------
void addTask(vector<Task> &tasks) {
    clearInputBuffer();
    string desc;
    cout << "\nEnter task description: ";
    getline(cin, desc);

    if (desc.empty()) {
        cout << "Task description cannot be empty!\n";
        return;
    }

    Task newTask;
    newTask.description = desc;
    newTask.isCompleted = false;

    tasks.push_back(newTask);
    saveTasksToFile(tasks);

    cout << "Task added successfully!\n";
}

// ---------- View Tasks ----------
void viewTasks(const vector<Task> &tasks) {
    printHeader("YOUR TASKS");

    if (tasks.empty()) {
        cout << "No tasks found. Add one!\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". [" 
             << (tasks[i].isCompleted ? "Completed" : "Pending  ") 
             << "] " << tasks[i].description << "\n";
    }
}

// ---------- Mark Task as Completed ----------
void markTaskCompleted(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available to update.\n";
        return;
    }

    viewTasks(tasks);
    int index;
    cout << "\nEnter task number to mark as completed: ";
    cin >> index;

    if (cin.fail() || index < 1 || index > (int)tasks.size()) {
        cin.clear();
        clearInputBuffer();
        cout << "Invalid task number!\n";
        return;
    }

    tasks[index - 1].isCompleted = true;
    saveTasksToFile(tasks);
    cout << "Task marked as completed!\n";
}

// ---------- Remove Task ----------
void removeTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available to remove.\n";
        return;
    }

    viewTasks(tasks);
    int index;
    cout << "\nEnter task number to remove: ";
    cin >> index;

    if (cin.fail() || index < 1 || index > (int)tasks.size()) {
        cin.clear();
        clearInputBuffer();
        cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + (index - 1));
    saveTasksToFile(tasks);
    cout << "Task removed successfully!\n";
}

// ---------- Load Tasks From File ----------
void loadTasksFromFile(vector<Task> &tasks) {
    ifstream inFile(FILE_NAME);
    if (!inFile) return; // file doesn't exist yet, skip

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        // Format: status|description
        size_t sep = line.find('|');
        if (sep == string::npos) continue;

        Task t;
        t.isCompleted = (line.substr(0, sep) == "1");
        t.description = line.substr(sep + 1);
        tasks.push_back(t);
    }
    inFile.close();
}

// ---------- Save Tasks To File ----------
void saveTasksToFile(const vector<Task> &tasks) {
    ofstream outFile(FILE_NAME);
    for (const auto &t : tasks) {
        outFile << (t.isCompleted ? "1" : "0") << "|" << t.description << "\n";
    }
    outFile.close();
}

// ---------- Clear Input Buffer ----------
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}