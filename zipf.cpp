/**
* Author: Alden Falcon 
*
* Program Description:
* Takes an input .txt file and stores all of its words into a Map (hash table or splay tree). It also
* keeps track of each word's occurence. Then it reports a list of all words present in the .txt
* file with its frequency. The splay tree reports the words in alphabetical order.
* Splay tree: user has no limitation to number of words insterted because new nodes can always be appended
* Hash table: The maximum number of distinct words is 20480, beacause the number of buckets had to be prime
* numbers, which was ended at 40961. However, this can be increased if desired.
*
* Required Files (description):
* Map.h (map class definition), 
* hash.h (hash table class/ function definition), 
* hash.cpp (hash table implementation), 
* bst.h (binary search tree definition/ implementation),
* splTree.h (splay tree - type of bst definition/ implementation)
* hamlet.txt (sample .txt file to run program on, other .txt file can be used)
*
* Compile command:
* g++ hash.cpp zipf.cpp -g -Wall -o zipf
*
* Run command (hamlet.txt included as sample, but other .txt files can be used):
* (hash table)
* ./zipf 4 hamlet.txt
* (splay tree)
* ./zipf 5 hamlet.txt
*
*/
#include "Map.h"
#include "hash.h"
#include "splTree.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char * argv[]) {
    clock_t start;
    double duration;

    start = clock();


    ifstream inFile(argv[2]); // second command line argument is the .txt file to input into Map
    Map* wordBank;
    string currWord;

    /**
    *  First command line argument is to select Map type: (4) for hash table and (5) for Splay Tree
    */
    int algorithm = atoi(argv[1]); 

    if (algorithm == 4)
    {
    	wordBank = new Hash();
    }
    else if (algorithm == 5)
    {
    	wordBank = new SplayTree<string,int>();
    }
    else
    {
    	cerr << "Choose (4) for Hash Table or (5) for Splay Tree" << endl;
    	return 1;
    }

    // add all words to map
    while (!inFile.eof())
	{
		inFile >> currWord;
		wordBank->add(currWord);
	}
	inFile.close();

    // print all words with their count to the command line
	wordBank->reportAll(cout);

    // report total duration of program runtime in seconds (can be used to compare speeds of both Map types)
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    cout << duration << endl;

    return 0;
}