#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <deque>
#include <sstream>
using namespace std;
/**Function extracts data from file and insert in to linked list.
@param FileName  file name
@param ArrayOfPointsCoordinates array where coordinates read from file will be stored
@param NumberCount a place where a number count will be stored
@param Dimensions a place where dimension count will be stored
@return an error flag
*/
int fileExtractionAndListInsertion(string FileName, vector<float> &ArrayOfPointsCoordinates, int& NumberCount, int& Dimensions);

/**Function writes data to file
@param OutputFile name of the output file where data will be stored. Must end with '.txt'
@param Clusters double linked queue which includes points' clusters
@param NumberCount defines a number of points
*/
void writeToFile(string OutputFile, deque<int> Clusters, int NumberCount);