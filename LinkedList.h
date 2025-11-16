#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"
#include <string>

// This is the Node for our Linked List.
// It holds one Student and a pointer to the next Node.
struct Node {
    Student data;
    Node* next;
};

// This is our Linked List class.
// It will manage all the operations for our list of students.
class LinkedList {
private:
    Node* head; // A pointer to the very first node in the list

public:
    // Constructor: sets head to NULL (an empty list)
    LinkedList();

    // Destructor: cleans up memory when the list is destroyed
    ~LinkedList();

    // Adds a new student to the front of the list
    Node* addStudent(Student s);

    // Deletes a student from the list using their ID
    bool deleteStudent(std::string id);

    // Prints all students in the list
    void printAll();

    // Helper function to get the head of the list (for saving)
    Node* getHead();
};

#endif // LINKEDLIST_H

