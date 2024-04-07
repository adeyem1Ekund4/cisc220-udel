/*
 * BST.cpp
 *
 *  Created on: Apr 1, 2023
 *      Author: Adeyemi Ekundayo
 */

#include "BST.hpp"
#include "BSTNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**************************************************************/
/* These are the methods you are to write for a BST           */
/* More Detailed Instructions can be found in the doc and in  */
/* the BST.hpp file                                           */
/**************************************************************/

BST::BST(string n, string st, string descr, bool Xtra) {
	root = new BSTNode(n,st,descr);
	Xt = Xtra;
}

bool BST::insert(string n, string st, string descr) {
	BSTNode *p = new BSTNode(n,st,descr);
	BSTNode *end = root;
	if(end==NULL){
		root = p;
		p->printNode(true);
		return true;
	}else{
		while(end!=NULL){
			if(n<end->animal->name){
				if(end->left==NULL){
					end->left=p;
					end->left->parent=end;
					setHeight(p);
					return true;
				}else{
				end=end->left;
				}
			}
			else if(n > end -> animal->name){
				if(end->right==NULL){
					end->right=p;
					end->right->parent=end;
					setHeight(p);
					return true;
				}else{
					end=end->right;
					}
				}
			else{
				if(end->animal->name==n){
					return false;
				}
			}
		}
	}
	return true;

}


BSTNode *BST::find(string n){
	if(root==NULL){
		return NULL;
	}
	else{
		BSTNode *stem = root;
		if(stem->animal->name==n){
			return stem;
		}
		else{
			if(n>stem->animal->name){
				if(stem->right==NULL){
					return NULL;
				}
				stem = stem -> right;
				stem->printNode(true);
			}
			else if(n<stem->animal->name){
						if(stem->left==NULL){
							return NULL;
						}
				stem = stem -> left;
				stem->printNode(true);
			}
		}
		return stem;
	}

}

void BST::updateStatus(string name, string st) {
	BSTNode *tmp=root;
	tmp=find(tmp->animal->name);
	tmp->animal->status=st;
	return;
}
void BST::printTreeIO(BSTNode *tmp) {
	if(tmp==NULL){
		return;
	}
	else{
		printTreeIO(tmp->left);
		tmp->printNode(true);
		printTreeIO(tmp->right);
	}
}

void BST::printTreePre(BSTNode *tmp) {
	if(tmp==NULL){
			return;
		}
		else{
			tmp->printNode(true);
			printTreePre(tmp->left);
			printTreePre(tmp->right);
		}
}


void BST::printTreePost(BSTNode *tmp) {
	if(tmp==NULL){
			return;
		}
		else{
			printTreePost(tmp->left);
			printTreePost(tmp->right);
			tmp->printNode(true);
		}
}

void BST::setHeight(BSTNode *tmp) {
		int left_height = 0;
		int right_height = 0;
			if(tmp->left != NULL) {
				left_height = tmp->left->height;
			}
			if(tmp->right != NULL) {
				right_height = tmp->right->height;
			}
			if(left_height>right_height) {
				tmp -> height=left_height += 1;
			}
			else {
				tmp -> height =right_height += 1;
			}
			if(tmp -> parent == NULL) {
				return;
			}
		setHeight(tmp -> parent);
}

BSTNode *BST::removeNoKids(BSTNode *tmp) {
	if(tmp->parent->left==tmp){
		tmp->parent->left=NULL;
		setHeight(tmp);
	}
	else if(tmp->parent->left==tmp){
		tmp->parent->right=NULL;
		setHeight(tmp);
	}
	return tmp;
}

BSTNode *BST::removeOneKid(BSTNode *tmp,bool leftFlag) {
	BSTNode *Nature = tmp->parent;
	BSTNode *value = tmp;
	if(leftFlag==true){
		BSTNode *kid=tmp->left;
		if((Nature->left->animal->name==tmp->animal->name)||(Nature->left->animal->info==tmp->animal->info)){
			tmp->parent->left=kid;
			value=tmp->parent;
			delete(tmp);
		}
		if((Nature->right->animal->name==tmp->animal->name)||(Nature->right->animal->info==tmp->animal->info)){
			tmp->parent->right=kid;
			value=tmp->parent;
			delete(tmp);
		}
	}
	else{
		BSTNode *kid=tmp->right;
		if((Nature->left->animal->name==tmp->animal->name)||(Nature->left->animal->info==tmp->animal->info)){
			tmp->parent->left=kid;
			value=tmp->parent;
			delete(tmp);
			}
		if((Nature->right->animal->name==tmp->animal->name)||(Nature->right->animal->info==tmp->animal->info)){
			tmp->parent->right=kid;
			value=tmp->parent;
			delete(tmp);
			}
	}
	return value;
}

BSTNode *BST::remove(string s) {
	BSTNode *newremove = find(s);
	if(newremove->left !=NULL && newremove->right !=NULL){
		BSTNode *status = newremove->left;
		while(status->right != NULL){
			status=status->right;
		}
			newremove->animal=status->animal;
			if(status->left==NULL && status->right==NULL){
			removeNoKids(status);
			}
			else if(status->left !=NULL && status->right==NULL){
				removeOneKid(status,true);
			}
			else{
				removeOneKid(status,false);
				}
	}
	else if(newremove->left !=NULL && newremove->right==NULL){
			removeOneKid(newremove,true);
		}
	else if(newremove->right !=NULL && newremove->left==NULL){
			removeOneKid(newremove,false);
		}
	else{
			removeNoKids(newremove);
		}
	return newremove;
}

/**************** Written for you  ***********************/

BST::BST(bool Xtra) {
	root = NULL;
	Xt = Xtra;
}


void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(BSTNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode(Xt);
		delete(tmp);
	}
}
void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}


