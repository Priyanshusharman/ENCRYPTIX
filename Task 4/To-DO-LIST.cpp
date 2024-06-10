#include <iostream>
#include <vector>
#include <string>
using namespace std;

class to_list
{
private:
    vector<string> list;

public:
    void add(string task)
    {
        list.push_back(task);
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
            cout << "Task " << i + 1 << " : " << list[i] << endl;
        }
    }
    void delete_tasks(int n)
    {
        if (n < 1 || n > list.size())
        {
            cout << "Invalid task number." << endl;
            return;
        }
        list.erase(list.begin() + n - 1);
    }
};

int main()
{
    cout << "***********************        To DO LIST        ***********************\n";
    to_list l1;
    while (true)
    {
        int choice;
        cout << "\nEnter 1 to see Task\n";
        cout << "Enter 2 to delete Task\n";
        cout << "Enter 3 to Add task\n";
        cout << "Enter 0 to exit\n";
        cin >> choice;

        if (choice > 3 || choice < 0)
        {
            cout << "Invalid choice, choose again\n";
        }
        else if (choice == 1)
        {
            l1.view();
        }
        else if (choice == 2)
        {
            l1.view();
            int n;
            cout << "Select Number of Task to delete: ";
            cin >> n;
            l1.delete_tasks(n);
        }
        else if (choice == 3)
        {
            string task;
            cout << "Enter task: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, task);
            l1.add(task);
            l1.view();
        }
        else
        {
            break;
        }
    }

    return 0;
}
