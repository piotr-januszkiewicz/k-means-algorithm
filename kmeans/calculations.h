#pragma once
#include "searching.h"
#include <iostream>
#include <vector>
#include <deque>

/**Function assign a point to a cluster based on a distance from every centre
@param Clusters a place where cluster goup numbers are stored
@param ClusterDistances a place where is stored the shortest distance between point and clusters' centre
@param ArrayOfPointsDistances a place where every distance between point and clusters' centre is stored
@param Clusters defines a number of clusters
@param NumberCount defines a number of points
*/
void assign(deque<int>& Clusters, vector <float>& ClusterDistances, vector<float> ArrayOfPointsDistances,  int ClustersCount, int NumberCount);

/**Function checks if the points are already centres
@param ClusterCentres array where are stored clusters' centres numbers
@param TableSum array which includes arithmetic average of every pair point-centre
@param TablePoints array which includes point numbers
@param ArrayPosition defines position of data in arrays
@param Iterator iterator from another function, used to search for data in arrays
@return a number of changed centres (could be more than the number of clusters)
*/
int checkingPoints(vector <int> ClusterCentres, vector<float> TableSum, vector <int> TablePoints, int ArrayPosition, int Iterator);

/**Function calculates distance from every centre to every point
@param Clusters an array where are stored numbers assignments
@param ClusterDistances a place where is stored the shortest distance between point and clusters' centre
@param ArrayOfPointsCoordinates array that stores coordinates of every point
@param ArrayOfPointsDistances array that stores distances between a point and assigned clusters' centre
@param ClusterCentres an array containing clusters' centres
@param Dimensions defines a number of dimensions
@param ClustersCount a number of clusters
@param NumberCount defines an upper border of points count
*/
void calculatingDistance(deque<int>& Clusters, vector <float>& ClusterDistances, vector<float> ArrayOfPointsCoordinates, vector <float> ArrayOfPointsDistances, vector <int> ClusterCentres, int ClusterCount, int NumberCount, int Dimensions);

/**Function calcultes an arithmetic average of every point that belongs to cluster in order to designate coordinates of a new centre
@param Clusters a place where cluster goup numbers are stored
@param ClusterDistances a place where is stored the shortest distance between point and clusters' centre
@param ArrayOfPointsCoordinates an array which stores coordinates of every point
@param ArithmeticAverageDistances an array which stores arithmetic average of coordinates from every point that belong to a cluster
@param ClustersCount defines a number of clusters
@param NumberCount defines a number of points
@param Dimensions defines a number of dimensions
*/
void arithmeticAverage(deque<int>& Clusters, vector <float>& ClusterDistances, vector<float>& ArrayOfPointsCoordinates, vector<float>& ArithmeticAverageDistances, int ClustersCount, int  NumberCount, int Dimensions);

/**Function is defying a centre. For each point belonging to a cluster defines a distance to a theroetical centre calculated in function arithmeticAverage()
@param ArrayOfPointsCoordinates an array which stores coordinates of every point
@param Clusters a place where cluster goup numbers are stored
@param ArithmeticAverageDistances an array which stores arithmetic average of coordinates from every point that belong to a cluster
@param ClusterDistances a place where is stored the shortest distance between point and clusters' centre
@param ClustersCount defines a number of clusters
@param NumberCount defines a number of points
@param Dimensions defines a number of dimensions
@return a number of changed centres (could be more than the number of clusters)
*/
int calculatingNewCenter(vector<float>& ArrayOfPointsCoordinates, deque<int>& Clusters, vector<float> ArithmeticAverageDistances, vector <int> ClusterCentres, int ClustersCount, int NumberCount, int Dimensions);
