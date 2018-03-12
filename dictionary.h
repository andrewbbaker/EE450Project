//
// Created by drew on 3/10/18.
//

#include <string.h>
#include <iostream>
#include <set>

using namespace std;



#ifndef EE450PROJECT_DICTIONARY_H
#define EE450PROJECT_DICTIONARY_H

class dictionary {
private:
    string word;
    string definition;
    dictionary** dictionaries;
    static int DICTIONARY_SIZE final = 26;
    void put(string, string, int);
    string get(string, int);
    string remove(string, int);
    int getLetterIndex(char);
    set<string> suffix(string, int);
    void addAllSuffixes(set<string>*);

public:
    dictionary();
    ~dictionary();
    void put(string, string);
    string get(string);
    string remove(string);
    set<string> suffix(string);
};




#endif //EE450PROJECT_DICTIONARY_H
