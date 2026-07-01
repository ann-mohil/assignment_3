//
// Created by Admin on 01.07.2026.
//
#include "Text.h"
#include <string>

Text::Text() {}

Text::~Text() {
    for (Line* line : lines) {
        delete line;
    }
    lines.clear();
}

void Text::add_line(Line *line) {
    lines.push_back(line);
}

void Text::print() const {
    for (const auto* line : lines) {
        line->print();
    }
}

std::string Text::serialize() const {
    std::string info = " ";
    for (const auto* line : lines) {
        info += line->serialize() + "\n";
    }
    return info;
}
