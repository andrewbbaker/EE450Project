//
// Created by drew on 3/13/18.
//

#include <string.h>
#include <vector>
#include "Dictionary.h"
#include <fstream>
#include <map>

using namespace std;

#ifndef EE450PROJECT_FILEREADER_H
#define EE450PROJECT_FILEREADER_H


class FileReader {
public:
    FileReader();
    ~FileReader();

    void read(string);
    void read(string, EE450PROJECT_DICTIONARY_H :: Dictionary);
    void read(string, map<string, string>);

    string SPLITTING_CHARACTERS = " :: ";

private:
    vector<string> split(string, string);
    string trim(string);

};


#endif //EE450PROJECT_FILEREADER_H
