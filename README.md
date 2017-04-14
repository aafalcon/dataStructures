# dataStructures
Implementation of several data structures and algorithms

main function is in zipf.cpp

zipf.cpp program description:

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
