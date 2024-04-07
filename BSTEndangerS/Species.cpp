/*
 * Species.cpp
 *
 *  Created on: Apr 1, 2023
 *      Author: Adeyemi Ekundayo
 */

#include "Species.hpp"

#include <iostream>
#include <string>
using namespace std;

Species::Species(string s, string st, string inf) {
	name = s;
	status = st;
	info = inf;
}

Species::Species() {
	name = "";
	status = "";
	info = "";
}



