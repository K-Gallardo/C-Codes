#pragma once
#include "Edge.h"

class Graph {
public:

	Graph() {}                    //  default constructor 

	virtual ~Graph() {}          //  default destructor

	Graph(const Graph& other) {}  //  copy constructor 

	//add in one Node;    bool returns if it is added successfully.
	virtual bool addNode(Node& v) = 0;   //add in one Node;    bool returns if it is added successfully.

	//Bonus question: add in a set of nodes; bool retruns if it is added successfully
	//virtual bool addNodes(Node* vArray) = 0;

	//the edges that has connection with this Node need to be removed; as a result, some node may remain as orphan.
	virtual bool removeNode(int NID) = 0; // different 

	// return bool if a Node exists in a graph;
	virtual bool searchNode(Node& v) = 0;

	//Bonus question: display the path that contains the Node;
	virtual void display(Node& v) = 0;

	virtual bool addEdge(Edge& e) = 0;  //add an edge to the graph; if an edge already exists, return false;

	//Bonus question : remove a set of edge; as a result, some node may remain as orphan.
	//virtual bool addEdges(Edge* eArray) = 0;

	// remove the edge
	virtual bool remove(Edge& e) = 0;

	// return bool if a Edge exists in a graph;
	virtual bool searchEdge(Edge& e) = 0;

	//Bonus question: display the path that contains the edge;
	//virtual void display(Edge& e) const = 0;

	// display the whole graph with your own defined format
	virtual void display() = 0;

	// convert the whole graph to a string such as 1-2-4-5; 1-3-5; each path is separated by ';'
	// define your own format of a string representation of the graph.
	virtual string toString() = 0;

	//remove all the nodes and edges;
	virtual bool clean() = 0;
};