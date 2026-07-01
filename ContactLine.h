//
// Created by Admin on 01.07.2026.
//

#ifndef ASSIGNMENT_3_CONTACTLINE_H
#define ASSIGNMENT_3_CONTACTLINE_H
#include "Line.h"

class ContactLine: public Line{
    std::string name;
    std::string surname;
    std::string email;
public:
    ContactLine(const std::string& n, const std::string& s, const std::string& em): name(n), surname(s), email(em) {}
    void print() const override {
        std::cout << "Contact:" << name << "" << surname
        << ", E-mail: " << email << std::endl;
    }

    std::string serialize() const override {
        return "Contact: " + name + " " + surname + ", E-mail: " + email;
    }

};
#endif //ASSIGNMENT_3_CONTACTLINE_H
