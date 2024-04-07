/*
 * mazeBoard.cpp
 *
 *  Created on: Feb 15, 2023
 *      Author: Adeyemi Ekundayo
 *      Allison Fantom
 */

#include "Board.hpp"

#include <iostream>
#include <stdlib.h>
using namespace std;

	Board::Board(char diff, bool d){
		level = diff;// the difficulty of the level will be selected
		debug = d;
		wallStrength = 6;
		InitAll();
	}

	Board::Board(char diff, string name, bool d){
		mydog.name = name;
		level = diff;
		debug = d;
		wallStrength = 6;
		InitAll();
	}

	Board::Board(bool d){
		level = 'e';// example of selected difficulty
		debug = d;
		wallStrength = 6;
		InitAll();
	}

	void Board::InitAll(){
		bool keepPlaying = true;
		while (keepPlaying){
			cout << "What's the level of difficulty would want to select (e,m, or h)" << endl;
			char c;// use the keyboard to select easy, medium, or hard
			cin >> c;
			level =c;

			startx = rand()%(size-2)+1;//the dog starts in a random position in the maze's entrance
			starty = 0;
			endx = rand()%(size-2)+1;
			endy=size-1;

			mydog.x=startx;
			mydog.y=starty+1;
			/*All the elements will be added to the board as
			 * well as the dog before the game starts.*/
			boardConfig();
			addTraps();
			addFood();
			printBoard();
			mydog.printDog();

			playGame();
			cout << "Play again?"<< endl;
			string s = "no";
			cin >> s;
			if(s=="yes"||s=="Yes"||s=="Y"||s=="y"||s=="YES"||s=="Yep"||s=="YEP"||s=="yep"){
				keepPlaying = true;
				mydog.reset();
			}else{
				cout <<"Thank you for playing! ;)"<<endl;
				keepPlaying = false;
			}
		}
	}

	void Board::boardConfig() {
		int numWallsToAdd = 12;/*the width of walls to add,
		the number will increase will each difficulty, making
		it hard to move through with the high change of
		losing strength faster.*/
		if (level == 'm') {
			numWallsToAdd = 18;
		}
		else if (level == 'h') {
			numWallsToAdd = 25;
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				board[i][j] = ' ';// a space will be added to free room to move
			}
		}

		for (int j = 0; j < size; j++) {
			int addWall = rand() % 2;
			int wallsAdded = 0;
			if (addWall && j % 2 == 1) {
				while (wallsAdded < numWallsToAdd) {
					int i = rand() % 18 + 1;
					board[i][j] = '|';// vertical walls are added in
					wallsAdded++;

				}
			}
		}

		for (int i = 0; i < size; i++) {
			int addWall = rand() % 2;
			int wallsAdded = 0;
			if (addWall && i %  2 == 1) {
				while (wallsAdded < numWallsToAdd) {
					int j = rand() % 18 + 1;
					board[i][j] = '_';// horizontal walls are added in
					wallsAdded++;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j == 0 || j == size-1) {
					board[i][j] = '|';
					}
				if (i == 0 || i == size-1) {
					board[i][j] = '_';
				}
			}
		}
		board[startx][starty] = '-';
		board[startx][starty + 1] = 'D';
		board[endx][endy] = '-';
		board[endx][endy - 1] = 'E';
	}

	void Board::printBoard(){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){

				if(board[i][j]=='-'){
					cout <<board[i][j]<<'>';
				}else if(board[i][j]=='T' && !debug){
					cout << ' ' << ' ';
				}else{
					cout <<board[i][j]<<' ';

				}



			}
			cout << endl;


		}
	}

	void Board::addFood(){ /*the amount of food will be added
	in depending on the difficulty*/
		int diff = 0;
		int foodnum = 0;
		if(level == 'm'){
			diff = 2;
		}
		else if(level == 'h'){
			diff = 5;
		}
		while(foodnum<size-diff){
			int randx = (rand()%18)+1;
			int randy = (rand()%18)+1;
			if(board[randx][randy]== ' '){
				board[randx][randy]='F';
				foodnum++;
			}
		}

	}

	void Board::addTraps(){/*the amount of traps will be added
	in depending on the difficulty*/
		int diff = 0;
		int traps = 0;
				if(level == 'm'){
					diff = 2;
				}
				else if(level == 'h'){
					diff = 5;
				}
				while(traps<size-diff){
					int randx = (rand()%18)+1;
					int randy = (rand()%18)+1;
					if(board[randx][randy]== ' '){
						board[randx][randy]='T';
						traps++;
					}
				}
	}

	void Board::playGame(){// the dog will move with each key pressed
		bool play = true;
		while(play){
			cout << "Use(u,d,l,r) to move." <<endl;
			char c;
			 cin >> c;
			 play = moveDog(c);
			 if(play){
				 printBoard();
			 }
		}
	}

	bool Board::moveDog(char c) {
		int a = mydog.x;
		int b = mydog.y;
		if (c == 'u') {//up
			mydog.x--;
		}
		else if (c == 'd') {//down
			mydog.x++;
		}
		else if (c == 'l') {//left
			mydog.y--;
		}
		else if (c == 'r') {//right
			mydog.y++;
		}
		else {
			cout << "Please enter a valid direction." << endl;
			mydog.printDog();
			return true;
		}
		if (mydog.x == endx && mydog.y == endy) {
			mydog.won();
			return false;
		}
		/*Try and leave the map, you will be stopped!*/
		if (mydog.x == 0 || mydog.x == size-1 || mydog.y == 0 || mydog.y == size-1) {
			cout << "You cannot go outside of the border!" << endl;
			mydog.x = a;
			mydog.y = b;
			return true;
		}
		else if (board[mydog.x][mydog.y] == 'F') {//strength boose
			int strengthGained = rand() % 16 + 2;
			cout << mydog.name << " eats food. He thinks it's delicious! +" << strengthGained << " Strength" << endl;
			mydog.changeStrength(strengthGained);
		}
		else if (board[mydog.x][mydog.y] == 'T') {//strength lost
			int strengthLost = -(rand() % 16 + 2);
			cout << "Oh, no! " << mydog.name << " stepped into a trap! " << strengthLost << " Strength" << endl;
			mydog.changeStrength(strengthLost);
		}
		else if (board[mydog.x][mydog.y] == '|' || board[mydog.x][mydog.y] == '_') {
			if (mydog.strength > wallStrength) {//try to movie thorugh a wall, you will lose strength
				string answer;
				cout << "Do you want to knock down that wall? It will cost 6 Strength." << endl;
				cin >> answer;
				if (answer == "yes" || answer == "y" || answer == "Yes" || answer == "Y") {
					mydog.changeStrength(-wallStrength);
				}
				else {
					mydog.changeStrength(-1);
					mydog.x = a;
					mydog.y = b;
				}
			}
			else {//if you strength falls to 0, you lose
				cout << mydog.name << " does not have enough Strength!" << endl;
				mydog.x = a;
				mydog.y = b;
			}
		}
		else {//for every step you make, you will lose 2 strength
			mydog.changeStrength(-2);
		}
		board[a][b] = ' ';
		board[mydog.x][mydog.y] = 'D';
		return mydog.changeStrength(0);
	}
