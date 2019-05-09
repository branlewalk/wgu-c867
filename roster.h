#ifndef ROSTER_H
#define ROSTER_H

#include "degree.h"
#include "student.h"

#include <string>

using namespace std;

class Roster {

public:
    void addStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
                    int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
    void removeStudent(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degreeProgram);
    Roster();
    ~Roster();

private:
    Student** classRosterArray;
    int countStudent;
};

#endif




