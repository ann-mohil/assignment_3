//
// Created by Admin on 16.06.2026.
//

#include "CeasarCipher.h"
#include <string>

CeasarCipher::CeasarCipher(int k) {
    key = k;
}

std::string CeasarCipher::encrypt(const std::string &text) {
    std::string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result += ((text[i] - 'A' + key) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            result += ((text[i] - 'a' + key) % 26) + 'a';
        }
        else {
            result += text[i];
        }
    }

    return result;
}

std::string CeasarCipher::decrypt(const std::string &text) {
    std::string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result += (((text[i] - 'A' - key) + 26) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            result += (((text[i] - 'a' - key) + 26) % 26) + 'a';
        }
        else {
            result += text[i];
        }
    }

    return result;
}