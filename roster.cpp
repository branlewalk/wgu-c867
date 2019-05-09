#include "roster.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"

#include <string>
#include <array>
#include <sstream>
#include <iostream>

#define CAPACITY 100
using namespace std;

void Roster::addStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
                        int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {

    int* daysInCourse = new int[3];
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
    Student *student = NULL;
    switch (degreeProgram) {
        case NETWORKING :
            student = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse);
            break;
        case SOFTWARE :
            student = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse);
            break;
        case SECURITY :
            student = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse);
            break;
    }
    if (student != NULL) {
        if (countStudent < CAPACITY) {
            classRosterArray[countStudent] = student;
            countStudent++;
        }
    }
}

void Roster::removeStudent(string studentID) {
    bool studentFound = false;
    for (int i = 0; i < countStudent; i++) {
        if (classRosterArray[i]->GetStudentID().compare(studentID) == 0) {
            studentFound = true;
            for (int j = i; j < countStudent; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            countStudent--;
        }
        else if (studentFound == true) {

        }
    }
    if (studentFound == true) {
        cout << "Student with Student ID: \"" << studentID << "\" does not exist." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < countStudent; i++) {
        classRosterArray[i]->Print();
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    const int NUM_COURSES = 3;
    int averageDaysInCourse = 0;
    int sumDaysInCourses = 0;
    for (int i = 0; i < countStudent; i++) {
        if (classRosterArray[i]->GetStudentID().compare(studentID) == 0) {
            int *daysOfCourses = classRosterArray[i]->GetDaysToCompCourse();
            for (int j = 0; j < NUM_COURSES; j++) {
                sumDaysInCourses += daysOfCourses[j];
            }
            averageDaysInCourse = sumDaysInCourses / NUM_COURSES;
            cout << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName()
            << "'s average days in his/her courses: "<< averageDaysInCourse << endl;
        }
    }
    cout << endl;
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < countStudent; i++) {
        string emailAddress = classRosterArray[i]->GetEmailAddress();
        if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos ||
            emailAddress.find(' ') != string::npos) {
            cout << "Invalid email: " << emailAddress << " for student: " << classRosterArray[i]->GetFirstName();
            cout << " " << classRosterArray[i]->GetLastName() << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
    for (int i = 0; i < countStudent; i++) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
    cout << endl;
}

Roster::Roster() {
    countStudent = 0;
    classRosterArray = new Student *[CAPACITY];
}

Roster::~Roster() {
    delete classRosterArray;
}

int main() {

    Roster *classRoster = new Roster;

    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                  "A5,Brandon,Walker,bwal113@wgu.edu,34,60,57,19,SOFTWARE",
                                  ""};

    for (int i = 0;  !studentData[i].empty(); i++) {
        istringstream data(studentData[i]);
        string id, fname, lname, email, ageString, day1String, day2String, day3String, programString;
        Degree program;
        int age, day1, day2, day3;
        getline(data, id, ',');
        getline(data, fname, ',');
        getline(data, lname, ',');
        getline(data, email, ',');
        getline(data, ageString, ',');
        getline(data, day1String, ',');
        getline(data, day2String, ',');
        getline(data, day3String, ',');
        getline(data, programString, ',');
        age = stoi(ageString);
        day1 = stoi(day1String);
        day2 = stoi(day2String);
        day3 = stoi(day3String);
        program = stringToDegree.at(programString);
        classRoster->addStudent(id, fname, lname, email, age, day1, day2, day3, program);
    }
    cout << "Program name: CLASS ROSTER - Course Name: SCRIPTING AND PROGRAMMING APPLICATIONS — C867" << endl;
    cout << "Programming Language: C++ - Student ID: 000837590 - Name: Brandon Walker" << endl;
    cout << endl;
    classRoster->printAll();
    classRoster->printInvalidEmails();
    classRoster->printAverageDaysInCourse("A5");
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->removeStudent("A3");
    classRoster->removeStudent("A3");
    delete classRoster;
}