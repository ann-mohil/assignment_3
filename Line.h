//
// Created by Admin on 01.07.2026.
//
#include <string>
#ifndef ASSIGNMENT_3_LINE_H
#define ASSIGNMENT_3_LINE_H
class Line {
public:
    virtual void print() const = 0;
    virtual std::string serialize() const = 0;
    virtual ~Line() {};

    static Line* deserialize(const std::string& raw);
};
#endif //ASSIGNMENT_3_LINE_H
