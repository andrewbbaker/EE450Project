//
// Created by drew on 3/10/18.
//

#include "dictionary.h"

dictionary :: dictionary() {
    word = NULL;
    definition = NULL;
    dictionaries = new dictionary*[26];

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        delete(dictionaries[i]);
        dictionaries[i] = NULL;
    }
}

dictionary ::~dictionary() {

}

void dictionary :: put(string word, string definition) {
    put(word, definition, word.size());
}

void dictionary :: put(string word, string definition, int currentIndex) {
    if (currentIndex == 0) {
        this -> word = word;
        this -> definition = definition;
        return;
    }

    currentIndex -= 1;
    int currentLetterIndex = getLetterIndex(word[currentLetterIndex]);
    if (dictionaries[currentLetterIndex] == NULL) {
        dictionaries[currentLetterIndex] = new dictionary();
    }

    dictionaries[currentLetterIndex] -> put(word, definition, currentLetterIndex);
}

string dictionary :: get(string word) {
    return get(word, word.size());
}

string dictionary :: get(string word, int currentIndex) {
    if (currentIndex == 0) {
        return definition;
    }

    currentIndex -= 1;
    int currentLetterIndex = getLetterIndex(word[currentLetterIndex]);
    if (dictionaries[currentLetterIndex] == NULL) {
        return NULL;
    }

    dictionaries[currentLetterIndex] -> get(word, currentLetterIndex);
}

string dictionary :: remove(string word) {
    return remove(word, word.size());
}

string dictionary :: remove(string word, int currentIndex) {
    if (currentIndex == 0) {
        string oldDefinition = definition;
        this -> word = NULL;
        this -> definition = NULL;
        return oldDefinition;
    }

    currentIndex -= 1;
    int currentLetterIndex = getLetterIndex(word[currentLetterIndex]);
    if (dictionaries[currentLetterIndex] == NULL) {
        return NULL;
    }

    dictionaries[currentLetterIndex] -> remove(word, currentLetterIndex);
}

set<string> dictionary :: suffix(string word) {
    return suffix(word, word.size());
}

set<string> dictionary :: suffix(string word, int currentIndex) {
    if (currentIndex == 0) {
        set<string> *suffixes = new set();
        suffixes -> insert(word);
        addAllSuffixes(suffixes);
        return *suffixes;
    }

    currentIndex -= 1;
    int currentLetterIndex = getLetterIndex(word[currentLetterIndex]);
    if (dictionaries[currentLetterIndex] == NULL) {
        return NULL;
    }

    dictionaries[currentLetterIndex] -> suffix(word, currentLetterIndex);
}

void dictionary :: addAllSuffixes(set<string> *suffixes) {
    if (word != NULL) {
        suffixes -> insert(word);
    }

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (dictionaries[i] != NULL) {
            dictionaries[i] -> addAllSuffixes(suffixes);
        }
    }

}

int dictionary :: getLetterIndex(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return letter - 'a';
    } else if (letter >='A' && letter <= 'Z') {
        return letter - 'A';
    } else {
        string message = string("input included the non letter \'") + letter + "\'";
        throw invalid_argument(message);
    }
}