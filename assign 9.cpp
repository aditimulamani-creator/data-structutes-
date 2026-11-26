#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int roll;
    string name;
    string course;
    Student* next;
};

class StudentSystem
{
    Student* head;
    Student* hashTable[10];

public:

    StudentSystem()
    {
        head = NULL;

        for (int i = 0; i < 10; i++)
            hashTable[i] = NULL;
    }

    // Hash function
    int hashFunction(int roll)
    {
        return roll % 10;
    }

    // Register a new student
    void registerStudent(int roll, string name)
    {
        if (searchStudent(roll, false))
        {
            cout << "Roll number already exists!\n";
            return;
        }

        Student* p = new Student;

        p->roll = roll;
        p->name = name;
        p->course = "Not Enrolled";
        p->next = head;

        head = p;

        // Insert into Hash Table
        int index = hashFunction(roll);

        p->next = hashTable[index];
        hashTable[index] = p;

        cout << "Student registered successfully!\n";
    }

    // Search student using Roll Number
    bool searchStudent(int roll, bool display = true)
    {
        int index = hashFunction(roll);

        Student* temp = hashTable[index];

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                if (display)
                {
                    cout << "\nRoll Number: "
                         << temp->roll;
                    cout << "\nName: " << temp->name;
                    cout << "\nCourse: "
                         << temp->course << endl;
                }

                return true;
            }

            temp = temp->next;
        }

        if (display)
            cout << "Student not found!\n";

        return false;
    }

    // Update student information
    void updateStudent(int roll)
    {
        int index = hashFunction(roll);
        Student* temp = hashTable[index];

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                cout << "Enter new name: ";
                cin >> temp->name;

                cout << "Student information updated!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Student not found!\n";
    }

    // Enroll student in a course
    void enrollCourse(int roll)
    {
        int index = hashFunction(roll);
        Student* temp = hashTable[index];

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                cout << "Enter course name: ";
                cin >> temp->course;

                cout << "Course enrollment successful!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Student not found!\n";
    }

    // Withdraw student from course
    void withdrawCourse(int roll)
    {
        int index = hashFunction(roll);
        Student* temp = hashTable[index];

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                temp->course = "Not Enrolled";
                cout << "Course withdrawal successful!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Student not found!\n";
    }

    // Remove student record
    void deleteStudent(int roll)
    {
        int index = hashFunction(roll);
        Student* temp = hashTable[index];
        Student* prev = NULL;

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                if (prev == NULL)
                    hashTable[index] = temp->next;
                else
                    prev->next = temp->next;

                // Remove from Linked List
                Student* current = head;
                Student* previous = NULL;

                while (current != NULL)
                {
                    if (current == temp)
                    {
                        if (previous == NULL)
                            head = current->next;
                        else
                            previous->next = current->next;

                        break;
                    }

                    previous = current;
                    current = current->next;
                }

                delete temp;
                cout << "Student record deleted!\n";
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Student not found!\n";
    }

    // Display all students
    void displayStudents()
    {
        Student* temp = head;

        if (temp == NULL)
        {
            cout << "No student records available.\n";
            return;
        }

        cout << "\n--- Student Records ---\n";

        while (temp != NULL)
        {
            cout << "\nRoll Number: " << temp->roll;
            cout << "\nName: " << temp->name;
            cout << "\nCourse: " << temp->course;
            cout << "\n-------------------\n";

            temp = temp->next;
        }
    }
};

int main()
{
    StudentSystem s;

    int choice, roll;
    string name;

    do
    {
        cout << "\n1. Register Student";
        cout << "\n2. Search Student";
        cout << "\n3. Update Student";
        cout << "\n4. Enroll in Course";
        cout << "\n5. Withdraw from Course";
        cout << "\n6. Delete Student";
        cout << "\n7. Display Students";
        cout << "\n8. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> roll;

            cout << "Enter Student Name: ";
            cin >> name;

            s.registerStudent(roll, name);
            break;

        case 2:
            cout << "Enter Roll Number: ";
            cin >> roll;

            s.searchStudent(roll);
            break;

        case 3:
            cout << "Enter Roll Number: ";
            cin >> roll;

            s.updateStudent(roll);
            break;

        case 4:
            cout << "Enter Roll Number: ";
            cin >> roll;

            s.enrollCourse(roll);
            break;

        case 5:
            cout << "Enter Roll Number: ";
            cin >> roll;

            s.withdrawCourse(roll);
            break;

        case 6:
            cout << "Enter Roll Number: ";
            cin >> roll;

            s.deleteStudent(roll);
            break;

        case 7:
            s.displayStudents();
            break;

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
