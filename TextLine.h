//
// Created by Admin on 01.07.2026.
//

#ifndef ASSIGNMENT_3_TEXTLINE_H
#define ASSIGNMENT_3_TEXTLINE_H
#include "Line.h"

class TextLine: public Line {
    std::string text;
public:
    TextLine(std::string t): text(t) {}
    void print() const override {std::cout << "Text: " << text << std::endl;}
    std::string serialize() const override {return "Text: " + text;}
};
#endif //ASSIGNMENT_3_TEXTLINE_H
