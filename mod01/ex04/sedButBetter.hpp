#ifndef SEDBUTBETTER_HPP
# define SEDBUTBETTER_HPP

# include <string>
# include <fstream>
# include <iostream>

class SedButBetter
{
	private:
		std::string		_filename;
		std::string		_s1;
		std::string		_s2;
		std::ifstream	_inFile;
		std::ofstream	_outFile;

		std::string		replaceAll(std::string line);

	public:
		SedButBetter(const std::string &filename, const std::string &s1, const std::string &s2);
		~SedButBetter();

		bool	openFiles();
		void	processFile();
};

#endif