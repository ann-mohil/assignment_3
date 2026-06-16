//
// Created by Admin on 16.06.2026.
//

#ifndef ASSIGNMENT_3_CIPHER_H
#define ASSIGNMENT_3_CIPHER_H
#include <string>


class Cipher {
public:
    virtual ~Cipher() = default;
    virtual std::string encrypt(const std::string& text) = 0;
    virtual std::string decrypt(const std::string& text) = 0;
};


#endif //ASSIGNMENT_3_CIPHER_H
