#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {

public:
	Book(std::string title, std::string author, unsigned short year):
		title{title}, author{author}, year{year} {}

	Book(Book&& other): title{std::move(other.title)}, author{std::move(other.author)}, year{other.year} {}

	Book(const Book&) = default;

	Book& operator=(Book&&) = default;
	//Book& operator=(const Book&) = default;

	std::string title;
	std::string author;
	unsigned short year;
};

#endif
