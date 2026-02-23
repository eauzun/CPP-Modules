#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			cout << (char)toupper(argv[i][j]);
		if (i < argc - 1)
			cout << " ";
	}
	cout << endl;
	return (0);
}