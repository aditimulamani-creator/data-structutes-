#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

// Patient record
struct Patient 
{
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

// Hash table
Patient* table[SIZE] = {NULL};

// Hash function
int hashFunction(int id)
{
    return id % SIZE;
}

// Search patient using ID
Patient* searchPatient(int id) 
{
    int index = hashFunction(id);
    Patient* temp = table[index];

    while (temp != NULL)
      {
        if (temp->id == id)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

// Register a new patient
void registerPatient() 
{
    Patient* p = new Patient;

    cout << "Enter Patient ID: ";
    cin >> p->id;

    // Check for duplicate ID
    if (searchPatient(p->id) != NULL) 
    {
        cout << "Patient ID already exists!\n";
        delete p;
        return;
    }

    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, p->name);

    cout << "Enter Age: ";
    cin >> p->age;

    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, p->disease);

    int index = hashFunction(p->id);

    // Insert patient at the beginning
    p->next = table[index];
    table[index] = p;

    cout << "Patient Registered Successfully!\n";
}

// Display all patients
void displayPatients() 
{
    bool found = false;

    cout << "\n--- Patient Records ---\n";

    for (int i = 0; i < SIZE; i++)
      {
        Patient* temp = table[i];

        while (temp != NULL) 
        {
            cout << "\nPatient ID: " << temp->id;
            cout << "\nName: " << temp->name;
            cout << "\nAge: " << temp->age;
            cout << "\nDisease: " << temp->disease;
            cout << "\n-------------------\n";

            found = true;
            temp = temp->next;
        }
    }

    if (!found)
        cout << "No patient records found!\n";
}

// Update patient information
void updatePatient() 
{
    int id;

    cout << "Enter Patient ID to update: ";
    cin >> id;

    Patient* p = searchPatient(id);

    if (p == NULL) {
        cout << "Patient not found!\n";
        return;
    }

    cin.ignore();

    cout << "Enter New Name: ";
    getline(cin, p->name);

    cout << "Enter New Age: ";
    cin >> p->age;

    cin.ignore();

    cout << "Enter New Disease: ";
    getline(cin, p->disease);

    cout << "Patient Record Updated!\n";
}

// Discharge patient
void dischargePatient() 
{
    int id;

    cout << "Enter Patient ID to discharge: ";
    cin >> id;

    int index = hashFunction(id);

    Patient* temp = table[index];
    Patient* prev = NULL;

    while (temp != NULL) 
    {
        if (temp->id == id)
        {

            if (prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            delete temp;

            cout << "Patient Discharged Successfully!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Patient Not Found!\n";
}

// Search and display one patient
void searchAndDisplay() 
{
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    Patient* p = searchPatient(id);

    if (p == NULL)
    {
        cout << "Patient Not Found!\n";
        return;
    }

    cout << "\nPatient ID: " << p->id;
    cout << "\nName: " << p->name;
    cout << "\nAge: " << p->age;
    cout << "\nDisease: " << p->disease << endl;
}

// Main function
int main() 
{
    int choice;

    do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Register Patient\n";
        cout << "2. Update Patient\n";
        cout << "3. Discharge Patient\n";
        cout << "4. Display All Patients\n";
        cout << "5. Search Patient\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                registerPatient();
                break;

            case 2:
                updatePatient();
                break;

            case 3:
                dischargePatient();
                break;

            case 4:
                displayPatients();
                break;

            case 5:
                searchAndDisplay();
                break;

            case 6:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
