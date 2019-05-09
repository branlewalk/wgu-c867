#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"
#include "degree.h"

class NetworkStudent : public Student  {

public:

    void Print();
    Degree GetDegreeProgram();
    NetworkStudent(string newStudentID, string newFirstName, string newLastName,
            string newEmailAddress, int newAge, int* days);
    ~NetworkStudent();

};

#endif