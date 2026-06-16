//
// Created by Admin on 16.06.2026.
//

#ifndef ASSIGNMENT_3_CEASARCIPHER_H
#define ASSIGNMENT_3_CEASARCIPHER_H
#include "Cipher.h"


class CeasarCipher: public Cipher{
private:
    int shift;

public:
    CeasarCipher(int k);

    std::string encrypt(const std::string &text) override;
    std::string decrypt(const std::string &text) override;
};


#endif //ASSIGNMENT_3_CEASARCIPHER_H
