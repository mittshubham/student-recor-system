
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

// Global vector of students
vector<Student> students;

// Function to add a student
void addStudent() {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;
    students.push_back(s);
    cout << "Student added!\n";
}

// Function to display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No records found.\n";
        return;
    }
    cout << "\nStudent Records:\n";
    for (const auto& s : students) {
        cout << "Roll No: " << s.rollNo << ", Name: " << s.name << ", Marks: " << s.marks << "\n";
    }
}

// Sort students by marks
void sortByMarks() {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.marks > b.marks;
    });
    cout << "Students sorted by marks.\n";
}

// Binary search student by roll number
void searchByRoll() {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.rollNo < b.rollNo;
    });

    int left = 0, right = students.size() - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (students[mid].rollNo == roll) {
            cout << "Found: " << students[mid].name << ", Marks: " << students[mid].marks << "\n";
            found = 1;
            break;
        } else if (students[mid].rollNo < roll) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) cout << "Student not found.\n";
}

// Menu-driven program
int main() {
    int choice;
    do {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n2. Display All\n3. Sort by Marks\n4. Search by Roll No\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: sortByMarks(); break;
            case 4: searchByRoll(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
