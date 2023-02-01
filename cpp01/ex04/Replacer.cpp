#include "Replacer.hpp"
#include <iostream>
#include <fstream>

Replacer::Replacer(void){}

Replacer::~Replacer(void){}

bool	Replacer::getArgs(char **argv)
{
	this->_inputFileName = argv[1];
	this->_stringToReplace = argv[2];
	this->_newString = argv[3];
	this->_ifs.open(this->_inputFileName.data());
	this->_outputFileName = this->_inputFileName;
	this->_outputFileName += ".replace";
	return (this->_ifs.is_open());
}

void	Replacer::execReplacement(void)
{
	std::string	newLine;
	std::string	lineReplaced;
	std::size_t	found;

	this->_ofs.open(this->_outputFileName.data());
	getline(this->_ifs, newLine);
	found = newLine.find(this->_stringToReplace);
	while (this->_ifs.eof() == false)
	{
		while (found != std::string::npos)
		{
			newLine.insert(found, this->_newString);
			newLine.erase(found + this->_newString.length(), this->_stringToReplace.length());
			found = newLine.find(this->_stringToReplace, found + this->_newString.length());
		}
		this->_ofs << newLine << std::endl;
		getline(this->_ifs, newLine);
		while (newLine.compare("\n") == 0)
			getline(this->_ifs, newLine);
		found = newLine.find(this->_stringToReplace);
	}
	this->_ofs.close();
	this->_ifs.close();
	return ;
}
