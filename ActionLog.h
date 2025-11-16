
#ifndef ACTIONLOG_H
#define ACTIONLOG_H

#include <string>

// This is the Node for our Stack
struct LogNode {
    std::string message;
    LogNode* next;
};

// This is our Stack class.
// We call it ActionLog to be descriptive.
class ActionLog {
private:
    LogNode* top; // Pointer to the top of the stack

public:
    // Constructor
    ActionLog();
    // Destructor
    ~ActionLog();

    // PUSH: Adds a message to the top of the stack
    void push(std::string message);

    // POP: Removes the top message (we don't need it, but good to have)
    std::string pop();

    // Prints all messages in the log (from top to bottom)
    void printLog();

    // Checks if the stack is empty
    bool isEmpty();
};

#endif // ACTIONLOG_H




