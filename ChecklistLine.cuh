//
// Created by Admin on 01.07.2026.
//

#ifndef ASSIGNMENT_3_CHECKLISTLINE_CUH
#define ASSIGNMENT_3_CHECKLISTLINE_CUH


#include "Line.h"

class ChecklistLine: public Line {
    std::string item;
    bool checked;
public:
    ChecklistLine(const std::string& i, bool c) : item(i), checked(c) {}
    void print() const override {
        std::cout << "[ " << (checked ? "x" : " ") << " ] " << item << std::endl;
    }
    std::string serialize() const override {return "Checked: " + std::to_string(checked) + "|" + item; }
};
#endif //ASSIGNMENT_3_CHECKLISTLINE_CUH
