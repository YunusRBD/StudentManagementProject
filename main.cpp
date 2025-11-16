#include <iostream>
#include <string>
#include <fstream>   // For file input/output (saving and loading)
#include <sstream>   // For splitting strings from the file
#include <map>       // <-- REQUIREMENT #3: The "outside" Data Structure

#include "Student.h"
#include "LinkedList.h"
#include "ActionLog.h"

// We can use this here for simplicity in our main file
using namespace std;

// --- These are our 3 Data Structures ---
LinkedList studentList;         // 1. Linked List (from course)
ActionLog historyLog;           // 2. Stack (from course)
map<string, Node*> studentMap;  // 3. Map (Red-Black Tree, from outside)

// --- Function Declarations ---
void showMenu();
void handleAdd();
void handleEdit();
void handleDelete();
void handleSearch();
void handlePrintAll();
void handlePrintLog(); // This is the function you asked about
void saveToFile();
void loadFromFile();

// --- Main Program ---
int main() {
    // Load data from file when program starts
    loadFromFile();

    char choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case '1':
                handleAdd();
                break;
            case '2':
                handleEdit();
                break;
            case '3':
                handleDelete();
                break;
            case '4':
                handleSearch();
                break;
            case '5':
                handlePrintAll();
                break;
            case '6':
                handlePrintLog();
                break;
            case '7':
                cout << "Saving and exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl; // Add a space before next menu

    } while (choice != '7');

    // Save data to file before program closes
    saveToFile();
    return 0;
}

// --- Function Implementations ---

void showMenu() {
    cout << "--- Student Management System ---" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Edit Student" << endl;
    cout << "3. Delete Student" << endl;
    cout << "4. Search for Student" << endl;
    cout << "5. Print All Students" << endl;
    cout << "6. Print Action Log" << endl;
    cout << "7. Save and Exit" << endl;
    cout << "Enter your choice: ";
}

// 1. Add Student
void handleAdd() {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;

    // Check if student ID already exists using our fast map
    if (studentMap.count(s.id)) {
        cout << "Error: Student ID " << s.id << " already exists." << endl;
        return;
    }

    cout << "Enter Student Name (use_underscores_for_spaces): ";
    cin >> s.name;
    cout << "Enter Student GPA: ";
    cin >> s.gpa;

    // 1. Add to the Linked List
    Node* newNode = studentList.addStudent(s);
    // 2. Add to the Map for fast search
    studentMap[s.id] = newNode;
    // 3. Add to the Action Log
    historyLog.push("Added student: " + s.id);

    cout << "Student added successfully." << endl;
}

// 2. Edit Student
void handleEdit() {
    string id;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    // 1. Find the student INSTANTLY using the map
    if (studentMap.count(id) == 0) {
        cout << "Error: Student not found." << endl;
        return;
    }

    // 2. Get the node pointer from the map
    Node* studentNode = studentMap[id];

    // 3. Update the data directly in that node
    cout << "Enter new Name (current: " << studentNode->data.name << "): ";
    cin >> studentNode->data.name;
    cout << "Enter new GPA (current: " << studentNode->data.gpa << "): ";
    cin >> studentNode->data.gpa;

    // 4. Log the action
    historyLog.push("Edited student: " + id);
    cout << "Student updated successfully." << endl;
}

// 3. Delete Student
void handleDelete() {
    string id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    // 1. Check if student exists using the map
    if (studentMap.count(id) == 0) {
        cout << "Error: Student not found." << endl;
        return;
    }

    // 2. Delete from the Linked List
    bool deleted = studentList.deleteStudent(id);

    if (deleted) {
        // 3. Delete from the Map
        studentMap.erase(id);
        // 4. Log the action
        historyLog.push("Deleted student: " + id);
        cout << "Student deleted successfully." << endl;
    } else {
        cout << "Error: Could not delete student." << endl;
    }
}

// 4. Search for Student
void handleSearch() {
    string id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    // 1. Find student INSTANTLY using the map
    if (studentMap.count(id)) {
        // 2. Get the node and print its data
        Node* studentNode = studentMap[id];
        cout << "  --- Student Found ---" << endl;
        cout << "  ID: " << studentNode->data.id << endl;
        cout << "  Name: " << studentNode->data.name << endl;
        cout << "  GPA: " << studentNode->data.gpa << endl;
        cout << "  ---------------------" << endl;
    } else {
        cout << "Error: Student not found." << endl;
    }
}

// 5. Print All Students
void handlePrintAll() {
    studentList.printAll();
}

// 6. Print Action Log
void handlePrintLog() {
    historyLog.printLog();
}

// Save all data to "students.txt"
void saveToFile() {
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "Error: Could not open file for saving." << endl;
        return;
    }

    // We walk the linked list from the head
    Node* current = studentList.getHead();
    while (current != NULL) {
        // Write as: ID,Name,GPA
        outFile << current->data.id << ","
                << current->data.name << ","
                << current->data.gpa << endl;
        current = current->next;
    }
    outFile.close();
}

// Load all data from "students.txt"
void loadFromFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "No existing 'students.txt' file found. Starting fresh." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string segment;
        Student s;

        // Parse the line: ID,Name,GPA
        getline(ss, s.id, ',');
        getline(ss, s.name, ',');
        string gpaStr;
        getline(ss, gpaStr, ',');
        s.gpa = stod(gpaStr); // string to double

        // Add the loaded student to our data structures
        // (We re-use the same logic as handleAdd)
        if (studentMap.count(s.id) == 0) {
            Node* newNode = studentList.addStudent(s);
            studentMap[s.id] = newNode;
        }
    }
    inFile.close();
    cout << "Student data loaded from file." << endl;
}
