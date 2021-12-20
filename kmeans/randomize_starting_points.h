#pragma once
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
/**Function randomize first clusters' centres
@param NumberCount defines a number of points from which the centres will be chosen
@param Array[] an array containing clusters' centres
@param ClustersCount defines a number of centres to choose
*/
void randomizeStartingPoints(int NumberCount, vector <int>& Array, int Clusters);
