//
// Created by Admin on 08.07.2026.
//
#include "ChecklistLine.cuh"
#include <iostream>

void ChecklistLine::print() const {
    std::cout << "[ " << (checked ? "x" : " ") << " ] " << item << std::endl;
}

std::string ChecklistLine::serialize() const {
    return "[ " + std::string (checked ? "x" : " ") + " ] " + item;
}

ChecklistLine *ChecklistLine::deserialize(const std::string &raw) {
    if (raw.size() < 6 || raw[0] != '[' || raw[4] != ']') {
        return nullptr;
    }
    bool checked = (raw[2] == 'x');
    std::string item = raw.substr(6);
    return new ChecklistLine(item, checked);
}
