#include <iostream>
#include <string>

using namespace std;

#include "softwareStudent.h"


void SoftwareStudent::Print() {
    cout << "Student ID: " << studentID << ", ";
    cout << "Name: " << firstName << " " << lastName << ", ";
    cout << "Email: " << emailAddress << ", ";
    cout << "Age: " << age << ", ";
    cout << "Days left in Course: ";
    for (int i = 0; i < COURSES; i++) {
        cout << *(daysToCompCourse + i) << ", ";
    }
    cout << "Degree: Software" << endl;
}

Degree SoftwareStudent::GetDegreeProgram() {
    return SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string newStudentID, string newFirstName, string newLastName,
                                 string newEmailAddress, int newAge, int *days) :
        Student(newStudentID, newFirstName, newLastName, newEmailAddress, newAge,
                days) {

}




