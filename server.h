//
// Created by drew on 3/10/18.
//

#include <string.h>
#include <array>
#include "FileReader.h"
#include "Constants.h"


using namespace std;

#ifndef EE450PROJECT_SERVER_H
#define EE450PROJECT_SERVER_H


class server {
public:
    server();

protected:
    void loadServer();
    string fileName;

};


#endif //EE450PROJECT_SERVER_H
