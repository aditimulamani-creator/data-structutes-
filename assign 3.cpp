#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name, category, expiry;
    float price;
    int quantity;
};

Product p[100];
int n = 0;

// Add product
void addProduct() 
{
    cout << "Enter ID, Name, Category, Price, Quantity, Expiry (YYYY-MM-DD): ";
    cin >> p[n].id >> p[n].name >> p[n].category
        >> p[n].price >> p[n].quantity >> p[n].expiry;

    n++;
    cout << "Product added successfully!\n";
}

// Display products
void display()
{
    if (n == 0) 
    {
        cout << "No products available.\n";
        return;
    }

    for (int i = 0; i < n; i++)
      {
        cout << "\nID: " << p[i].id
             << "\nName: " << p[i].name
             << "\nCategory: " << p[i].category
             << "\nPrice: " << p[i].price
             << "\nQuantity: " << p[i].quantity
             << "\nExpiry: " << p[i].expiry << "\n";
    }
}

// Search by ID
void searchProduct() 
{
    int id;
    cout << "Enter Product ID: ";
    cin >> id;

    for (int i = 0; i < n; i++)
      {
        if (p[i].id == id) 
        {
            cout << "Product found: " << p[i].name
                 << ", Price: " << p[i].price << "\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// Update product
void updateProduct()
{
    int id;
    cout << "Enter Product ID to update: ";
    cin >> id;

    for (int i = 0; i < n; i++) 
    {
        if (p[i].id == id)
        {
            cout << "Enter new Price and Quantity: ";
            cin >> p[i].price >> p[i].quantity;
            cout << "Product updated!\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// Delete product
void deleteProduct()
{
    int id;
    cout << "Enter Product ID to delete: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (p[i].id == id) {
            for (int j = i; j < n - 1; j++)
                p[j] = p[j + 1];

            n--;
            cout << "Product deleted!\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// Sort products
void sortProducts()
{
    int choice;
    cout << "1. Price  2. Quantity  3. Expiry Date\n";
    cin >> choice;

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++)
          {
            bool swapNeeded = false;

            if (choice == 1 && p[j].price > p[j + 1].price)
                swapNeeded = true;

            else if (choice == 2 &&
                     p[j].quantity > p[j + 1].quantity)
                swapNeeded = true;

            else if (choice == 3 &&
                     p[j].expiry > p[j + 1].expiry)
                swapNeeded = true;

            if (swapNeeded)
            {
                Product temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    cout << "Products sorted!\n";
    display();
}

int main() 
{
    int choice;

    do 
    {
        cout << "\n--- Grocery Inventory System ---\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "6. Sort Products\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
          {
            case 1: addProduct(); break;
            case 2: display(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: sortProducts(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
