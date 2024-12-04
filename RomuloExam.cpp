#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string id;  
    string name;
    int age;
    float gpa;

    Student(string i, string n, int a, float g) : id(i), name(n), age(a), gpa(g) {}
};

void createStudent(vector<Student>& students);
void readStudents(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\nStudent Information System\n";
        cout << "1. Create Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createStudent(students); break;
            case 2: readStudents(students); break;
            case 3: updateStudent(students); break;
            case 4: deleteStudent(students); break;
            case 5: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}


void createStudent(vector<Student>& students) {
    string id, name;
    int age;
    float gpa;

    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Student Name: ";
    cin.ignore();  
    getline(cin, name);
    cout << "Enter Student Age: ";
    cin >> age;
    cout << "Enter Student GPA: ";
    cin >> gpa;

    students.push_back(Student(id, name, age, gpa));
    cout << "Student added successfully.\n";
}

void readStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    for (const auto& student : students) {
        cout << "ID: " << student.id << ", Name: " << student.name 
             << ", Age: " << student.age << ", GPA: " << student.gpa << '\n';
    }
}

void updateStudent(vector<Student>& students) {
    string id;
    cout << "Enter Student ID: ";
    cin >> id;

    for (auto& student : students) {
        if (student.id == id) {
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter student age: ";
            cin >> student.age;
            cout << "Enter student GPA: ";
            cin >> student.gpa;
            cout << "Student updated successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent(vector<Student>& students) {
    string id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
