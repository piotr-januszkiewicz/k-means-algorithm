#include "programme_logic_part.h"

int programme (int argc, char* argv[])
{
	int NumberCount = 0, Dimensions = 0, IsAlgorithmDone = 1, ClustersCount = 3, Flag = 0;
	string Inputfile = "nazwa.txt", Outputfile = "orya.txt";
	deque<int> Clusters;

	//ClustersCount = getArguments(argc, argv, Inputfile, Outputfile);

	if (ClustersCount != 0)
	{
		vector<float> ArrayOfPointsCoordinates;

		Flag = fileExtractionAndListInsertion(Inputfile, ArrayOfPointsCoordinates, NumberCount, Dimensions);
		if (Flag == 1)
		{
			return Flag;
		}
		if (ClustersCount > NumberCount)
		{
			Flag = 2;
			cerr << "There is more Clusters Than Points. I cannot assign all points to every cluster. shutting down...";
			return Flag;
		}

		vector <int> ClusterCentres;
		vector <float> ClusterDistances, ArrayOfPointsDistances;

		
		randomizeStartingPoints(NumberCount, ClusterCentres, ClustersCount);

		while (IsAlgorithmDone != 0)
		{
			vector<float> ArithmeticAverageDistances;

			calculatingDistance(Clusters, ClusterDistances, ArrayOfPointsCoordinates, ArrayOfPointsDistances, ClusterCentres, ClustersCount, NumberCount, Dimensions);
			
			arithmeticAverage(Clusters, ClusterDistances, ArrayOfPointsCoordinates, ArithmeticAverageDistances, ClustersCount, NumberCount, Dimensions);

			IsAlgorithmDone = calculatingNewCenter(ArrayOfPointsCoordinates, Clusters, ArithmeticAverageDistances, ClusterCentres, ClustersCount, NumberCount, Dimensions);

			if (IsAlgorithmDone == 0)
				break;
		}

		writeToFile(Outputfile, Clusters, NumberCount);
	}
	else
	{
		cerr << "There are no clusters defined. shutting down...";
		Flag = 3;
	}
	return Flag;
}
