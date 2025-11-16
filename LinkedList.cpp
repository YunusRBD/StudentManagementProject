#include "LinkedList.h"
#include <iostream>

using namespace std;

// Constructor
LinkedList::LinkedList() {
    head = NULL; // Initialize the list as empty
}

// Destructor
// This loops through and deletes every node to prevent memory leaks
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next; // Store next node
        delete current;            // Delete current node
        current = next;            // Move to the next node
    }
}

// Adds a new student to the front of the list
Node* LinkedList::addStudent(Student s) {
    // 1. Create a new node
    Node* newNode = new Node();
    newNode->data = s;
    newNode->next = NULL; // Initialize 'next'

    // 2. Point the new node's 'next' to the current head
    newNode->next = head;

    // 3. Make the new node the new head
    head = newNode;

    // Return the new node so it can be added to the map
    return newNode;
}

// Deletes a student from the list using their ID
bool LinkedList::deleteStudent(string id) {
    Node* current = head;
    Node* prev = NULL;

    // Loop to find the node with the matching ID
    while (current != NULL && current->data.id != id) {
        prev = current;
        current = current->next;
    }

    // If current is NULL, the student was not found
    if (current == NULL) {
        return false;
    }

    // --- Student was found, now we delete it ---

    // Case 1: The node to delete is the head node
    if (prev == NULL) {
        head = current->next; // The new head is the next node
    }
    // Case 2: The node is in the middle or at the end
    else {
        prev->next = current->next; // "Skip" the current node
    }

    // Delete the node and free the memory
    delete current;
    return true;
}

// Prints all students in the list
void LinkedList::printAll() {
    Node* current = head;
    if (current == NULL) {
        cout << "  List is empty." << endl;
        return;
    }

    cout << "  --- All Students ---" << endl;
    while (current != NULL) {
        cout << "  ID: " << current->data.id
             << ", Name: " << current->data.name
             << ", GPA: " << current->data.gpa << endl;
        current = current->next;
    }
    cout << "  --------------------" << endl;
}

// Helper function to get the head of the list
Node* LinkedList::getHead() {
    return head;
}
