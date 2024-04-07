/*
 * lab1_class2.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Adeyemi EKundayo
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int func1(int x);

int main(){
	/*this will be how running lines be... */
	cout << "Hello World!" << endl;
	int x = func1(6);
	cout << x << endl;
	cout << "hi" << endl;
	return 0;
}

int func1(int x){
	for (int i = 0; i > x;i++){
		cout << i << ", ";
	}
	cout << endl;
	return x + 4;
}


