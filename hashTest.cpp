#include "hash.h"
#include <iostream>
#include <string>

using namespace std;

int main () 
{
	Map* h = new Hash();

	h->add("the");
	h->add("tragedy");
	h->add("of");
	h->add("hamlet,");
	h->add("prince");
	/*
	h->add("superhero");
	h->add("alden");
	h->add("blue");
	h->add("george");
	h->add("the");
	h->add("tragedy");
	h->add("Hamlet,");
	h->add("boy");
	h->add("who's");
	h->add("bravo");
	h->add("charlie");
	h->add("delta");
	h->add("echo");
	h->add("epsilon");
	h->add("foxtrot");
	h->add("alden");
	h->add("billie");
	h->add("tony");
	h->add("daredevil");
	h->add("trainwreck");
	*/

	cout << "---FINAL REPORT---" << endl;


	h->reportAll(cerr);

	return 0;
}