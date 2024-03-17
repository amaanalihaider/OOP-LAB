#include <iostream>
#include <list>
#include <string>

using namespace std;

class ToDoList {
private:
    struct Task {
        string description;
        list<Task> subTasks;

        Task(const string& desc) : description(desc) {}
    };

    list<Task> tasks;

public:
    // Method to add a new task to the list
    void addTask(const string& description) {
        tasks.push_back(Task(description));
    }

    // Method to add a sub-task to a given task index
    void addSubTask(int taskIndex, const string& subTaskDescription) {
        auto it = tasks.begin();
        advance(it, taskIndex);
        it->subTasks.push_back(Task(subTaskDescription));
    }

    // Method to display the to-do list
    void display() {
        displayTasks(tasks.begin(), 0);
    }

private:
    // Recursive method to display tasks and sub-tasks
    void displayTasks(list<Task>::iterator it, int level) {
        while (it != tasks.end()) {
            cout << string(level * 4, ' ') << "- " << it->description << endl;
            displayTasks(it->subTasks.begin(), level + 1);
            ++it;
        }
    }
};

int main() {
    ToDoList todo;

    todo.addTask("Task 1");
    todo.addSubTask(0, "Subtask 1.1");
    todo.addSubTask(0, "Subtask 1.2");

    todo.addTask("Task 2");
    todo.addSubTask(1, "Subtask 2.1");

    cout << "To-Do List:" << endl;
    todo.display();

    return 0;
}
