//
// Created by Admin on 16.06.2026.
//
#include "cipher_api.h"
#include <iostream>

int main() {
    int option;
    std::string text;
    std::cout << "Select cipher type: Caesar Cipher - 1\n Vigenere Cipher - 2\n >> ";
    std::cin >> option;
    std::cin.get();

    if (option != 1 && option != 2) {
        std::cout << "Invalid option" << std::endl;
        return 1;
    }

    std::cout << "Enter text to encrypt: ";
    std::getline(std::cin, text);

    cipher_t cipher = nullptr;

    if (option == 1) {
        int key;
        std::cout << "Enter Caesar key (int): ";
        std::cin >> key;

        cipher = cipher_create_ceasar(key);
    }
    else {
        std::string key;
        std::cout << "Enter Vigenere key (string): ";
        std::getline(std::cin, key);

        cipher = cipher_create_vigenere(key.c_str());
    }

    if (!cipher) {
        std::cout << "Failed creation" << std::endl;
        return 1;
    }

    char* encrypted = cipher_encrypt(&cipher, text.c_str());
    std::cout << "Encrypted: " << encrypted << std::endl;

    char* decrypted = cipher_decrypt(&cipher, encrypted);
    std::cout << "Decrypted: " << decrypted << std::endl;

    cipher_free(encrypted);
    cipher_free(decrypted);
    cipher_destroy(&cipher);

    return 0;
}