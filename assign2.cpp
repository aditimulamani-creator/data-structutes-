#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name, program;
    float marks;
};

Student s[100];
int n = 0;

// Add student
void addStudent() {
    if (n == 100) {
        cout << "Array is full!\n";
        return;
    }

    cout << "Enter Roll Number: ";
    cin >> s[n].roll;

    cout << "Enter Name: ";
    cin >> ws;
    getline(cin, s[n].name);

    cout << "Enter Program: ";
    getline(cin, s[n].program);

    cout << "Enter Total Marks: ";
    cin >> s[n].marks;

    n++;
    cout << "Student added successfully!\n";
}

// Display all students
void display() {
    if (n == 0) {
        cout << "No records found.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nRoll: " << s[i].roll
             << "\nName: " << s[i].name
             << "\nProgram: " << s[i].program
             << "\nMarks: " << s[i].marks << "\n";
    }
}

// Search student by Roll Number
void searchStudent() {
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            cout << "Student Found!\n";
            cout << s[i].name << " - "
                 << s[i].marks << " marks\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

// Update student
void updateStudent() {
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            cout << "Enter New Name: ";
            cin >> ws;
            getline(cin, s[i].name);

            cout << "Enter New Program: ";
            getline(cin, s[i].program);

            cout << "Enter New Marks: ";
            cin >> s[i].marks;

            cout << "Record updated!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

// Delete student
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            for (int j = i; j < n - 1; j++)
                s[j] = s[j + 1];

            n--;
            cout << "Record deleted!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

// Sort students
void sortStudents(int choice) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            bool swapNeeded = false;

            if (choice == 1 && s[j].roll > s[j + 1].roll)
                swapNeeded = true;

            if (choice == 2 && s[j].name > s[j + 1].name)
                swapNeeded = true;

            if (choice == 3 && s[j].marks < s[j + 1].marks)
                swapNeeded = true;

            if (swapNeeded) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    display();
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Sort by Roll Number\n";
        cout << "7. Sort by Name\n";
        cout << "8. Generate Merit List\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: display(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortStudents(1); break;
            case 7: sortStudents(2); break;
            case 8: sortStudents(3); break;
            case 0: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
