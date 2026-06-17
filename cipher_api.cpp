//
// Created by Admin on 16.06.2026.
//

#include "cipher_api.h"
#include "CeasarCipher.h"
#include "VigenereCipher.h"
#include <cstring>

extern "C" {

cipher_t cipher_create_ceasar(int key) {
    return static_cast<cipher_t>(new CeasarCipher(key));
}

cipher_t cipher_create_vigenere(const char* key) {
    return static_cast<cipher_t>(new VigenereCipher(key));
}

char* cipher_encrypt(cipher_t* cipher, const char* text) {
    Cipher* c = static_cast<Cipher *>(*cipher);
    std::string result = c -> encrypt(text);

    char* c_str = new char[result.length() + 1];
    std:strcpy(c_str, result.c_str());
    return c_str;
}

char* cipher_decrypt(cipher_t* cipher, const char* text) {
    Cipher* c = static_cast<Cipher *>(*cipher);
    std::string result = c -> decrypt(text);

    char* c_str = new char[result.length() + 1];
    std:strcpy(c_str, result.c_str());
    return c_str;
}

void cipher_destroy(cipher_t* cipher) {
    Cipher* c = static_cast<Cipher *>(*cipher);
    delete c;
}

void cipher_free(char* str) {
    delete[] str;
}
}