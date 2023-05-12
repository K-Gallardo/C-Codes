#pragma once
#include "Graph.h"

class DGraph : public Graph
{
public:

	Node NodeArray[3];
	Edge EdgeArray[3];

	// array for operator + overloading with 6 edge array values 
	Edge EdgeArray1[6];

	DGraph();   // default constructor 

	~DGraph();

	//add in one Node;    bool returns if it is added successfully.
	bool addNode(Node& v);

	//Bonus question: add in a set of nodes; bool retruns if it is added successfully
	//bool addNodes(Node* vArray);

	//the edges that has connection with this Node need to be removed; as a result, some node may remain as orphan.
	bool removeNode(int NID); // different 

	// return bool if a Node exists in a graph;
	bool searchNode(Node& v);

	//Bonus question: display the path that contains the Node;
	void display(Node& v);

	bool addEdge(Edge& e);  //add an edge to the graph; if an edge already exists, return false;

	//Bonus question : remove a set of edge; as a result, some node may remain as orphan.
	//bool addEdges(Edge* eArray);

	// remove the edge
	bool remove(Edge& e);

	// return bool if a Edge exists in a graph;
	bool searchEdge(Edge& e);

	//Bonus question: display the path that contains the edge;
	//void display(Edge& e) const;

	// display the whole graph with your own defined format
	void display();

	// convert the whole graph to a string such as 1-2-4-5; 1-3-5; each path is separated by ';'
	// define your own format of a string representation of the graph.
	string toString();

	// remove all the nodes and edges;
	bool clean();

	// operator overloading section:

	// verifying if the edges are the same
	bool operator== (DGraph& g1);

	// assigning the edges of graph2 to the current object
	void operator= (DGraph& graph2);

	// prefix ++ that increments all weigth by 1 
	void operator++ ();

	// postfix ++ that increments all weigth by 1 
	void operator++ (int);

	// returns a graph that contains all the node and edges of graph and graph1
	DGraph operator+ (DGraph& graph);

	// return the node at the index position
	Node operator[] (int);

	// cout << all edges
	friend ostream& operator<<(ostream&, DGraph&);

	// casts the graph object to a string that encodes all the edges.
	// string operator() (DGraph& graph);
};