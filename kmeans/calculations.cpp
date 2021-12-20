#include "calculations.h"

void assign(deque<int>& Clusters, vector <float>& ClusterDistances, vector <float> ArrayOfPointsDistances, int ClusterCount, int NumberCount)
{
	int ClusterNumber = 1; 

	if (Clusters.empty() || ClusterDistances.empty())
	{
		for (int i = 0; i < NumberCount; i++)
		{
			Clusters.push_back(1);
			ClusterDistances.push_back(ArrayOfPointsDistances[i]);
		}
	}
	

	for (int i = 1; i < ClusterCount; i++)
	{
		for (int j = 0; j < NumberCount; j++)
		{
			int Position = i * NumberCount + j;

			if (ArrayOfPointsDistances[Position] < ClusterDistances[j])
			{
				ClusterDistances[j] = ArrayOfPointsDistances[Position];
				Clusters[j] = ClusterNumber + i;
			}
		}
	}

}

void calculatingDistance(deque<int>& Clusters, vector <float>& ClusterDistances, vector<float> ArrayOfPointsCoordinates, vector <float> ArrayOfPointsDistances, vector <int> ClusterCentres, int ClusterCount, int NumberCount, int Dimensions)
{
	int ClustersNumber = 0;
	if (ArrayOfPointsDistances.empty())
	{
		for (int i = 0; i < NumberCount*ClusterCount; i++)
		{
			ArrayOfPointsDistances.push_back(0);
		}
	}
	
	while (ClustersNumber != ClusterCount)
	{
		vector<float> ClustersCoordinates;

		searchForCoordinates(ClustersCoordinates, ArrayOfPointsCoordinates, Dimensions, ClusterCentres[ClustersNumber]);

		for (int i = 0; i < NumberCount; i++)
		{
			float Sum = 0, Equation = 0;

	 		for (int j = 0; j < Dimensions; j++)
	 		{
	 			auto Position = Dimensions * i + j;
	 			Equation = ClustersCoordinates[j] - ArrayOfPointsCoordinates[Position];
	 			Sum += Equation * Equation;
	 		}
		 	auto Position = ClustersNumber * NumberCount + i;
			
			Sum = sqrt(Sum);
		 	ArrayOfPointsDistances[Position] = Sum;
	 	}
	 	ClustersNumber++;
	 }
	assign(Clusters, ClusterDistances,ArrayOfPointsDistances,ClusterCount,NumberCount);
	
}

int checkingPoints(vector <int> ClusterCentres, vector<float> TableSum, vector<int> TablePoints, int ArrayPosition, int Iterator)
{
	int Position = 0, CentreChanged = 0;

	for (int j = 0; j < ArrayPosition; j++)
	{
		if (ClusterCentres[Iterator] == TablePoints[j])
			Position = j;
	}

	float Value = TableSum[Position];

	for (int j = 0; j < ArrayPosition; j++)
	{
		if (TableSum[j] < Value)
		{
			Value = TableSum[j];
			ClusterCentres[Iterator] = TablePoints[j];
			CentreChanged++;
		}
	}
	return CentreChanged;
}
void arithmeticAverage(deque<int>& Clusters, vector <float>& ClusterDistances, vector<float>& ArrayOfPointsCoordinates, vector<float>& ArithmeticAverageDistances, int ClustersCount, int  NumberCount, int Dimensions)
{
	for (int i = 0; i < ClustersCount*Dimensions; i++)
	{
		ArithmeticAverageDistances.push_back(0);
	}
	for (int i = 0; i < ClustersCount; i++)
	{
		float Sum = 0; int Points = 0;

		for (int j = 0; j < NumberCount; j++)
		{
			if (Clusters[j] == i + 1)
			{
				for (int k = 0; k < Dimensions; k++)
				{
					int AA_ArrayPosition = i * Dimensions + k, PC_ArrayPosition = j * Dimensions + k;
					
					ArithmeticAverageDistances[AA_ArrayPosition] += ArrayOfPointsCoordinates[PC_ArrayPosition];
				}
				Points++;
			}
		}
		if (Points != 0)
		{
			for (int k = 0; k < Dimensions; k++)
			{
				int ArrayPosition = i * Dimensions + k;

				ArithmeticAverageDistances[ArrayPosition] = ArithmeticAverageDistances[ArrayPosition] / Points;
			}
		}
		
	}

}

int calculatingNewCenter(vector<float>& ArrayOfPointsCoordinates, deque<int>& Clusters, vector<float> ArithmeticAverageDistances, vector <int> ClusterCentres, int ClustersCount, int NumberCount, int Dimensions)
{
	int Changes = 0;

	for (int i = 0; i < ClustersCount; i++)
	{
		vector<float> TableSum; vector<int> TablePoints;
		int ArrayPosition = 0;
	
		for (int j = 0; j < NumberCount; j++)
		{
			if (Clusters[j] == i + 1)
			{
				float Variable = 0, Sum = 0;

				for (int k = 0; k < Dimensions; k++)
				{
					int ArrayPosition = k + i * Dimensions;  int PC_ArrayPosition = j * Dimensions + k;
					Variable = ArithmeticAverageDistances[ArrayPosition] - ArrayOfPointsCoordinates[PC_ArrayPosition];
					Sum += Variable * Variable;
				}

				if (Sum != 0)
				{
					Sum = sqrt(Sum);
				}

				TableSum.push_back(Sum);
				TablePoints.push_back(j + 1);
				ArrayPosition++;
			}
		}
		Changes = checkingPoints(ClusterCentres, TableSum, TablePoints, ArrayPosition, i);
	}
	return Changes;
}

