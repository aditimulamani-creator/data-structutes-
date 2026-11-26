#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Customer 
{
    int token;
    string name;
};

// Queues for customers
queue<Customer> normal;
queue<Customer> priority;

// Stack for served customers
stack<Customer> history;

int tokenNo = 1;

// Issue a token
void issueToken() 
{
    Customer c;
    int choice;

    c.token = tokenNo++;

    cout << "Enter customer name: ";
    cin >> c.name;

    cout << "Priority customer? (1=Yes, 0=No): ";
    cin >> choice;

    if (choice == 1) 
    {
        priority.push(c);
        cout << "Priority token issued: ";
    }
    else {
        normal.push(c);
        cout << "Normal token issued: ";
    }

    cout << c.token << endl;
}

// Serve the next customer
void serveCustomer() 
{
    Customer c;

    if (!priority.empty()) 
    {
        c = priority.front();
        priority.pop();
    }
    else if (!normal.empty())
    {
        c = normal.front();
        normal.pop();
    }
    else 
    {
        cout << "No customers waiting!\n";
        return;
    }

    history.push(c);

    cout << "\nServing Customer\n";
    cout << "Token Number: " << c.token << endl;
    cout << "Customer Name: " << c.name << endl;
}

// Display recently served customers
void showHistory() 
{
    stack<Customer> temp = history;

    if (temp.empty()) 
    {
        cout << "No served customers!\n";
        return;
    }

    cout << "\nRecently Served Customers:\n";

    while (!temp.empty())
      {
        Customer c = temp.top();
        temp.pop();

        cout << "Token: " << c.token
             << " Name: " << c.name << endl;
    }
}

// Main menu
int main() 
{
    int choice;

    do
      {
        cout << "\n--- Bank Token Management System ---\n";
        cout << "1. Issue Token\n";
        cout << "2. Serve Customer\n";
        cout << "3. Show Served History\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
          {
            case 1:
                issueToken();
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                showHistory();
                break;

            case 4:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
