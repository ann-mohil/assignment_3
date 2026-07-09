//
// Created by Admin on 02.07.2026.
//
#include "Line.h"

#include "ChecklistLine.cuh"
#include "TextLine.h"
#include "ContactLine.h"

Line *Line::deserialize(const std::string& raw) {
    if (Line* line = ContactLine::deserialize(raw)) {
        return line;
    }
    if (Line* line = ChecklistLine::deserialize(raw)) {
        return line;
    }
    if (Line* line = TextLine::deserialize(raw)) {
        return line;
    }
    return new TextLine(raw);
}
