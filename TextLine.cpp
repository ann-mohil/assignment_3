//
// Created by Admin on 02.07.2026.
//
#include "TextLine.h"
#include <string>
#include <iostream>

void TextLine::print() const {
    {std::cout << "Text: " << text << std::endl;}
}

std::string TextLine::serialize() const {
    return "Text: " + text;
}

TextLine* TextLine::deserialize(const std::string& raw) {
    const std::string prefix = "Text: ";
    if (raw.rfind(prefix, 0) != 0) {
        return nullptr;
    }
    return new TextLine(raw.substr(prefix.size()));
}
