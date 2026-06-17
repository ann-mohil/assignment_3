//
// Created by Admin on 16.06.2026.
//
#include "cipher_api.h"
#include <iostream>

int main() {
    std::cout << "Caesar Cipher" << std::endl;
    cipher_t caesar = cipher_create_ceasar(3);

    const char* text = "ANNA";
    std::cout << "Original: " << text << std::endl;

    char* encrypted_ceasar = cipher_encrypt(&caesar, text);
    std::cout << "Encrypted: " << encrypted_ceasar << std::endl;

    char* decrypted_ceasar = cipher_decrypt(&caesar, encrypted_ceasar);
    std::cout << "Decrypted: " << decrypted_ceasar << std::endl;

    cipher_free(encrypted_ceasar);
    cipher_free(decrypted_ceasar);
    cipher_destroy(&caesar);

    std::cout << "Vigenere Cipher" << std::endl;

    cipher_t vigenere = cipher_create_vigenere("KEY");

    std::cout << "Original: " << text << std::endl;

    char* encrypted_vigenere = cipher_encrypt(&vigenere, text);
    std::cout << "Encrypted: " << encrypted_vigenere << std::endl;

    char* decrypted_vigenere = cipher_decrypt(&vigenere, encrypted_vigenere);
    std::cout << "Decrypted: " << decrypted_vigenere << std::endl;

    cipher_free(encrypted_vigenere);
    cipher_free(decrypted_vigenere);
    cipher_destroy(&vigenere);

    return 0;
}