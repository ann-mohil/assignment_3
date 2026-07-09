//
// Created by Admin on 16.06.2026.
//
#include "Text.h"
#include "TextLine.h"
#include "ContactLine.h"
#include "ChecklistLine.cuh"
#include "CipherLoader.h"
#include <iostream>
#include <sstream>
#include <fstream>

class TextEditor {
    Text text;
public:
    void run() {
        int command;
        while (true) {
            print_menu();
            if (!(std::cin >> command)) break;
            std::cin.ignore(10000, '\n');

            if (command == 0) {
                std::cout << "Exit\n";
                break;
            }

            switch (command) {
                case 1:
                    add_textline();
                    break;
                case 2:
                    add_contactline();
                    break;
                case 3:
                    add_checklistline();
                    break;
                case 4:
                    text.print();
                    break;
                case 5:
                    save_to_file();
                    break;
                case 6:
                    load_from_file();
                    break;
                case 7:
                    encrypt();
                    break;
                case 8:
                    decrypt();
                    break;
                case 9:
                    toggle_checklist_status();
                    break;
                default:
                    std::cout << "Unknown command\n";
                    break;
            }
        }
    }
private:
    void print_menu() const {
        std::cout << "Menu\n";
        std::cout << "1 - add text line\n";
        std::cout << "2 - add contact line\n";
        std::cout << "3 - add checklist line\n";
        std::cout << "4 - print all\n";
        std::cout << "5 - save to file\n";
        std::cout << "6 - load from file\n";
        std::cout << "7 - encrypt\n";
        std::cout << "8 - decrypt\n";
        std::cout << "9 - toggle status\n";
        std::cout << "0 - exit..\n";
    }

    void add_textline() {
        std::cout << "Enter text: ";
        std::string content;
        std::getline(std::cin, content);
        text.add_line(new TextLine(content));
        std::cout << "Text line added\n";
    }

    void add_contactline() {
        std::string name, surname, email;
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        std::cout << "Enter surname: ";
        std::getline(std::cin, surname);
        std::cout << "Enter e-mail: ";
        std::getline(std::cin, email);
        text.add_line(new ContactLine(name, surname, email));
        std::cout << "Contact line added\n";
    }

    void add_checklistline() {
        std::string item;
        std::cout << "Enter checklist item: ";
        std::getline(std::cin, item);
        std::cout << "Checked? (1 - yes / 0 - no): ";
        int checked;
        std::cin >> checked;
        std::cin.ignore(10000, '\n');
        text.add_line(new ChecklistLine(item, checked != 0));
        std::cout << "Checklist line added\n";
    }

    void save_to_file() {
        std::cout << "Enter file path: ";
        std::string path;
        std::getline(std::cin, path);
        std::ofstream file(path);
        if (!file) {
            std::cout << "Cannot open file\n";
            return;
        }
        file << text.serialize();
        std::cout << "Saved\n";
    }

    void load_from_file() {
        std::cout << "Enter file path: ";
        std::string path;
        std::getline(std::cin, path);
        std::ifstream file(path);
        if (!file) {
            std::cout << "Cannot open file\n";
            return;
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        text.deserialize(buffer.str());
        std::cout << "Loaded\n";
    }

    void encrypt() {
        std::cout << "Enter input file path: ";
        std::string input_path;
        std::getline(std::cin, input_path);
        std::cout << "Enter output file path: ";
        std::string output_path;
        std::getline(std::cin, output_path);

        std::ifstream input(input_path);
        if (!input) {
            std::cout << "Cannot open file\n";
            return;
        }
        std::stringstream buffer;
        buffer << input.rdbuf();
        std::string content = buffer.str();

        std::cout << "Choose Cipher: 1 - Caesar, 2 - Vigenere\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore(10000, '\n');

        try {
            std::string encrypted;
            if (choice == 1) {
                int key;
                std::cout << "Enter Caesar key: ";
                std::cin >> key;
                std::cin.ignore(10000, '\n');
                CipherLoader loader(CipherType::Ceasar, key, "");
                encrypted = loader.encrypt(content);
            }
            else {
                std::string key;
                std::cout << "Enter Vigenere key: ";
                std::getline(std::cin, key);
                CipherLoader loader(CipherType::Vigenere, 0, key);
                encrypted = loader.encrypt(content);
            }

            std::ofstream output(output_path);
            output << encrypted;
            std::cout << "File encrypted and saved\n";
        } catch (const std::exception& e) {
            std::cout << "Failed: " << e.what() << "\n";
        }
    }

    void decrypt() {
        std::cout << "Enter input file path: ";
        std::string input_path;
        std::getline(std::cin, input_path);
        std::cout << "Enter output file path: ";
        std::string output_path;
        std::getline(std::cin, output_path);

        std::ifstream input(input_path);
        if (!input) {
            std::cout << "Cannot open file\n";
            return;
        }
        std::stringstream buffer;
        buffer << input.rdbuf();
        std::string content = buffer.str();

        std::cout << "Choose Cipher: 1 - Caesar, 2 - Vigenere\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore(10000, '\n');

        try {
            std::string decrypted;
            if (choice == 1) {
                int key;
                std::cout << "Enter Caesar key: ";
                std::cin >> key;
                std::cin.ignore(10000, '\n');
                CipherLoader loader(CipherType::Ceasar, key, "");
                decrypted = loader.decrypt(content);
            }
            else {
                std::string key;
                std::cout << "Enter Vigenere key: ";
                std::getline(std::cin, key);
                CipherLoader loader(CipherType::Vigenere, 0, key);
                decrypted = loader.decrypt(content);
            }

            std::ofstream output(output_path);
            output << decrypted;
            std::cout << "File decrypted and saved\n";
        } catch (const std::exception& e) {
            std::cout << "Failed: " << e.what() << "\n";
        }
    }

    void toggle_checklist_status() {
        std::cout << "Enter line index: ";
        int idx;
        std::cin >> idx;
        std::cin.ignore(10000, '\n');
        text.toggle_checked(idx);
    }
};

int main() {
    TextEditor text_editor;
    text_editor.run();
    return 0;
}