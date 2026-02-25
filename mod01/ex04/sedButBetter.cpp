#include "sedButBetter.hpp"

SedButBetter::SedButBetter(const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2)
{
}

SedButBetter::~SedButBetter()
{
	if (_inFile.is_open())
		_inFile.close();
	if (_outFile.is_open())
		_outFile.close();
}

std::string	SedButBetter::replaceAll(std::string line)
{
	size_t	pos = 0;

	while ((pos = line.find(_s1, pos)) != std::string::npos)
	{
		line.erase(pos, _s1.length());
		line.insert(pos, _s2);
		pos += _s2.length();
	}
	return (line);
}

bool	SedButBetter::openFiles()
{
	_inFile.open(_filename.c_str());
	if (!_inFile.is_open())
	{
		std::cerr << "Error: cannot open file: " << _filename << std::endl;
		return (false);
	}

	_outFile.open((_filename + ".replace").c_str());
	if (!_outFile.is_open())
	{
		std::cerr << "Error: cannot create output file" << std::endl;
		return (false);
	}
	return (true);
}

void	SedButBetter::processFile()
{
	std::string	line;

	while (std::getline(_inFile, line))
	{
		_outFile << replaceAll(line);
		if (!_inFile.eof())
			_outFile << "\n";
	}
}