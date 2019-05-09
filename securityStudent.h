#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"
#include "degree.h"

class SecurityStudent : public Student {

public:
    void Print();
    Degree GetDegreeProgram();
    SecurityStudent(string newStudentID, string newFirstName, string newLastName,
    string newEmailAddress, int newAge, int* days);
    ~SecurityStudent();

};

#endif



