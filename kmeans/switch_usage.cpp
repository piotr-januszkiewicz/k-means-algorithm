#include "switch_usage.h"

int getArguments(int argc, char* argv[], string& Inputfile, string& Outputfile)
{
	string K;

	for (int i = 0; i < argc; ++i)
	{
		string argument = argv[i];

		if (argument == "-k")
		{
			K = argv[i + 1];
			i++;
		}
		if (argument == "-i")
		{
			Inputfile = argv[i + 1];
			i++;
		}
		if (argument == "-o")
		{
			Outputfile = argv[i + 1];
			i++;
		}
		if (argc == 1 || argument == "-h")
		{
			instruction();
		}
	}

	int k = atoi(K.c_str());
	return k;
}


