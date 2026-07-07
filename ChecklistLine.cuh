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
    void print() const override;
    std::string serialize() const override;
    static ChecklistLine* deserialize(const std::string& raw);
};
#endif //ASSIGNMENT_3_CHECKLISTLINE_CUH
