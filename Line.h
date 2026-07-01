//
// Created by Admin on 01.07.2026.
//

#ifndef ASSIGNMENT_3_LINE_H
#define ASSIGNMENT_3_LINE_H
class Line {
public:
    virtual void print() const = 0;
    virtual std::string serialize() const = 0;
    virtual ~Line() {};
};
#endif //ASSIGNMENT_3_LINE_H
