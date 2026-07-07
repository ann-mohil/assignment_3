//
// Created by Admin on 01.07.2026.
//

#ifndef ASSIGNMENT_3_TEXTLINE_H
#define ASSIGNMENT_3_TEXTLINE_H
#include "Line.h"
#include <string>

class TextLine: public Line {
    std::string text;
public:
    TextLine(std::string t): text(t) {}
    void print() const override;
    std::string serialize() const override;
    static TextLine* deserialize(const std::string& raw);
};
#endif //ASSIGNMENT_3_TEXTLINE_H
