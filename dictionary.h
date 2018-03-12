//
// Created by drew on 3/10/18.
//

#include <string.h>
#include <iostream>

using namespace std;



#ifndef EE450PROJECT_DICTIONARY_H
#define EE450PROJECT_DICTIONARY_H

class dictionary {
private:
    string word;
    string definition;
    dictionary* dictionaries;
    static int DICTIONARY_SIZE final = 26;
    void put(string, string, int);
    string get(string, int);
    string remove(string, int);

public:
    dictionary();
    ~dictionary();
    void put(string, string);
    string get(string);
    string remove(string);
};

dictionary :: dictionary() {
    word = nullptr;
    definition = nullptr;
    dictionaries = new dictionary[26];

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        dictionaries[i] = nullptr;
    }
}

dictionary ::~dictionary() {

}

void dictionary :: put(string word, string definition) {
    put(word, definition, word.size());
}

void dictionary :: put(string word, string definition, int currentIndex) {

}

string dictionary :: get(string word) {
    return get(word, word.size());
}

string dictionary :: get(string word, int currentIndex) {

}

string dictionary :: remove(string word) {

}

string dictionary :: remove(string word, int currentIndex) {

}




#endif //EE450PROJECT_DICTIONARY_H
