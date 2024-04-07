/*
 * grader.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Owner
 */


#include <iostream>
#include <stdlib.h>

	using namespace std;

	int testscore = 76;
	char grade;

	int main(){
		if(testscore >= 90){
			grade = 'A';
		}
		else if(testscore >= 80){
			grade = 'B';
				}
		else if(testscore >= 70){
			grade = 'C';
				}
		else if(testscore >= 60){
			grade = 'D';
				}
		else {
			grade = 'F';
				}
		cout << "Grade = " << grade << endl;
	}



