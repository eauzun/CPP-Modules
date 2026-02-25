#include "sedButBetter.hpp"

static bool	checkArgs(int argc, const std::string &s1)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
		return (false);
	}
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	std::string	s1 = argc > 2 ? argv[2] : "";

	if (!checkArgs(argc, s1))
		return (1);

	SedButBetter	sed(argv[1], argv[2], argv[3]);

	if (!sed.openFiles())
		return (1);

	sed.processFile();
	return (0);
}