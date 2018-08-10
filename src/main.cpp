#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "book.h"
#include <vector>
#include "rcfile.h"

int main()
{
	RCFile rcfile(".orderrc");

	std::cout << rcfile.useTitle << "\n"
		      << rcfile.useAuthor << "\n"
		      << rcfile.useYear << "\n"
		      << rcfile.titleAscending << "\n"
		      << rcfile.authorAscending << "\n"
		      << rcfile.yearAscending << "\n";
	
	std::ofstream bookssorted;
	bookssorted.open ("livrosordenados.txt");

	std::vector<Book> books;
	std::ifstream infile("livros.txt");
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
				books.push_back({title, author, (unsigned short)stoi(year)});
				break;
		}
	}

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

	for(auto it: books)
		bookssorted << it.title << "\t" << it.author << "\t" << it.year << "\n";

	bookssorted.close();

	return 0;
}
