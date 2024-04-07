/*
 * DLL.cpp
 *
 *  Created on: Mar 2, 2023
 *      Author: Owner
 */
#include "DNode.hpp"
#include "Song.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

	//Check Playlist.cpp for instructions of what to write here and how to test it
	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}

	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}

	void DLL::push(string t, string a, int m, int s) {
		// does what you'd think
		DNode *n = new DNode(t,a,m,s);
		if(numSongs==0){
			first = n;
			last = first;
		}else{
			n->prev=last;
			last->next=n;
			last =n;
		}
		numSongs++;
			}
	Song *DLL::pop() { //does what you'd think
		DNode *tmp=last;
		Song *x=tmp->song;
		last=last->prev;
		delete tmp;
		last->next = NULL;
		numSongs--;
		return x;
	}

	void DLL::printList() {
		DNode *current=first;
		while(current !=NULL){
			current->song->printSong();
			current = current->next;
		}
	}

	void DLL::moveUp(string t) {
		DNode *current = first;
		while (current->song->title != t){
			current = current->next;

		}

		if(current->prev==NULL){
			last->next = current;
			current->next->prev = NULL;
			first = current->next;
			current->prev = last;
			last = current;
			current->next = NULL;
			last->next = NULL;
			}
		else if(current->next==NULL){
			current->prev->prev->next = current;
			current->prev->next = NULL;
			current->next = current->prev;
			DNode *tmp;
			tmp = current->prev->prev;
			current->prev->prev = current;
			last = current->prev;
			current->prev = tmp;
			}
		else if(current->prev->prev==NULL){
			current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;
			current->prev->prev = current;
			current->prev = NULL;
			first = current;
		}else{
			current->prev->prev->next = current;
			current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;
			DNode *tmp;
			tmp = current->prev->prev;
			current->prev->prev = current;
			current->prev = tmp;
		}
	}

	void DLL::listDuration(int *tm, int *ts) {
		DNode *current = first;
		while(current !=NULL){
			*ts += current->song->sec;
			*tm += current->song->min;
			current=current->next;
		}

			}
	void DLL::moveDown(string t) {
		DNode *current = first;
		while (current->song->title != t){
			current = current->next;
		}
		if(current->next==NULL){
			current->prev->next=NULL;
			last=current->prev;
			first->prev=current;
			current->prev=NULL;
			current->next=first;
			first =current;
		}else if(current->prev==NULL){
			current->next->next->prev=current;
			current->next->prev=NULL;
			current->prev=current->next;
			DNode *tmp=current->next->next;
			current->next->next=current;
			current->next=tmp;
			first=current->prev;
		}else if(current->next->next==NULL){
			current->prev->next=current->next;
			current->next->prev=current->prev;
			current->prev = current->next;
			current->next->next=current;
			current->next=NULL;
			last=current;
		}else{
			current->next->next->prev=current;
			current->prev->next=current->next;
			current->next->prev=current->prev;
			current->prev = current->next;
			DNode *tmp;
			tmp=current->next->next;
			current->next->next=current;
			current->next=tmp;
		}


	}

	void DLL::makeRandom() {
		DNode *current = first;
		DNode *random;
		int randInd;
		for (int i =0;i<numSongs;i++){
			random=current;
			randInd=(rand()% numSongs + 1);

			for (int j =0;j<randInd;j++){
						if(random->next ==NULL){
							randInd=j;
							break;
							}
						random=random->next;
				}
			for(int x=0;x<randInd;x++){
				moveUp(random->song->title);
				}

			}
		randInd=(rand()%numSongs)+1;
		for(int y=0;y<randInd;y++){
			moveUp(current->song->title);
			}
		current=first;
		while(current->next!=NULL){
			current=current->next;
		}
		last=current;
		}

	int DLL::remove(string t) {
		DNode *tmp = first;
		int x=0;
		while(tmp!=NULL && x==0){
			if(tmp->song->title==t){
				if(tmp==first){
					if(tmp->song->sec<10){
						cout << "Removing: " << tmp->song->title << ", " << tmp->song->artist << "......." << tmp->song->min << ":0" << tmp->song->sec << endl;
					}else{
						cout << "Removing: " << tmp->song->title << ", " << tmp->song->artist << "......." << tmp->song->min << ":0" << tmp->song->sec << endl;
					}
					first=tmp->next;
					x=1;
				}else if(tmp==last){
					if(tmp->song->sec<10){
						cout << "Removing: " << tmp->song->title << ", " << tmp->song->artist << "......." << tmp->song->min << ":0" << tmp->song->sec << endl;
					}else{
						cout << "Removing: " << tmp->song->title << ", " << tmp->song->artist << "......." << tmp->song->min << ":0" << tmp->song->sec << endl;
					}
					pop();
					x=1;
				}else{
					if(tmp->song->sec<10){
						cout << "Removing: " << tmp->song->title << ", " << tmp->song->artist << "........" << tmp->song->min << ":0" << tmp->song->sec << endl;
					}else{
						cout << "Removing: " << tmp->song->title << ", " << tmp->song->artist << "........" << tmp->song->min << ":0" << tmp->song->sec << endl;
					}
					tmp->prev->next=tmp->next;
					tmp->next->prev=tmp->prev;
					x=1;
				}

			}
			else{tmp=tmp->next;
			}


			}
		delete tmp;
		return x;
		}

//*****//
	DLL::~DLL(){
		DNode *current = first;
		DNode *next;

		while (current !=NULL){
			next = current->next;
			delete current;
			current = next;

		}
		last = NULL;
		first = NULL;
		numSongs=0;
	}




