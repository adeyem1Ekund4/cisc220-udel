/*
 * theDog.cpp
 *
 *  Created on: Feb 15, 2023
 *      Author: Adeyemi Ekundayo
 *      Allison Fantom
 *
 */

#include "Dog.hpp"

#include <iostream>
#include <stdlib.h>
using namespace std;

	Dog::Dog(string n){
		name = n;//the name of the dog
		strength = 50;// base strength will be 50
		x=1;
		y=1;
	}
	Dog::Dog(){
		name == "Arcane";//the dog's name
		strength = 50;
		x=1;
		y=1;
	}
	void Dog::printDog(){
		cout << "Dog: "<<name<<endl;
		cout << "Strength: "<< strength << endl;
	}

	bool Dog::changeStrength(int amt){
		strength += amt;
		if(amt==0){
			printDog();//show the current information of the dog's status

		}
		if(strength>0){// the game will continue as long as the strength is not 0
			return true;
		}
		else{// if the dog's strength falls to 0, then it's game over
			if(amt==0){
				die();
				return false;
			}
		}
	}

	void Dog::die(){// the Game Over will show up on the screen if the dog's strength is 0
		cout << "GAME OVER!" << endl;
		cout << name << " has been succumbed to the maze's endless nightmare." << endl;
		cout << "But no one really dies...."<< endl;

	}
	void Dog::won(){
		cout << "Your dog " << name << " has escaped the maze :D" << endl;
		cout << "Are you up to the challenge again?" << endl;
	}
	void Dog::reset(){// if the player wants to paly again, then the game will reset
		strength = 50;
		x=1;
		y=1;
	}
