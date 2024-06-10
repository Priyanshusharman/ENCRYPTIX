#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task
{
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList
{
private:
    vector<Task> list;

public:
    void add(string task)
    {
        list.push_back(Task(task));
    }

    void view()
    {
        if (list.empty())
        {
            cout << "No tasks available." << endl;
            return;
        }

        for (int i = 0; i < list.size(); i++)
        {
            cout << "Task " << i + 1 << " [" << (list[i].completed ? "Completed" : "Pending") << "] : " << list[i].description << endl;
        }
    }

    void deleteTask(int n)
    {
        if (n < 1 || n > list.size())
        {
            cout << "Invalid task number." << endl;
            return;
        }
        list.erase(list.begin() + n - 1);
    }

    void markCompleted(int n)
    {
        if (n < 1 || n > list.size())
        {
            cout << "Invalid task number." << endl;
            return;
        }
        list[n - 1].completed = true;
    }
};

int main()
{
    cout << "***********************        To-DO-LIST        ***********************\n";
    ToDoList toDoList;
    while (true)
    {
        int choice;
        cout << "\nEnter 1 to view tasks\n";
        cout << "Enter 2 to delete a task\n";
        cout << "Enter 3 to add a task\n";
        cout << "Enter 4 to mark a task as completed\n";
        cout << "Enter 0 to exit\n";
        cin >> choice;

        if (choice > 4 || choice < 0)
        {
            cout << "Invalid choice, choose again\n";
        }
        else if (choice == 1)
        {
            toDoList.view();
        }
        else if (choice == 2)
        {
            toDoList.view();
            int n;
            cout << "Select task number to delete: ";
            cin >> n;
            toDoList.deleteTask(n);
        }
        else if (choice == 3)
        {
            string task;
            cout << "Enter task: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, task);
            toDoList.add(task);
            toDoList.view();
        }
        else if (choice == 4)
        {
            toDoList.view();
            int n;
            cout << "Select task number to mark as completed: ";
            cin >> n;
            toDoList.markCompleted(n);
            toDoList.view();
        }
        else
        {
            break;
        }
    }

    return 0;
}
