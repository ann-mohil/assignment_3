//
// Created by Admin on 16.06.2026.
//

#ifndef ASSIGNMENT_3_VIGENERECIPHER_H
#define ASSIGNMENT_3_VIGENERECIPHER_H
#include "Cipher.h"


class VigenereCipher: public Cipher{
public:
    VigenereCipher(const std::string& k);

    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;

private:
    std::string key;

};

#endif //ASSIGNMENT_3_VIGENERECIPHER_H
