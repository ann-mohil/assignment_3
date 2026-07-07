//
// Created by Admin on 02.07.2026.
//
#include "ContactLine.h"
#include <string>
#include <iostream>

void ContactLine::print() const {
    std::cout << "Contact - " << name << " " << surname
        << ", E-mail: " << email << std::endl;
}

std::string ContactLine::serialize() const {
    return "Contact - " + name + " " + surname + ", E-mail: " + email;
}

ContactLine *ContactLine::deserialize(const std::string &raw) {
    const std::string prefix = "Contact - ";
    if (raw.rfind(prefix, 0) != 0) {
        return nullptr;
    }

    std::string rest = raw.substr(prefix.size());
    const std::string email_marker = ", E-mail: ";
    size_t marker_idx = rest.find(email_marker);
    if (marker_idx == std::string::npos) {
        return nullptr;
    }
    std::string full_name = rest.substr(0, marker_idx);
    std::string email = rest.substr(marker_idx + email_marker.size());

    size_t space_idx = full_name.find(' ');
    std::string name;
    std::string surname;
    if (space_idx != std::string::npos) {
        name = full_name.substr(0, space_idx);
    }
    else {
        name = full_name;
    }
    if (space_idx != std::string::npos) {
        surname = full_name.substr(space_idx + 1);
    }
    else {
        surname = "";
    }

    return new ContactLine(name, surname, email);
}
