//
// Created by Admin on 01.07.2026.
//

#ifndef ASSIGNMENT_3_TEXT_H
#define ASSIGNMENT_3_TEXT_H
#include <vector>
#include "Line.h"
class Text {
    std::vector<Line*> lines;
public:
    Text();
    ~Text();

    void add_line(Line* line);
    void print() const;
    std::string serialize() const;
    void clear();
    void deserialize(const std::string& text);
    void toggle_checked(int idx);
};
#endif //ASSIGNMENT_3_TEXT_H
