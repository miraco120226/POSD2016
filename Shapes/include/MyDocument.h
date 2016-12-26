#ifndef MYDOCUMENT_H
#define MYDOCUMENT_H
#include <string>
#include <iostream>
#include <fstream>
#include <io.h>
#include "Document.h"
using namespace std;

class MyDocument : public Document{
public:
    void openFile(const string name);
    bool canOpenDocument(const string name);
    string readFile();
private:
    ifstream is;
};

#endif // MYDOCUMENT_H
