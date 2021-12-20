#pragma once
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
/**Function search for coordinates of a given point
@param ClustersCoordinates array where coordinates of clusters will be stored
@param ArrayOfPointsCoordinates a place where coordinates of every point are stored
@param Dimensions defines a number of dimensions
@param NumberCount a number of points' coordinates
*/
void searchForCoordinates(vector<float>& ClustersCoordinates, vector<float> ArrayOfPointsCoordinates, int Dimensions, int Number);
