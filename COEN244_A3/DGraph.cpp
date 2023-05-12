#include "DGraph.h"
#include <sstream>

// default constrcutor 
// There is nothing in the default constructor because the only members of DGraph are
// Node and Edge objects, so the constructor for both those classes are called
DGraph::DGraph() {}

// destructor of DGraph
DGraph::~DGraph() { cout << "\nDestructor of DGraph called." << endl; }

//add in one Node; bool returns if it is added successfully.
bool DGraph::addNode(Node& nod) {

    int size = 3;

    for (int i = 0; i < size; i++)
    {
        // checks if a node with this ID exists
        if (NodeArray[i].getId() == nod.getId()) {
            cout << "Node with this ID already exists, Node entry unsuccessfull.";
            return false;
        }

        // check for empty spot in array
        else if (NodeArray[i].getId() == 0)
        {
            NodeArray[i].setId(nod.getId());
            NodeArray[i].setValue(nod.getValue());
            cout << "\nNode added successfully : (" << NodeArray[i].getId() << ", " << NodeArray[i].getValue() << ")" << endl;
            return true;
        }

        // if the array is full
        else if (i == (size - 1)) {
            cout << "Only 3 Nodes objects can exist, Node entry unsuccessfull." << endl;
            return false;
        }
    }

    //if for loop not successful, return fail
    return false;
}// eof addNode method.

//add in one Edge; bool returns if it is added successfully.
bool DGraph::addEdge(Edge& e)
{
    int size = 3;

    for (int i = 0; i < size; i++)
    {
        // check if edge already exists
        if (EdgeArray[i].getStart().getId() == e.getStart().getId() &&
            EdgeArray[i].getEnd().getId() == e.getEnd().getId() &&
            EdgeArray[i].getWeight() == e.getWeight()) {

            cout << "This Edge already exists, cannot add within the array." << endl;
            return false;
        }

        // check for empty spot in EdgeArray
        else if (EdgeArray[i].getStart().getId() == 0)
        {
            EdgeArray[i].setStart(e.getStart());
            EdgeArray[i].setEnd(e.getEnd());
            EdgeArray[i].setWeight(e.getWeight());

            cout << "\nEdge added successfully: (" << e.getStart().getId() << ", " << e.getEnd().getId() << ", " << e.getWeight() << ")" << endl;
            return true;
        }

        // if the array is full
        else if (i == (size - 1)) {
            cout << "\nEdge was not added successfully." << endl;
            return false;
        }
    }

    //if for loop not successful, return fail
    return false;
}// eof addEdge method.

 // Remove Node the edges that has connection0ith this Nodes also  need to be removed;
bool DGraph::removeNode(int NID) {

    int flag = 0;
    int Size = 3;

    // for loop going through all the elements in array 	
    for (int i = 0; i < Size; i++) {

        // looking for index where the desired ID number is 	
        if (NodeArray[i].getId() == NID) {

            cout << "\nNode with ID number found, object is erased and NodeArray is updated." << endl;
            flag = i;
            break;
        }

        // if Node was not found, 
        if (i == (Size - 1)) {
            cout << "\nNode with ID not found, NodeArray remains unchanged." << endl;
            return false;
        }
    }

    // If the ID was found in the NodeArray, int i now has the index of where the ID number was found  	
    if (flag < Size) {

        // reduce number of items inside of the array
        Size--;

        // Shifting values of NodeArray using for loop going though all members on the right side of index i
        for (int j = flag; j < Size; j++)
        {
            // assigning all items one spot to the left 			
            NodeArray[j] = NodeArray[j + 1];
        }

        cout << "Node successfully removed." << endl;
        return true;
    }

    //if for loop not successful, return fail
    return false;
}

// search for a Node using Node object
bool DGraph::searchNode(Node& other)
{
    int size = 3;

    cout << "\nThe Node we are looking for is " << other.getId() << "." << endl;

    for (int i = 0; i < size; i++)
    {
        if (NodeArray[i].getId() != other.getId())
        {
            cout << "\nNode found successfully (" << other.getId() << ", " << other.getValue() << ")" << endl;
            return true;
        }
        else if (i == (size - 1))
        {
            cout << "\nNode was not found successfully." << endl;
            return false;
        }
    }

    //if for loop not successful, return fail
    return false;
}

