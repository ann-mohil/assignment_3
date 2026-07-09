//
// Created by Admin on 09.07.2026.
//

#ifndef ASSIGNMENT_3_CIPHERLOADER_H
#define ASSIGNMENT_3_CIPHERLOADER_H
#pragma once
#include <string>

enum class CipherType {
    Ceasar,
    Vigenere
};

typedef void* cipher_t;

class CipherLoader {
    void* handle = nullptr;
    cipher_t cipher = nullptr;

    typedef cipher_t(*create_caesar_func)(int);
    typedef cipher_t(*create_vigenere_func)(const char*);
    typedef char* (*encrypt_func)(cipher_t*, const char*);
    typedef char* (*decrypt_func)(cipher_t*, const char*);
    typedef void (*destroy_func)(cipher_t*);
    typedef void (*free_func)(char*);

    create_caesar_func cipher_create_ceasar = nullptr;
    create_vigenere_func cipher_create_vigenere = nullptr;
    encrypt_func cipher_encrypt = nullptr;
    decrypt_func cipher_decrypt = nullptr;
    destroy_func cipher_destroy = nullptr;
    free_func cipher_free = nullptr;
public:
    CipherLoader(CipherType type, int int_key, const std::string& str_key);
    ~CipherLoader();

    CipherLoader(const CipherLoader&) = delete;
    CipherLoader& operator = (const CipherLoader&) = delete;

    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);
};

#endif //ASSIGNMENT_3_CIPHERLOADER_H
