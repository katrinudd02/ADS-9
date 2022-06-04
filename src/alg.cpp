// Copyright 2021 NNTU-CS
#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
#include <string>
#include <cstring>
#include <sstream>

BST makeTree(const char* filename) {
    std::string word, line;
    BST mTree;
    char* pch;
    char* buffer;
    const char* delim = " ,.-?!;&*#()=+_`~@^$%№/[]:\'\"";

    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return -1;
    }

    while (getline(file, line)) {
        buffer = new char[line.size() + 1];
        std::copy(line.begin(), line.end(), buffer);
        buffer[line.size()] = '\0';
        pch = strtok(buffer, delim);
        while (pch != NULL) {
            word = pch;
            word = lower(word);
            if (checkWord(word)) {
                mTree.add(word);
            }
            pch = strtok(NULL, delim);
        }
        delete[] buffer;
    }
    file.close();
    return mTree;
}

std::string lower(std::string word) {
    size_t len = word.length();
    int i;
    char ch;
    for (i = 0; i < len; i++) {
        ch = word[i];
        if (ch >= 'A' && ch <= 'Z')  word[i] = ch + 32;
    }
    return word;
}

bool checkWord(std::string word) {
    bool result = true;
    size_t len = word.length();
    int i;
    char ch;
    for (i = 0; i < len; i++) {
        ch = word[i];
        if (ch < 'a' || ch > 'z') {
            result = false;
            break;
        }
    }
    return result;
}
