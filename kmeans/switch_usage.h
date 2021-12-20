#pragma once
#include <iostream>
#include "interface.h"

using namespace std;
/**Function receives arguments from user using switches
@param argc argument count - counts how many arguments are passed by switches
@param argv array which stores argument values
@param Inputfile a place where input files name will be stored
@param Outputfile a place where output files name will be stored
@return number of clusters*/
int getArguments(int argc, char* argv[], string& Inputfile, string& Outputfile);
