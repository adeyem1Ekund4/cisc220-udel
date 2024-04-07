/*
 * DNode.cpp
 *
 *  Created on: Mar 3, 2023
 *      Author: Owner
 */

#include "DNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

DNode::DNode(){
	song = new Song();
	next = NULL;
	prev = NULL;
}

DNode::DNode(string s, string a, int lenmin, int lensec){
	song = new Song(s,a,lenmin,lensec);
	next = NULL;
	prev = NULL;
}



