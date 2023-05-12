#pragma once
#include "Node.h"

class Edge
{
private:

	Node start, end;
	int weight;

public:

	// default constructor
	Edge() {
		// the default constrcutor for Node is also called in this constrcutor
		weight = 0;
	}

	// parametized constructor
	Edge(Node& s, Node& e, int w) {
		start = s;
		end = e;
		weight = w;
	}

	// copy constructor
	Edge(const Edge& e) {
		start = e.start;
		end = e.end;
		weight = e.weight;
	}

	// destructor
	~Edge() {}

	// getter methods
	int getWeight() { return weight; }

	Node getStart() { return start; }

	Node getEnd() { return end; }

	// setter methods
	void setWeight(int w) { weight = w; }

	void setStart(Node v) { start = v; }

	void setEnd(Node v) { end = v; }
};