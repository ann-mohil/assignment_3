//
// Created by Admin on 16.06.2026.
//
#include "cipher_api.h"
#include <iostream>
#include <dlfcn.h>


typedef void* cipher_t;

typedef cipher_t (*create_ceasar_func)(int);
typedef cipher_t (*create_vigenere_func)(const char*);
typedef char* (*encrypt_func)(cipher_t*, const char*);
typedef char* (*decrypt_func)(cipher_t*, const char*);
typedef void (*destroy_func)(cipher_t*);
typedef void (*free_func)(char*);


int main() {

    const char* lib_path = "./libcipher.dylib";

    void* handle = dlopen("./libcipher.so", RTLD_LAZY);
    if (!handle) {
        std::cout << "Library loading error: " << dlerror() << std::endl;
        return 1;
    }
    std::cout << "Library loaded at runtime" << std::endl;

    auto cipher_create_ceasar = (create_ceasar_func)dlsym(handle, "cipher_create_ceasar");
    auto cipher_create_vigenere = (create_vigenere_func)dlsym(handle, "cipher_create_vigenere");
    auto cipher_encrypt = (encrypt_func)dlsym(handle, "cipher_encrypt");
    auto cipher_decrypt = (decrypt_func)dlsym(handle, "cipher_decrypt");
    auto cipher_destroy = (destroy_func)dlsym(handle, "cipher_destroy");
    auto cipher_free = (free_func)dlsym(handle, "cipher_free");

    if (!cipher_create_ceasar || !cipher_create_vigenere || !cipher_encrypt || !cipher_decrypt || !cipher_destroy || !cipher_free) {
        std::cout << "Failed to resolve function pointers" << std::endl;
        dlclose(handle);
        return 1;
    }

    std::cout << "Function pointers resolved" << std::endl;
    std::cout << "cipher_create_caesar: " << (void*)cipher_create_ceasar << std::endl;
    std::cout << "cipher_create_vigenere: " << (void*)cipher_create_vigenere << std::endl;
    std::cout << "cipher_encrypt: " << (void*)cipher_encrypt << std::endl;
    std::cout << "cipher_decrypt: " << (void*)cipher_decrypt << std::endl;

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
        dlclose(handle);
        return 1;
    }

    char* encrypted = cipher_encrypt(&cipher, text.c_str());
    std::cout << "Encrypted: " << encrypted << std::endl;


    char* decrypted = cipher_decrypt(&cipher, encrypted);
    std::cout << "Decrypted: " << decrypted << std::endl;


    cipher_free(encrypted);
    cipher_free(decrypted);
    cipher_destroy(&cipher);


    std::cout << "Closing library.." << std::endl;
    dlclose(handle);
    std::cout << "Closed" << std::endl;

    return 0;
}