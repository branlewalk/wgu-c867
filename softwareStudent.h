#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student {

public:
    void Print();
    Degree GetDegreeProgram();
    SoftwareStudent(string newStudentID, string newFirstName, string newLastName,
    string newEmailAddress, int newAge, int* days);
    ~SoftwareStudent();

};

#endif




