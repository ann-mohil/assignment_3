//
// Created by Admin on 01.07.2026.
//
#include "Text.h"
#include <string>
#include <sstream>

Text::Text() {}

Text::~Text() {
    clear();
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

void Text::clear() {
    for (Line* line : lines) {
        delete line;
    }
    lines.clear();
}

void Text::deserialize(const std::string &text) {
    clear();
    std::istringstream stream(text);
    std::string raw_line;

    while (std::getline(stream, raw_line)) {
        if (raw_line.empty()) {
            continue;
        }
        Line* line  = Line::deserialize(raw_line);
        lines.push_back(line);
    }
}
