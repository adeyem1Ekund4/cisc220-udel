/*
 * myfiles.cpp
 *
 *  Created on: Feb 13, 2023
 *      Author: Owner
 */

#include <iostream>
#include <string.h>
#include "student.hpp"
using namespace std;

int main(){
	Student stud1;
	cout << stud1.last;
	cout << stud1.grade;
	Student stud2;
	cout << stud2.last;
	cout << stud2.grade;
	Student stud3("Tues","Ben");
	cout << stud3;

};


