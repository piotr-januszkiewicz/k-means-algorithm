#include "randomize_starting_points.h"

void randomizeStartingPoints(int NumberCount, vector <int>& Array, int Clusters)
{
	for (int i = 0; i < Clusters; i++)
	{
		Array.push_back(0);
	}

	srand(time(NULL));
	int RandomNumber = 0, NumberOfIterations = 0;
	do
	{
		RandomNumber = rand() % NumberCount + 1;
		int Flag = 0;

		for (int j = 0; j <= NumberOfIterations; j++)
		{
			
			if (RandomNumber == Array[j])
			{
				Flag = 1;
			}

		}

		if (Flag == 0)
		{
			Array[NumberOfIterations] = RandomNumber;
			NumberOfIterations++;
		}

	} while (NumberOfIterations != Clusters);

}
