//
// Created by drew on 3/13/18.
//

#include "FileReader.h"

#include <unistd.h>
#define GetCurrentDir getcwd


using namespace std;

FileReader::FileReader() {

}

FileReader::~FileReader() {

}

void FileReader::read(string fileName) {
    ifstream file;
    file.open(fileName, ios :: in);
    string nextLine;

    while (getline(file, nextLine)) {
//        file >> nextLine;
        vector<string> wordDefinition = split(nextLine, SPLITTING_CHARACTERS);
        cout << wordDefinition[0] << " - " << wordDefinition[1] << endl;
    }

}

void FileReader::read(string fileName, ::Dictionary dictionary) {
    ifstream file;
    file.open(fileName, ios :: in);
    string nextLine;

    while (getline(file, nextLine)) {
        vector<string> wordDefinition = split(nextLine, SPLITTING_CHARACTERS);
        dictionary.put(wordDefinition[0], wordDefinition[1]);
    }

    set<string*> *allWords = dictionary.suffix("");

    for (string* word : *allWords) {
        cout << *word << " - " << *dictionary.get(*word) << endl;
    }
}

void FileReader::read(string, map<string, string>) {

}

vector<string> FileReader::split(string line, string splitPhrase) {
    vector<string> split;
    int splitter = line.find(splitPhrase);
    string trimmedLine = trim(line.substr(0, splitter));
    split.push_back(trimmedLine);
    trimmedLine = trim(line.substr(splitter + splitPhrase.size(), line.size()));
    split.push_back(trimmedLine);
    return split;
}

string FileReader::trim(string line) {
    int start = 0;
    int end = line.size();

    while (start < end - 1 && (isspace(line.at(start)) || line.at(start) == '"')) {
        start++;
    }

    while (end - 1 > start && (isspace(line.at(end - 1)) || line.at(start) == '"')) {
        end--;
    }

    return line.substr(start, end);
}
