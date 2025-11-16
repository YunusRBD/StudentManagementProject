# StudentManagementProject
A C++ console program that manages student records using three data structures: a linked list, a stack, and a map.
The program supports adding, editing, deleting, searching, printing, saving, and loading student information.

Features
Add a student
Edit student information
Delete a student
Search for a student by ID
Print all students
Print action log
Save data to file and load it on startup

Data Structures
Linked List
Stores all students.
Each node contains a Student object and a pointer to the next node.
Stack (ActionLog)
Stores actions such as add, edit, and delete.
Newest actions appear first.

Map
Uses std::map<string, Node*> to find students quickly using their ID.

File Structure
main.cpp
LinkedList.h
LinkedList.cpp
Student.h
ActionLog.h
ActionLog.cpp
students.txt
README.md

File Saving Format
The file students.txt stores each student as:
id,name,gpa

Example:
4411,Khalid_fhaad,4.2
44422445,Yunus_Ali,4.7

Compile and Run
Using g++:
g++ main.cpp LinkedList.cpp ActionLog.cpp -o StudentManager
./StudentManager

Running the Program
The program loads students automatically from students.txt.
Before closing, it saves all students back to the file.
