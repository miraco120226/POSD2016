#include "Document.h"

string Document::openDocument(const string name){
	if(!canOpenDocument(name))
		throw std::string("file is not existed.");
	openFile(name);
	return readFile();
}

