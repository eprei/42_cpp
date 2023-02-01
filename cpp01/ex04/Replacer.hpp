#ifndef REPLACE_HPP
# define REPLACE_HPP
# include <string>
# include <fstream>

class Replacer
{
	public:
		Replacer(void);
		~Replacer(void);

		bool	getArgs(char **argv);
		void	execReplacement(void);

	private:
		std::string		_inputFileName;
		std::string		_outputFileName;
		std::string		_stringToReplace;
		std::string		_newString;
		std::ifstream	_ifs;
		std::ofstream	_ofs;
};

#endif
