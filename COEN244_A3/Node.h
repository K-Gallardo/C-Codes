#pragma once
#include <iostream>
using namespace std;

class Node
{
private:

	int id;
	int value;

public:

	// default constrcutor
	Node() {      //default constructor
		id = 0;
		value = 0;   // Initialize constructor
	}

	// parametized constructor
	Node(int i, int v) { // Initialize constructor called first
		id = i;
		value = v;
	}

	// copy constructr
	Node(const Node& v) {
		id = v.id;
		value = v.value;
	}

	// destructor
	~Node() {}

	//  getter methods 
	int getId() { return id; }

	int getValue() { return value; }

	// setter methods
	void setId(int i) { id = i; }

	void setValue(int v) { value = v; }
};