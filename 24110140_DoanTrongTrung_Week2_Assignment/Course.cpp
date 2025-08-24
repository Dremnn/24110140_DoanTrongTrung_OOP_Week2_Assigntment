#include <bits/stdc++.h>
using namespace std;

class Course {
public:
    string courseName;
    string courseCode;
    string instructorName;
    int credits;

    void displayInfo() {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor's Name: " << instructorName << endl;
    }

    bool isHighCredit() {
        return credits > 3;
    }

    bool isLabRequired() {
        return credits > 4;
    }
    
};

int main() {
    Course course1;
    course1.courseName = "Object Oriented Programming";
    course1.courseCode = "CS202";
    course1.credits = 4;
    course1.instructorName = "Nguyen Van A";

    course1.displayInfo();

    if (course1.isHighCredit()) {
        cout << "This is a high credit course." << endl;
    } else {
        cout << "This is not a high credit course." << endl;
    }

    if (course1.isLabRequired()) {
        cout << "This course requires a lap." << endl;
    } else {
        cout << "This course doesn't require a lap." << endl;
    }

    return 0;
}
