#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Request 
{
    int id;
    string name;
    string issue;
};

// Queue for normal requests
queue<Request> normal;

// Queue for urgent requests
queue<Request> urgent;

// Stack for resolved requests
stack<Request> history;

int requestNo = 1;

// Add a customer request
void addRequest() 
{
    Request r;
    int choice;

    r.id = requestNo++;

    cout << "Enter customer name: ";
    cin >> r.name;

    cout << "Enter issue: ";
    cin >> r.issue;

    cout << "Is it urgent? (1=Yes, 0=No): ";
    cin >> choice;

    if (choice == 1)
    {
        urgent.push(r);
        cout << "Urgent request added!\n";
    }
    else {
        normal.push(r);
        cout << "Normal request added!\n";
    }
}

// Process the next request
void processRequest()
{
    Request r;

    if (!urgent.empty())
    {
        r = urgent.front();
        urgent.pop();
    }
    else if (!normal.empty())
    {
        r = normal.front();
        normal.pop();
    }
    else
    {
        cout << "No pending requests!\n";
        return;
    }

    cout << "\nProcessing Request\n";
    cout << "ID: " << r.id << endl;
    cout << "Customer: " << r.name << endl;
    cout << "Issue: " << r.issue << endl;

    history.push(r);

    cout << "Request Resolved!\n";
}

// Display recent resolved requests
void showHistory() 
{
    stack<Request> temp = history;

    if (temp.empty()) 
    {
        cout << "No resolved requests!\n";
        return;
    }

    cout << "\nRecently Resolved Requests:\n";

    while (!temp.empty()) 
    {
        Request r = temp.top();
        temp.pop();

        cout << "ID: " << r.id
             << " Name: " << r.name
             << " Issue: " << r.issue << endl;
    }
}

// Recursive IVR menu
void IVR() 
{
    int choice;

    cout << "\n--- Customer Support IVR ---\n";
    cout << "1. Billing Support\n";
    cout << "2. Technical Support\n";
    cout << "3. Account Support\n";
    cout << "4. Add Customer Request\n";
    cout << "5. Exit IVR\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
      {
        case 1:
            cout << "You selected Billing Support.\n";
            break;

        case 2:
            cout << "You selected Technical Support.\n";
            break;

        case 3:
            cout << "You selected Account Support.\n";
            break;

        case 4:
            addRequest();
            break;

        case 5:
            cout << "Thank you for contacting us!\n";
            return;

        default:
            cout << "Invalid choice!\n";
    }

    IVR(); // Recursive call
}

// Main menu
int main() 
{
    int choice;

    do
      {
        cout << "\n--- Customer Service System ---\n";
        cout << "1. Add Request\n";
        cout << "2. Process Request\n";
        cout << "3. Show Resolved History\n";
        cout << "4. Start IVR\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
          {
            case 1:
                addRequest();
                break;

            case 2:
                processRequest();
                break;

            case 3:
                showHistory();
                break;

            case 4:
                IVR();
                break;

            case 5:
                cout << "System Closed!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
