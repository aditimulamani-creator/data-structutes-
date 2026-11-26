#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Order 
{
    int id;
    string name;
};

// Queues and stack
queue<Order> normalOrders;
queue<Order> vipOrders;
stack<Order> cancelledOrders;

// Add a new order
void addOrder()
{
    Order o;
    int vip;

    cout << "Enter Order ID: ";
    cin >> o.id;

    cout << "Enter Customer Name: ";
    cin >> o.name;

    cout << "VIP Order? (1=Yes, 0=No): ";
    cin >> vip;

    if (vip == 1)
        vipOrders.push(o);
    else
        normalOrders.push(o);

    cout << "Order Added Successfully!\n";
}

// Process the next order
void processOrder() 
{
    Order o;

    if (!vipOrders.empty()) 
    {
        o = vipOrders.front();
        vipOrders.pop();
    }
    else if (!normalOrders.empty())
    {
        o = normalOrders.front();
        normalOrders.pop();
    }
    else {
        cout << "No pending orders!\n";
        return;
    }

    cout << "Processing Order: "
         << o.id << " - " << o.name << endl;
}

// Cancel an order
void cancelOrder() 
{
    Order o;

    cout << "Enter Order ID: ";
    cin >> o.id;

    cout << "Enter Customer Name: ";
    cin >> o.name;

    cancelledOrders.push(o);

    cout << "Order Cancelled!\n";
}

// Display cancelled order history
void showCancelled()
{
    stack<Order> temp = cancelledOrders;

    if (temp.empty())
    {
        cout << "No cancelled orders!\n";
        return;
    }

    cout << "\nRecently Cancelled Orders:\n";

    while (!temp.empty()) 
    {
        Order o = temp.top();
        temp.pop();

        cout << o.id << " - " << o.name << endl;
    }
}

// Recursive menu navigation
void menu()
{
    int choice;

    cout << "\n--- Restaurant Order System ---\n";
    cout << "1. Add Order\n";
    cout << "2. Process Order\n";
    cout << "3. Cancel Order\n";
    cout << "4. Show Cancelled Orders\n";
    cout << "5. Exit\n";

    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice) 
    {
        case 1:
            addOrder();
            break;

        case 2:
            processOrder();
            break;

        case 3:
            cancelOrder();
            break;

        case 4:
            showCancelled();
            break;

        case 5:
            cout << "Thank You!\n";
            return;

        default:
            cout << "Invalid Choice!\n";
    }

    menu(); // Recursive call
}

int main()
{
    menu();
    return 0;
}
