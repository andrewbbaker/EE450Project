//
// Created by drew on 3/10/18.
//

#include "server.h"

int main(int argc, char **argv) {
    server* server1 = new server();
}

server::server() {
    loadServer();
}

void server::loadServer() {
    fileName = Constants::debugFilePath + "/backendA.txt";

    FileReader fileReader;
    Dictionary dictionary;
    fileReader.read(fileName, dictionary);
}
