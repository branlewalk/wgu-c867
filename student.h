#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

#include "degree.h"

class Student {

public:

    void SetStudentID (string newStudentID);
    void SetFirstName (string newFirstName);
    void SetLastName (string newLastName);
    void SetEmailAddress (string newEmailAddress);
    void SetAge (int newAge);
    void SetDaysToCompCourse (int days[]);
    virtual void Print() = 0;
    virtual Degree GetDegreeProgram() = 0;

//    Student();
    Student(string newStudentID, string newFirstName, string newLastName,
            string newEmailAddress, int newAge, int* daysToCompCourse);
    ~Student();

    string GetStudentID ();
    string GetFirstName ();
    string GetLastName ();
    string GetEmailAddress ();
    int    GetAge ();
    int*   GetDaysToCompCourse ();

protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* daysToCompCourse;
    const int COURSES = 3;

};

#endif


