#include "MyDocument.h"


void MyDocument::openFile(const string name){
    is.open(name,ios::in);
}

bool MyDocument::canOpenDocument(const string name){
    if(access(name.c_str(),R_OK)==0)
        return true;
    else
        return false;
}

string MyDocument::readFile(){
    string str;
    string temp;

    getline(is,str);

    while(getline(is,temp)){
        str+='\n';
        str+=temp;
    }
    return str;
}
