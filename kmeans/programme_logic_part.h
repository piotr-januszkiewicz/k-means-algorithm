#pragma once
#include <iostream>

#include "searching.h"
#include "calculations.h"
#include "operations_on_files.h"
#include "randomize_starting_points.h"
#include "interface.h"
#include "switch_usage.h"
#include "programme_logic_part.h"

/**Function is a loggic part of a programme
@param argc argument count - counts how many arguments are passed by switches
@param argv array which stores argument values
@return flag*/
int programme(int argc, char* argv[]);