// search for a Edge using Edge object
bool DGraph::searchEdge(Edge& e) {

    int size = 3;

    cout << "\nThe Edge we are looking for is : " << e.getStart().getId() << " " << e.getEnd().getId()
        << " " << e.getWeight() << "." << endl;

    for (int i = 0; i < size; i++) {

        if (EdgeArray[i].getStart().getId() == e.getStart().getId() &&
            EdgeArray[i].getEnd().getId() == e.getEnd().getId() &&
            EdgeArray[i].getWeight() == e.getWeight()) {

            cout << "\nEdge found successfully." << endl;
            cout << EdgeArray[i].getStart().getId() << " " << EdgeArray[i].getEnd().getId()
                << " " << EdgeArray[i].getWeight() << endl;

            return true;
        }
        else if (i == (size - 1))
        {
            cout << "\nEdge was not found successfully " << endl;
            return false;
        }
    }

    //if for loop not successful, return fail
    return false;
}

// display the edgearray, ie the whole graph with your own defined format
void DGraph::display() {

    // counter for empty spots within the NodeArray
    int flag = 0;

    // checking for empty spots within the array
    for (int i = 0; i < 3; i++) {

        if (this->NodeArray[i].getId() == 0) {
            flag++;
        }
    }

    cout << "\nWe are now displaying the whole graph.\n" << endl;

    for (int i = 0; i < 3; i++) {

        cout << this->EdgeArray[i].getStart().getId() << " " << EdgeArray[i].getEnd().getId()
            << " " << this->EdgeArray[i].getWeight() << endl;
    }
}

// display the path of a certain node using node object
void DGraph::display(Node& v) {

    int size = 3;

    for (int i = 0; i < size; i++) {

        if (NodeArray[i].getId() != v.getId())
        {
            cout << "\nNode display, here is ID and Path of the Node (" << v.getId() << ", " << v.getValue() << ")" << endl;
            return;
        }
        else if (i == (size - 1))
        {
            cout << "\nCannot display the Node and its Paths. Node was not found " << endl;
            return;
        }
    }
}

// remove Edge using Edge object
bool DGraph::remove(Edge& e) {

    /*first find the index of the desired ID Edge, then use that index value to delete the edge and its passes to its neighbor nodes .
    It may become an orphan Node.*/

    // The index i is thus defined outside of the for loop
    int i;
    int Size = 3;
    int src_path = 0;
    int dest_path = 0;

    // for loop going through all the elements of the EdgeArray.
    for (i = 0; i < Size; i++) {

        //cout << "\n" << EdgeArray[i].getStart().getId() << "," << EdgeArray[i].getEnd().getId() << "," << EdgeArray[i].getWeight();

        if ((EdgeArray[i].getStart().getId() == e.getStart().getId()) &&
            (EdgeArray[i].getEnd().getId() == e.getEnd().getId())) {

            cout << "\nFound the edge object " << "(" << e.getStart().getId() << ", " << e.getEnd().getId() << ", " << e.getWeight() << ")" << endl;
            break;
        }

        // if ID was not found, exit remove()
        if (i == (Size - 1)) {
            cout << "\nEdge was not found." << endl;
            return false;
        }
    }

    // If the Edge found in the EdgeArray,  we now must delete the Edgae in the EdgeArry and delete value (path) for each Node in the NodeArray.  
    if (i < Size) {

        // reduce number of items inside of the array
        Size--;

        // Shifting values of NodeArray using for loop going though all members on the right side of index i
        for (int j = i; j < Size; j++) {
            // assigning all items one spot to the left
            EdgeArray[j] = EdgeArray[j + 1];
        }

        cout << "Edge successfully removed." << endl;
        return true;
    }
}

//remove all the nodes and edges;
bool DGraph::clean() {

    cout << "We have removed all the nodes and edges." << endl;
    this->~DGraph();
    return true;
}

// display the edgearray using string
string DGraph::toString()  // called second
{
    stringstream s;

    cout << "\nWe are displaying graph as a string: Source Node ID - Destination Node ID - Weight.\n" << endl;

    for (int i = 0; i < 3; i++) {

        s << this->EdgeArray[i].getStart().getId() << " - " << this->EdgeArray[i].getEnd().getId()
            << " - " << this->EdgeArray[i].getWeight() << endl;
    }

    return s.str();
}

// return TRUE if e & e1 have the same exact Nodes and Edges
bool DGraph::operator == (DGraph& g1)
{
    // flags to check how many objects are similar
    int eflag = 0;
    int nflag = 0;

    // for loop going through all 3 elements in array
    for (int i = 0; i < 3; i++) {

        // checking edges
        if (this->EdgeArray[i].getStart().getId() == g1.EdgeArray[i].getStart().getId() &&
            this->EdgeArray[i].getEnd().getId() == g1.EdgeArray[i].getEnd().getId() &&
            this->EdgeArray[i].getWeight() == g1.EdgeArray[i].getWeight())
            eflag++;

        // checking nodes
        if (this->NodeArray[i].getId() == g1.NodeArray[i].getId() &&
            this->NodeArray[i].getValue() == g1.NodeArray[i].getValue())
            nflag++;
    }

    if (eflag == 3 && nflag == 3)
        return true;
    else
        return false;
}

