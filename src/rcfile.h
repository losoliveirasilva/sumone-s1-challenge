#ifndef RC_H
#define RC_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

class RCFile {

public:
    RCFile(std::string filepath);

	int useTitle;
	int useAuthor;
	int useYear;

	bool titleAscending;
	bool authorAscending;
	bool yearAscending;

private:
	//bool parseValue(std::string value);
    void storeLine(std::string key, std::string value);
	int aux;

};

#endif
