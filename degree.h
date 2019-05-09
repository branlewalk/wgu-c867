#ifndef DEGREE_H
#define DEGREE_H

#include <map>
#include <string>

using namespace std;

enum Degree { SECURITY, NETWORKING, SOFTWARE};
const map<string, Degree> stringToDegree {
        {"SECURITY",   SECURITY},
        {"NETWORK", NETWORKING},
        {"SOFTWARE",   SOFTWARE}
};

#endif
