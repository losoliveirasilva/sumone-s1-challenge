#include "rcfile.h"

RCFile::RCFile(std::string filepath){
	std::ifstream infile(filepath);

	aux = 0;

	useTitle = -1;
	useAuthor = -1;
	useYear = -1;

	titleAscending = true;
	authorAscending = true;
	yearAscending = true;

	if ((infile.rdstate() & std::ifstream::failbit) != 0){
		std::cerr << "Error opening '" << filepath << "'" << std::endl;
	} else{
		std::string line;
		while (std::getline(infile, line)){
			if (line.at(0) != '\"'){
				std::istringstream is_line(line);
				std::string key;
				if (std::getline(is_line, key, '=')){
					std::string value;
					if (std::getline(is_line, value)){
						try {
							storeLine(key, value);
						} catch (const std::logic_error& e) {
							std::cout << e.what() << std::endl;
						}
					}
				}
			}
		}
	}
}

bool parseValue(std::string value) {
	std::transform(value.begin(), value.end(), value.begin(), ::tolower);
	if (value == "ascendente")
		return true;
	else if (value == "descendente")
		return false;
	
	std::ostringstream ss;
	ss << "Error parsing value " << value << ".";
	throw std::logic_error(ss.str());

}

void RCFile::storeLine(std::string key, std::string value){

	if (key.compare("titulo") == 0){
		useTitle = aux;
		titleAscending = parseValue(value);
		aux++;
	} else if (key.compare("autor") == 0){
		useAuthor = aux;
		authorAscending = parseValue(value);
		aux++;
	} else if (key.compare("edicao") == 0){
		useYear = aux;
		yearAscending = parseValue(value);
		aux++;
	}
}
