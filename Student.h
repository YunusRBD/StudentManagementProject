#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// We use 'using namespace std;' in the .cpp files,
// but it's good practice to be specific in header files.

// This is a simple struct to hold our student data.
// A struct is like a simple class with public members.
struct Student {
    std::string id;
    std::string name;
    double gpa;
};

#endif // STUDENT_H
