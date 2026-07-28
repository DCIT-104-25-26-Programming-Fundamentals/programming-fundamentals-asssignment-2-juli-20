// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void displayMenu();
void addStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void calculateAverage(const vector<Student>& students);

int main() {
    vector<Student> students;
    int choice;
    
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
    cout << "================================" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverage(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter 1-4." << endl;
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

void addStudent(vector<Student>& students) {
    Student newStudent;
    int numScores;
    
    cout << "Student name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    
    cout << "Student ID: ";
    cin >> newStudent.id;
    
    cout << "How many scores? ";
    cin >> numScores;
    
    if (numScores < 0) {
        cout << "Error: Number of scores cannot be negative." << endl;
        return;
    }
    
    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }
    
    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }
    
    cout << "\n------------------------------------------" << endl;
    cout << "Name                 ID        Scores       Average" << endl;
    cout << "------------------------------------------" << endl;
    
    for (const auto& student : students) {
        // Name
        cout << student.name;
        for (int i = student.name.length(); i < 20; i++) cout << " ";
        
        // ID
        cout << student.id;
        for (int i = to_string(student.id).length(); i < 10; i++) cout << " ";
        
        // Scores - display as whole numbers
        string scoresStr = "";
        for (size_t i = 0; i < student.scores.size(); i++) {
            scoresStr += to_string((int)student.scores[i]);
            if (i < student.scores.size() - 1) {
                scoresStr += ", ";
            }
        }
        cout << scoresStr;
        for (int i = scoresStr.length(); i < 12; i++) cout << " ";
        
        // Average
        if (student.scores.empty()) {
            cout << "N/A" << endl;
        } else {
            double sum = 0;
            for (double score : student.scores) {
                sum += score;
            }
            double avg = sum / student.scores.size();
            cout << setprecision(2) << avg << endl;
        }
    }
    cout << "------------------------------------------" << endl;
}

void calculateAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in the system yet." << endl;
        return;
    }
    
    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;
    
    for (const auto& student : students) {
        if (student.id == searchId) {
            if (student.scores.empty()) {
                cout << student.name << " has no scores recorded." << endl;
                return;
            }
            
            double sum = 0;
            for (double score : student.scores) {
                sum += score;
            }
            double avg = sum / student.scores.size();
            
            cout << student.name << "'s average score: " 
                 << setprecision(2) << avg << endl;
            return;
        }
    }
    
    cout << "Error: Student with ID " << searchId << " not found." << endl;
}