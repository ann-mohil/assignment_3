//
// Created by Admin on 09.07.2026.
//

#include "CipherLoader.h"

#include <dlfcn.h>


CipherLoader::CipherLoader(CipherType type, int int_key, const std::string &str_key) {
    handle = dlopen("./libcipher.dylib", RTLD_LAZY);
    if (!handle) {
        throw std::runtime_error(std::string("Library loading error: ") + dlerror());
    }

    cipher_create_ceasar = (create_caesar_func)dlsym(handle, "cipher_create_ceasar");
    cipher_create_vigenere = (create_vigenere_func)dlsym(handle, "cipher_create_vigenere");
    cipher_encrypt = (encrypt_func)dlsym(handle, "cipher_encrypt");
    cipher_decrypt = (decrypt_func)dlsym(handle, "cipher_decrypt");
    cipher_destroy = (destroy_func)dlsym(handle, "cipher_destroy");
    cipher_free = (free_func)dlsym(handle, "cipher_free");

    if (!cipher_create_ceasar || !cipher_create_vigenere || !cipher_encrypt || !cipher_decrypt || !cipher_destroy || !cipher_free) {
        dlclose(handle);
        handle = nullptr;
        throw std::runtime_error("Failed to resolve pointers");
    }

    if (type == CipherType::Ceasar) {
        cipher = cipher_create_ceasar(int_key);
    }
    else {
        cipher = cipher_create_vigenere(str_key.c_str());
    }

    if (!cipher) {
        dlclose(handle);
        handle = nullptr;
        throw std::runtime_error("Failed to create cipher object");
    }
}

CipherLoader::~CipherLoader() {
    if (cipher && cipher_destroy) {
        cipher_destroy(&cipher);
    }
    if (handle) {
        dlclose(handle);
    }
}

std::string CipherLoader::encrypt(const std::string& text) {
    char* result = cipher_encrypt(&cipher, text.c_str());
    std::string encrypted(result);
    cipher_free(result);
    return encrypted;
}

std::string CipherLoader::decrypt(const std::string& text) {
    char* result = cipher_decrypt(&cipher, text.c_str());
    std::string decrypted(result);
    cipher_free(result);
    return decrypted;
}
