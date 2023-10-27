#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string task;
    string status;
};

vector<Task> tasks;

void add_task() {
    Task new_task;
    cout << "Enter the task: ";
    getline(cin, new_task.task);
    new_task.status = "pending";
    tasks.push_back(new_task);
    cout << "Task added successfully!" << endl;
}

void view_tasks() {
    if (tasks.empty()) {
        cout << "No tasks found!" << endl;
    } else {
        for (int i = 0; i < tasks.size(); i++) {
            cout << i+1 << ". " << tasks[i].task << " (" << tasks[i].status << ")" << endl;
        }
    }
}

void mark_task_as_completed() {
    if (tasks.empty()) {
        cout << "No tasks found!" << endl;
    } else {
        view_tasks();
        int task_index;
        cout << "Enter the task number to mark as completed: ";
        cin >> task_index;
        if (task_index < 1 || task_index > tasks.size()) {
            cout << "Invalid task number!" << endl;
        } else {
            tasks[task_index-1].status = "completed";
            cout << "Task marked as completed successfully!" << endl;
        }
    }
}

void remove_task() {
    if (tasks.empty()) {
        cout << "No tasks found!" << endl;
    } else {
        view_tasks();
        int task_index;
        cout << "Enter the task number to remove: ";
        cin >> task_index;
        if (task_index < 1 || task_index > tasks.size()) {
            cout << "Invalid task number!" << endl;
        } else {
            tasks.erase(tasks.begin()+task_index-1);
            cout << "Task removed successfully!" << endl;
        }
    }
}

void menu() {
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                mark_task_as_completed();
                break;
            case 4:
                remove_task();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}

