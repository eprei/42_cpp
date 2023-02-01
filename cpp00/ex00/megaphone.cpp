#include <iostream>

int main(int argc, char **argv)
{
	int i;
	int j;
	char c;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			c = toupper(argv[i][j++]);
			std::cout << c;
		}
		if (i + 1 < argc)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}
