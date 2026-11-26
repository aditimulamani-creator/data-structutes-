#include <iostream>
#include <string>
using namespace std;

// Structure for product details
struct Product
{
    int id;
    string name;
    float price;
    int quantity;

    Product* next;
};

// Linked List to store products
class ProductSystem
{
    Product* head;

    // Hash Table with Chaining
    Product* hashTable[10];

public:
    ProductSystem()
    {
        head = NULL;

        for (int i = 0; i < 10; i++)
            hashTable[i] = NULL;
    }

    // Hash function
    int hashFunction(int id)
    {
        return id % 10;
    }

    // Add a new product
    void addProduct(int id, string name,
                    float price, int quantity)
    {
        Product* p = new Product;

        p->id = id;
        p->name = name;
        p->price = price;
        p->quantity = quantity;

        // Insert into Linked List
        p->next = head;
        head = p;

        // Insert into Hash Table
        int index = hashFunction(id);

        p->next = hashTable[index];
        hashTable[index] = p;

        cout << "Product added successfully!\n";
    }

    // Search product using Product ID
    void searchProduct(int id)
    {
        int index = hashFunction(id);

        Product* temp = hashTable[index];

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "\nProduct Found!\n";
                cout << "ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Price: " << temp->price << endl;
                cout << "Quantity: "
                     << temp->quantity << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Product not found!\n";
    }

    // Display all products
    void displayProducts()
    {
        Product* temp = head;

        if (temp == NULL)
        {
            cout << "No products available.\n";
            return;
        }

        cout << "\n--- Product Catalog ---\n";

        while (temp != NULL)
        {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Price: " << temp->price
                 << " | Quantity: " << temp->quantity
                 << endl;

            temp = temp->next;
        }
    }

    // Update product details
    void updateProduct(int id)
    {
        Product* temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "Enter new price: ";
                cin >> temp->price;

                cout << "Enter new quantity: ";
                cin >> temp->quantity;

                cout << "Product updated!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Product not found!\n";
    }

    // Delete a product
    void deleteProduct(int id)
    {
        Product* temp = head;
        Product* prev = NULL;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                if (prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "Product deleted!\n";
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Product not found!\n";
    }
};

// Main function
int main()
{
    ProductSystem s;
    int choice, id, quantity;
    string name;
    float price;

    do
    {
        cout << "\n1. Add Product";
        cout << "\n2. Search Product";
        cout << "\n3. Update Product";
        cout << "\n4. Delete Product";
        cout << "\n5. Display Products";
        cout << "\n6. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Product ID: ";
            cin >> id;

            cout << "Enter Product Name: ";
            cin >> name;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> quantity;

            s.addProduct(id, name, price, quantity);
            break;

        case 2:
            cout << "Enter Product ID: ";
            cin >> id;
            s.searchProduct(id);
            break;

        case 3:
            cout << "Enter Product ID: ";
            cin >> id;
            s.updateProduct(id);
            break;

        case 4:
            cout << "Enter Product ID: ";
            cin >> id;
            s.deleteProduct(id);
            break;

        case 5:
            s.displayProducts();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
