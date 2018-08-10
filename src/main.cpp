#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "book.h"
#include <vector>
#include "rcfile.h"

int main()
{
	// Open configuration file
	RCFile rcfile(".orderrc");
	
	std::ofstream bookssorted;
	bookssorted.open ("livrosordenados.txt");
	if(!bookssorted.is_open()){
		std::cout << "Failed to open file\n\n";
	    return -1;
	}

	std::vector<Book> books;
	std::ifstream infile("livros.txt");
	if(infile.fail()){
		std::cout << "Failed to open books file\n\n";
	    return -1;
	}
	std::string line;
	std::string title, author, year;
	char infoAux = 0;

	// Create books unsorted vector
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
				books.push_back({title, author, (unsigned short)stoi(year)});
				break;
		}
	}

	// Sort books
	std::sort(books.begin(), books.end(), [=](const Book& a, const Book& b) {
		if(rcfile.useYear > -1){
		    if(rcfile.yearAscending and a.year < b.year){
			    return true;
			} else if(rcfile.yearAscending and b.year < a.year){
			    return false;
			} else if(!rcfile.yearAscending and a.year > b.year){
			    return true;
			} else if(!rcfile.yearAscending and b.year > a.year){
			    return false;
			}
		}

		if(rcfile.useAuthor > -1){
		    if(rcfile.authorAscending and a.author < b.author){
			    return true;
			} else if(rcfile.authorAscending and b.author < a.author){
			    return false;
			} else if(!rcfile.authorAscending and a.author > b.author){
			    return true;
			} else if(!rcfile.authorAscending and b.author > a.author){
			    return false;
			}
		}

		if(rcfile.useTitle > -1){
		    if(rcfile.titleAscending and a.title < b.title){
			    return true;
			} else if(rcfile.titleAscending and b.title < a.title){
			    return false;
			} else if(!rcfile.titleAscending and a.title > b.title){
			    return true;
			} else if(!rcfile.titleAscending and b.title > a.title){
			    return false;
			}
		}

		return false;
	});

	// Write sorted books list file
	for(auto it: books)
		bookssorted << it.title << "\t" << it.author << "\t" << it.year << "\n";

	bookssorted.close();

	return 0;
}
