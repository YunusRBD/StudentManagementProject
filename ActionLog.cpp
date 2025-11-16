#include "ActionLog.h"
#include <iostream>

using namespace std;

// Constructor
ActionLog::ActionLog() {
    top = NULL; // Initialize stack as empty
}

// Destructor
ActionLog::~ActionLog() {
    while (!isEmpty()) {
        pop(); // Pop all items to free memory
    }
}

// PUSH: Adds a message to the top of the stack
void ActionLog::push(string message) {
    // 1. Create a new log node
    LogNode* newNode = new LogNode();
    newNode->message = message;

    // 2. Link it to the current top
    newNode->next = top;

    // 3. Make it the new top
    top = newNode;
}

// POP: Removes the top message
string ActionLog::pop() {
    if (isEmpty()) {
        return ""; // Stack is empty
    }

    // 1. Store the top node and its message
    LogNode* temp = top;
    string msg = temp->message;

    // 2. Move the top pointer down
    top = top->next;

    // 3. Delete the old top node
    delete temp;
    return msg;
}

// Prints all messages in the log
void ActionLog::printLog() {
    if (isEmpty()) {
        cout << "  Action Log is empty." << endl;
        return;
    }

    LogNode* current = top;
    cout << "  --- Action Log (Newest to Oldest) ---" << endl;
    while (current != NULL) {
        cout << "  - " << current->message << endl;
        current = current->next;
    }
    cout << "  -------------------------------------" << endl;
}

// Checks if the stack is empty
bool ActionLog::isEmpty() {
    return top == NULL;
}
