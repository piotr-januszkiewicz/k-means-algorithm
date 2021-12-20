#include "searching.h"

void searchForCoordinates(vector<float>& ClustersCoordinates, vector<float> ArrayOfPointsCoordinates, int Dimensions,  int Number)
{
	for (int i = 0; i < Number+1; i++)
	{
		if (i == Number)
		{
			for (int j = 0; j < Dimensions; j++)
			{
				auto Position = Dimensions * (i - 1) + j;
				ClustersCoordinates.push_back(ArrayOfPointsCoordinates[Position]);
			}
		}
	}
}
