//
// Created by drew on 3/10/18.
//

#include <string.h>
#include <iostream>
#include <set>

using namespace std;



#ifndef EE450PROJECT_DICTIONARY_H
#define EE450PROJECT_DICTIONARY_H

class Dictionary {
private:
    string* word;
    string* definition;
    long size = 0;
    Dictionary** dictionaries;
    static const int DICTIONARY_SIZE = 57;
    bool put(string &, string &, int);
    string* get(string &, int);
    string* remove(string &, int);
    int getLetterIndex(char);
    char getLetterFromIndex(int);
    set<string*>* suffix(string, int);
    void addAllSuffixes(set<string*>*);

public:
    Dictionary();
    ~Dictionary();
    bool put(string &, string &);
    string* get(string);
    string* remove(string);
    set<string*>* suffix(string);
    long getSize();
};




#endif //EE450PROJECT_DICTIONARY_H
