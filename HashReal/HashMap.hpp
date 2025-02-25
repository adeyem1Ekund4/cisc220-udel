/*
 * HashMap.hpp
 *
 *  Created on: Apr 21, 2023
 *      Author: Owner
 */

#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

#include "hashNode.hpp"

class hashMap {
	friend class makeSeuss;
	hashNode **map;  //Note that this is a dynamically
			//allocated array of pointers to hash Nodes.  It
			//is not a matrix.  I made it a pointer to an
			//array of pointers to nodes because I didn't
			//want to have to delete every hash Node and
			//then create a new one when I rehashed the
			//array.
	string first; // for first keyword for printing to a file
	int numKeys;  // Number of keys currently in the hashMap
	int mapSize;  // total size of the hashMap array
	bool hashfn;  // a bool indicating whether to use hash
			//function 1 or hash function 2 (we're comparing
			//hash function efficiencies)
	bool collfn;  // a bool indicating whether to use the
			//collision function 1 or the collision function
			//2 (we're also comparing the efficiency of
			//different collision functions)
	int collisions;  // number of collisions using the
			//collision-handling method
	int hashcoll; //number of initial collisions using just
			//the hash function

public:
	hashMap(bool hash1, bool coll1);  // when creating the
			//map, make sure you initialize the values to
			//NULL so you know whether that index has a key
			//in it or is set to NULL
	void addKeyValue(string k, string v);
			// adds a node  to the map at the correct index
			// based on the key string, and then inserts the
			// value into the value field of the hashNode
			// Must check to see whether there's already a
			// node at that location.  If there's nothing
			// there(it's NULL), add the hashNode with the
			// keyword and value.
			// If the node has the same keyword, just add
			// the value to the list of values.
			// If the node has a different keyword, keep
			// calculating a new hash index until either the
			// keyword matches the node at that index's
			// keyword, or until the map at that index is
			// NULL, in which case you'll add the node
			// there.
			// This method also checks for load, and if the
			// load is over 70%, it calls the reHash method
			// to create a new longer map array and rehash
			// the values
	void checkValsSize(int h);
			//Helper function to determine whether size of the
			//values array of a HashNode needs to be increased
	int getIndex(string k); // uses calcHash and reHash to
			// calculate and return the index of where
			// the keyword k should be inserted into the map
			// array
	int calcHash(string k);
			//Helper function used to negate having to write conditional
			//statements when wanting to call the calcHash functions
	int calcHash1(string k);  // hash function
	int calcHash2(string k);  // hash function 2
	int getClosestPrime(int curr);
			//Returns the closest prime number of the argument,
			//which in this case would be the closest prime number to double
			//the mapSize to.
	void reHash();  // when size of array is at 70%, double
			//array size and rehash keys
	int coll(int h, string k);
			//Helper function used to determine which collision function to call
			//rather than using conditional statments
	int coll1(int h, string k);  // a probing method
			//for collisions (when index is already full)
	int coll2(int h, string k);  // a different method
			//for dealing with collisions
	void printMap();  //I wrote this solely to check if
			//everything was working.
};




#endif /* HASHMAP_HPP_ */
