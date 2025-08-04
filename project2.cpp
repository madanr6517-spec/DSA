#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    Student* next;
};

Student* head = nullptr;

void addStudent() {
    Student* newStudent = new Student;
    cout << "Enter Student ID: ";
    cin >> newStudent->id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newStudent->name);
    cout << "Enter Age: ";
    cin >> newStudent->age;
    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newStudent;
    }
    cout << "Student added successfully!\n";
}

void searchStudent() {
    int searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->id == searchId) {
            cout << "ID: " << temp->id << "\n";
            cout << "Name: " << temp->name << "\n";
            cout << "Age: " << temp->age << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Record not found.\n";
}

void modifyStudent() {
    int modifyId;
    cout << "Enter Student ID to modify: ";
    cin >> modifyId;
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->id == modifyId) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, temp->name);
            cout << "Enter new Age: ";
            cin >> temp->age;
            cout << "Record Updated Successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Record not found.\n";
}

void deleteStudent() {
    int deleteId;
    cout << "Enter Student ID to delete: ";
    cin >> deleteId;
    Student* temp = head;
    Student* prev = nullptr;

    while (temp != nullptr && temp->id != deleteId) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Record not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Record Deleted Successfully!\n";
}

void menu() {
    int choice;
    while (true) {
        cout << "\n==== Student Information System ====\n";
        cout << "1. Add New Record\n";
        cout << "2. Search a Record\n";
        cout << "3. Modify a Record\n";
        cout << "4. Delete a Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            searchStudent();
        else if (choice == 3)
            modifyStudent();
        else if (choice == 4)
            deleteStudent();
        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        } else
            cout << "Invalid choice. Try again.\n";
    }
}

int main() {
    menu();
    return 0;
}
