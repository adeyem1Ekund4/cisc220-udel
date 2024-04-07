/*
 * student.hpp
 *
 *  Created on: Feb 13, 2023
 *      Author: Owner
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_
#include <iostream>
#include <string.h>
	using namespace std;

	class Student {
		string last;
		string first;
		int labs[5];
		char grade;
	public:

		Student();
		Student(string l,string f,int l1,int l2,int l3,int l4,int ex);
		char getGrade();
		void printName();

};

#endif /* STUDENT_HPP_ */
