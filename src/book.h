#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {

public:
	Book(std::string title, std::string author, unsigned short year):
		title{title}, author{author}, year{year} {}

	const std::string title;
	const std::string author;
	const unsigned short year;
};

#endif
