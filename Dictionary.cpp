//
// Created by drew on 3/10/18.
//

#include "Dictionary.h"

Dictionary :: Dictionary() {
    word = nullptr;
    definition = nullptr;
    dictionaries = new Dictionary*[DICTIONARY_SIZE];

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        dictionaries[i] = nullptr;
    }
}

Dictionary ::~Dictionary() {

}

bool Dictionary :: put(string &word, string &definition) {
    return put(word, definition, word.size());
}

bool Dictionary :: put(string &word, string &definition, int currentIndex) {
    if (currentIndex == 0) {
        bool wordExists = this -> word != nullptr;
        this -> word = new string(word);
        this -> definition = new string(definition);
        if (!wordExists) {
            size++;
        }
        return wordExists;
    }

    currentIndex -= 1;
    int currentLetterIndex = getLetterIndex(word[currentIndex]);
    if (dictionaries[currentLetterIndex] == nullptr) {
        dictionaries[currentLetterIndex] = new Dictionary();
    }

    bool wordExists = dictionaries[currentLetterIndex] -> put(word, definition, currentIndex);
    if (!wordExists) {
        size++;
    }
}

string* Dictionary :: get(string word) {
    return get(word, word.size());
}

string* Dictionary :: get(string &word, int currentIndex) {
    if (currentIndex == 0) {
        return definition;
    }

    currentIndex -= 1;
    int currentLetterIndex = getLetterIndex(word[currentIndex]);
    if (dictionaries[currentLetterIndex] == nullptr) {
        return nullptr;
    }

    return dictionaries[currentLetterIndex] -> get(word, currentIndex);
}

string* Dictionary :: remove(string word) {
    return remove(word, word.size());
}

string* Dictionary :: remove(string &word, int currentIndex) {
    if (currentIndex == 0) {
        if (definition != nullptr) {
            size--;
        }
        string oldDefinition = *definition;

        this -> word = nullptr;
        this -> definition = nullptr;
        return &oldDefinition;
    }

    currentIndex -= 1;
    int currentLetterIndex = getLetterIndex(word[currentLetterIndex]);
    if (dictionaries[currentLetterIndex] == nullptr) {
        return nullptr;
    }

    string* oldWord = dictionaries[currentLetterIndex] -> remove(word, currentLetterIndex);
    if (oldWord != nullptr) {
        size--;
    }
    return oldWord;
}

set<string*>* Dictionary :: suffix(string word) {
    return suffix(word, word.size());
}

set<string*>* Dictionary :: suffix(string word, int currentIndex) {
    if (currentIndex == 0) {
        set<string*> *suffixes = new set<string*>();
        addAllSuffixes(suffixes);
        return suffixes;
    }

    currentIndex -= 1;
    int currentLetterIndex = getLetterIndex(word[currentLetterIndex]);
    if (dictionaries[currentLetterIndex] == nullptr) {
        return nullptr;
    }

    dictionaries[currentLetterIndex] -> suffix(word, currentLetterIndex);
}

void Dictionary :: addAllSuffixes(set<string*> *suffixes) {
    if (word != nullptr) {
        string* copy = new string(*word);
        suffixes -> insert(copy);
    }

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (dictionaries[i] != nullptr) {
            dictionaries[i] -> addAllSuffixes(suffixes);
        }
    }
}

long Dictionary::getSize() {
    return size;
}

int Dictionary :: getLetterIndex(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return letter - 'a';
    } else if (letter >='A' && letter <= 'Z') {
        return letter - 'A' + 26;
    } else if (letter == ' ') {
        return 52;
    } else if (letter == '-') {
        return 53;
    } else if (letter == '/') {
        return 54;
    } else if (letter == '\'') {
        return 55;
    } else if (letter == '.') {
        return 56;
    } else {
        string message = string("input included the non letter \'") + letter + "\'";
        throw invalid_argument(message);
    }
}

char Dictionary::getLetterFromIndex(int index) {
    if (index >= 0 && index < 26) {
        return 'a' + index;
    }if (index >= 26 && index < 52) {
        return 'A' + index - 26;
    } else if (index == 52) {
        return ' ';
    } else if (index == 53) {
        return '-';
    } else if (index == 54) {
        return '/';
    } else if (index == 55) {
        return '\'';
    } else if (index == 56) {
        return '.';
    } else {
        string message = string("invalid index");
        throw invalid_argument(message);
    }
}
