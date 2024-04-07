/*
 * MakeSuess.hpp
 *
 *  Created on: Apr 21, 2023
 *      Author: Owner
 */

#ifndef MAKESUESS_HPP_
#define MAKESUESS_HPP_

#include "hashMap.hpp"
#include <iostream>
using namespace std;

class makeSeuss {
	hashMap *ht;
	string fn;
	string newfile;
	bool hashfn;
	bool collfn;
public:
	makeSeuss(string file,string newf, bool hash1, bool coll1);
	void readFile();
	void writeFile();

};


#endif /* MAKESUESS_HPP_ */
