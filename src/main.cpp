#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "book.h"
#include <vector>

int main()
{
	
	std::vector<Book> books;
	std::ifstream infile("books.txt");
	std::string line;
	std::string title, author, year;
	char infoAux = 0;

	while (std::getline(infile, line)){
		switch(infoAux){
			case 0:
				title = line;
				infoAux++;
				break;
			case 1:
				author = line;
				infoAux++;
				break;
			case 2:
				year = line;
				infoAux = 0;
				//std::cout << title << " | " << author << " | " << year << "\n";
				books.push_back(Book(title, author, (unsigned short)stoi(year)));
				break;
		}
	}


	for(auto it: books)
		std::cout << it.title << " | " << it.author << " | " << it.year << "\n";

	return 0;
}
