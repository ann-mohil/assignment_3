//
// Created by Admin on 16.06.2026.
//

#include "VigenereCipher.h"
#include <string>

VigenereCipher::VigenereCipher(const std::string &k) {
    key = k;
}

std::string VigenereCipher::encrypt(const std::string& text) {
    std::string result = "";

    int keyIdx = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result += (((text[i] - 'A' + (key[keyIdx] - 'A')) + 26) % 26) + 'A';
            keyIdx = (keyIdx + 1) % key.length();
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            result += (((text[i] - 'a' + (key[keyIdx] - 'A')) + 26) % 26) + 'a';
            keyIdx = (keyIdx + 1) % key.length();
        }
        else {
            result += text[i];
        }
    }

    return result;
}

std::string VigenereCipher::decrypt(const std::string& text) {
    std::string result = "";

    int keyIdx = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result += (((text[i] - 'A' - (key[keyIdx] - 'A')) + 26) % 26) + 'A';
            keyIdx = (keyIdx + 1) % key.length();
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            result += (((text[i] - 'a' - (key[keyIdx] - 'A')) + 26) % 26) + 'a';
            keyIdx = (keyIdx + 1) % key.length();
        }
        else {
            result += text[i];
        }
    }

    return result;
}