// assigning the edges of graph2 to the current object
void DGraph::operator= (DGraph& graph2) {

    // assigning EdgeArray from graph 1 to graph 2
    for (int i = 0; i < 3; i++) {

        this->EdgeArray[i].setStart(graph2.EdgeArray[i].getStart());
        this->EdgeArray[i].setEnd(graph2.EdgeArray[i].getEnd());
        this->EdgeArray[i].setWeight(graph2.EdgeArray[i].getWeight());
    }

    // assigning NodeArray from graph 1 to graph 2
    for (int i = 0; i < 3; i++) {

        this->NodeArray[i].setId(graph2.NodeArray[i].getId());
        this->NodeArray[i].setValue(graph2.NodeArray[i].getValue());
    }
}

// prefix ++ that increments all weigth by 1 
void DGraph::operator++ () {

    for (int i = 0; i < 3; i++) {

        int w = this->EdgeArray[i].getWeight();
        this->EdgeArray[i].setWeight(++w);
    }

    this->display();

    throw runtime_error("\nUsing the prefix ++ operator, the weight of all Edge objects have increased by 1.\n\nPass\n");
}

// postfix ++ that increments all weigth by 1 
void DGraph::operator++ (int) {

    for (int i = 0; i < 3; i++) {

        int w = this->EdgeArray[i].getWeight();
        this->EdgeArray[i].setWeight(++w);
    }

    this->display();

    throw runtime_error("\nUsing the postfix ++ operator, the weight of all Edge objects have increased by 1.\n\nPass\n");
}

// returns a graph that contains all the node and edges of graph and graph1
DGraph DGraph::operator+ (DGraph& graph2) {

    DGraph temp;

    // adding the fist object within the array
    for (int i = 0; i < 3; i++) {

        Node n1, n2;
        int w;

        n1.setId(this->EdgeArray[i].getStart().getId());
        n2.setId(this->EdgeArray[i].getEnd().getId());
        w = this->EdgeArray[i].getWeight();


        temp.EdgeArray1[i].setStart(n1);
        temp.EdgeArray1[i].setEnd(n2);
        temp.EdgeArray1[i].setWeight(w);

        cout << "\nIn index position " << i << " : "
            << "Start id: " << temp.EdgeArray1[i].getStart().getId()
            << ", end id: " << temp.EdgeArray1[i].getEnd().getId()
            << ", weight: " << temp.EdgeArray1[i].getWeight() << endl;
    }

    // adding the second object within the array
    for (int i = 0; i < 3; i++) {

        Node n1, n2;
        int w;

        n1.setId(graph2.EdgeArray[i].getStart().getId());
        n2.setId(graph2.EdgeArray[i].getEnd().getId());
        w = graph2.EdgeArray[i].getWeight();


        temp.EdgeArray1[i + 3].setStart(n1);
        temp.EdgeArray1[i + 3].setEnd(n2);
        temp.EdgeArray1[i + 3].setWeight(w);


        cout << "\nIn index position " << i + 3 << " : "
            << "Start id: " << temp.EdgeArray1[i + 3].getStart().getId()
            << ", end id: " << temp.EdgeArray1[i + 3].getEnd().getId()
            << ", weight: " << temp.EdgeArray1[i + 3].getWeight() << endl;
    }

    return temp;
}

// return the node at the index position
Node DGraph::operator[] (int subnum) {

    Node temp;

    temp.setId(this->NodeArray[subnum].getId());
    temp.setValue(this->NodeArray[subnum].getValue());

    return temp;
}

// operator overlodaing of cout << graph
ostream& operator<<(ostream& output, DGraph& graph) {


    for (int i = 0; i < 3; i++) {

        output << graph.EdgeArray[i].getStart().getId() << " - " << graph.EdgeArray[i].getEnd().getId()
            << " - " << graph.EdgeArray[i].getWeight() << endl;
    }

    return output;
}

// casts the graph object to a string that encodes all the edges.
/*
string DGraph::operator() (DGraph& graph) {

    stringstream s;

    cout << "\nWe are displaying graph as a string: Source Node ID - Destination Node ID - Weight." << endl;

    for (int i = 0; i < 3; i++) {

        s << graph.EdgeArray[i].getStart().getId() << " - " << graph.EdgeArray[i].getEnd().getId()
            << " - " << graph.EdgeArray[i].getWeight() << endl;
    }

    return s.str();

}
*/