/*
 * mainDDL.cpp
 *
 *  Created on: Mar 2, 2023
 *      Author: Owner
 */
#include <iostream>
#include <stdlib.h>
#include "Playlist.hpp"
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL));
	Playlist *list = new Playlist("ShortList.txt");
}
