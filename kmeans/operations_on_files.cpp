#include "operations_on_files.h"

int fileExtractionAndListInsertion(string FileName, vector<float> &ArrayOfPointsCoordinates, int& NumberCount, int& Dimensions)
{
	int Flag = 0;
	ifstream File(FileName);
	if (File)
	{
		string FileLines; int Counter = 0;
		while (!File.eof())
		{
			getline(File, FileLines);
			size_t Comment = FileLines.find_last_of('%');
			stringstream FileStream(FileLines);

			if (Counter == 0)
			{
				FileStream >> NumberCount;
				Counter++;
			}
			else if (Counter == 1)
			{
				FileStream >> Dimensions;
				Counter++;
			}
			else
			{
				
				if (FileLines[0] != '%')
				{
					int CoordinatesCounter = 0;
					while (CoordinatesCounter!=Dimensions)
					{
						float Coordinate;
						FileStream >> Coordinate;
						ArrayOfPointsCoordinates.push_back(Coordinate);
						CoordinatesCounter++;
					}
				}
			}
		}
	}
	else
	{
		cerr << "file could not be loaded. shutting down...";
		Flag = 1;
	}
	File.close();
	return Flag;
}


void writeToFile(string OutputFile, deque<int> Clusters, int NumberCount)
{
	ofstream outputFile(OutputFile);
	
	for (int i = 0; i < NumberCount; i++)
	{
		outputFile << Clusters[i] << "\t\t % indeks grupy punktu " << i + 1 << endl;

	}

	outputFile.close();
}