#ifndef HASH_H
#define HASH_H

#include "Map.h"
#include <string>
#include <cstdlib>
#include <vector>

class Hash : public Map {
public:
	// Constructor
	Hash();
	// Destructor
	~Hash();
	/* If the word is already in the Map, increments the count. 
	If it's new, adds it to the hash table and starts its count at 1. */
	void add(const std::string& word);
	/* outputs, to the given stream, every word in the Map, 
	in the order they appear in the hashtable; on each line, outputs one word, 
	followed by a space, that word's count, and then a newline. */
	void reportAll(std::ostream& output);
private:
	/* This takes a string as input, and outputs a pseudo-random index 
	to store it at. */
	int hashWord(std::string word);
	/* A private helper function which approximately doubles the number 
	of buckets available. It is called when load factor exceeds 0.5. 
	The # of buckets follows the sequence: 11, 23, 41, 83, 163, 331, 641, 
	1283, 2579, 5147, 10243, 20483, 40961. */
	void reSize();
	// finds a new hash value for all words to place into resized hash table
	void rehash();

	double loadFactor; // the amount of occupied space in the Map in relation to its total size
	int buckets; // number of Map locations that can be hashed to
	int items; // number of items contained in the Map
	std::vector<std::pair<std::string, int>* > hashTable; // hash table with word + integer pair
};

#endif

