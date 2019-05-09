#include <iostream>
#include <string>

using namespace std;

#include "student.h"


void Student::SetStudentID(string newStudentID) {
    studentID = newStudentID;
}

void Student::SetFirstName(string newFirstName) {
    firstName = newFirstName;
}

void Student::SetLastName(string newLastName) {
    lastName = newLastName;
}

void Student::SetEmailAddress(string newEmailAddress) {
    emailAddress = newEmailAddress;
}

void Student::SetAge(int newAge) {
    age = newAge;
}

void Student::SetDaysToCompCourse(int days[]) {
    daysToCompCourse = days;
}

Student :: Student(string newStudentID, string newFirstName, string newLastName,
                   string newEmailAddress, int newAge, int* days) {
    daysToCompCourse = days;
    studentID = newStudentID;
    firstName = newFirstName;
    lastName = newLastName;
    emailAddress = newEmailAddress;
    age = newAge;
}

Student :: ~Student() {

}

string Student :: GetStudentID() {
    return studentID;
}

string Student :: GetFirstName() {
    return firstName;
}

string Student :: GetLastName() {
    return lastName;
}

string Student :: GetEmailAddress() {
    return emailAddress;
}

int Student :: GetAge() {
    return age;
}

int* Student :: GetDaysToCompCourse() {
    return daysToCompCourse;
}

