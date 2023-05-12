#include "DGraph.h"

void TestAddandRemoveNode() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing AddNode() function." << endl;

    DGraph graph;
    Node v(1, 10);

    if (graph.addNode(v))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    cout << "\nTesting Remove Node function." << endl;

    if (graph.removeNode(1))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    cout << "\n***************************************************************************************************************\n" << endl;
}

void TestAddandRemoveEdge() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing AddEdge function." << endl;

    DGraph graph;
    Node v(1, 10);
    Node v1(2, 10);
    Edge e(v, v1, 30);

    graph.addNode(v);
    graph.addNode(v1);

    if (graph.addEdge(e))
        cout << "\nPass" << endl;
    else
        cout << "\nFail" << endl;

    cout << "\nTesting Remove Edge function." << endl;

    if (graph.remove(e))
        cout << "\nPass" << endl;
    else
        cout << "\nFail" << endl;

    cout << "\n***************************************************************************************************************\n" << endl;
}

void TestSearchNodeAndEdge() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing the search function for both Node and Edge.\n" << endl;

    DGraph graph;
    Node v(1, 10);
    Node v1(2, 10);
    Edge e(v, v1, 30);

    graph.addNode(v);
    graph.addNode(v1);
    graph.addEdge(e);

    cout << "\n\nWe are now searching for the Node v." << endl;

    if (graph.searchNode(v1))
        cout << "\nPass." << endl;
    else
        cout << "\nFail." << endl;

    cout << "\n\nWe are now searching for the Edge e." << endl;

    if (graph.searchEdge(e))
        cout << "\nPass." << endl;
    else
        cout << "\nFail." << endl;

    cout << "\n***************************************************************************************************************\n" << endl;
}

void TestDisplay() {

    cout << "\n***************************************************************************************************************\n" << endl;
    cout << "Testing the display functions of the whole graph.\n" << endl;

    DGraph graph;
    Node v(1, 10);
    Node v1(2, 10);
    Edge e(v, v1, 30);

    graph.addNode(v);
    graph.addNode(v1);
    graph.addEdge(e);

    // cout << "\n\nTesting displaying the whole graph by passing no arguments." << endl;
    graph.display();

    cout << "\n\nTesting displaying the attributes of the Node by passing Node object v as argument." << endl;
    graph.display(v);

    cout << "\n\nTesting displaying the whole graph using string." << endl;
    cout << graph.toString();

    cout << "\n***************************************************************************************************************\n" << endl;
}

void TestOperatorEqualEqual() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing the operator overload == on objects graph and graph1.\n" << endl;

    try {

        cout << "\nDefinition for graph is as follows : " << endl;

        Node n1(1, 10);
        Node n2(2, 20);
        Node n3(3, 50);
        Edge e1(n1, n2, 30);
        Edge e2(n2, n3, 40);
        Edge e3(n1, n3, 50);

        DGraph graph;

        graph.addNode(n1);
        graph.addNode(n2);
        graph.addNode(n3);
        graph.addEdge(e1);
        graph.addEdge(e2);
        graph.addEdge(e3);
        graph.display();

        cout << "\n\nDefinition for graph1 is as follows : " << endl;

        Node n4(1, 10);
        Node n5(2, 20);
        Node n6(3, 50);
        Edge e4(n4, n5, 30);
        Edge e5(n5, n6, 40);
        Edge e6(n4, n6, 50);

        DGraph graph1;

        graph1.addNode(n4);
        graph1.addNode(n5);
        graph1.addNode(n6);
        graph1.addEdge(e4);
        graph1.addEdge(e5);
        graph1.addEdge(e6);
        graph1.display();

        cout << "\n\nWe are now displaying the result of the operator overload == on graph and graph1." << endl;

        // throw exception
        if (graph == graph1)
            throw runtime_error("\nObject graph is equal to object graph 1\n\nPass\n");
        else
            throw runtime_error("\nObject graph is not equal to object graph 1\n\nFail\n");
    }
    catch (exception& check_result) {
        cout << check_result.what() << endl;
    }

    // run_time inherits from exception

    cout << "\n***************************************************************************************************************\n" << endl;
}

void TestOperatorEqual() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing the operator overload = on objects graph1 and graph2.\n" << endl;

    try {

        cout << "\nDefinition for graph1 is as follows : " << endl;

        Node n1(1, 10);
        Node n2(2, 20);
        Node n3(3, 50);
        Edge e1(n1, n2, 30);
        Edge e2(n2, n3, 40);
        Edge e3(n1, n3, 50);

        DGraph graph1;

        graph1.addNode(n1);
        graph1.addNode(n2);
        graph1.addNode(n3);
        graph1.addEdge(e1);
        graph1.addEdge(e2);
        graph1.addEdge(e3);

        DGraph graph2;

        graph2 = graph1;

        cout << "\n\nWe are now displaying the result of the operator overload = on graph1 and graph2." << endl;

        cout << "\nDisplay of Graph1: \n";
        graph1.display();

        cout << "\nDisplay of Graph2: \n";
        graph2.display();

        // using operator == to see if they graph1 was properly assigned to graph2
        if (graph1 == graph2)
            throw runtime_error("\nThe edges of graph1 was successfully assigned to graph 2.\n\nPass\n");
        else
            throw runtime_error("\nThe edges of graph1 was not assigned to graph 2.\n\nFail\n");
    }
    catch (exception& check_result) {
        cout << check_result.what() << endl;
    }

    cout << "\n***************************************************************************************************************\n" << endl;
}

void TestOperatorPlusPlus() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing the operator overload ++ on object graph.\n" << endl;

    cout << "\nDefinition for graph is as follows : " << endl;

    Node n1(1, 10);
    Node n2(2, 20);
    Node n3(3, 50);
    Edge e1(n1, n2, 30);
    Edge e2(n2, n3, 40);
    Edge e3(n1, n3, 50);

    DGraph graph;

    graph.addNode(n1);
    graph.addNode(n2);
    graph.addNode(n3);
    graph.addEdge(e1);
    graph.addEdge(e2);
    graph.addEdge(e3);

    graph.display();

    try {
        cout << "\n\nWe will now test the prefix ++ on the graph object." << endl;

        ++graph;
    }
    catch (exception& successful) {
        cout << successful.what() << endl;
    }
    catch (...) { // failure
        cout << "\nThe operator ++ has failed to increment the weight by 1.\nFail." << endl;
    }

    try {
        cout << "\n\nWe will now test the postfix ++ on the graph object." << endl;
        graph++;
    }
    catch (exception& successful) {
        cout << successful.what() << endl;
    }
    catch (...) { // failure
        cout << "\nThe operator ++ has failed to increment the weight by 1.\nFail." << endl;
    }

    cout << "\n***************************************************************************************************************\n" << endl;

}

void TestOperatorPlus() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing the operator overload + on objects graph and graph1.\n" << endl;

    cout << "\nDefinition for graph is as follows : " << endl;

    Node n1(1, 10);
    Node n2(2, 20);
    Node n3(3, 50);
    Edge e1(n1, n2, 30);
    Edge e2(n2, n3, 40);
    Edge e3(n1, n3, 50);

    DGraph graph;

    graph.addNode(n1);
    graph.addNode(n2);
    graph.addNode(n3);
    graph.addEdge(e1);
    graph.addEdge(e2);
    graph.addEdge(e3);

    cout << "\n\nDefinition for graph1 is as follows : " << endl;

    Node n4(4, 10);
    Node n5(5, 40);
    Node n6(6, 80);
    Edge e4(n4, n5, 60);
    Edge e5(n4, n6, 100);
    Edge e6(n5, n4, 10);

    DGraph graph1;

    graph1.addNode(n4);
    graph1.addNode(n5);
    graph1.addNode(n6);
    graph1.addEdge(e4);
    graph1.addEdge(e5);
    graph1.addEdge(e6);

    try {
        cout << "\n\nWe are now displaying the result of the operator overload + on graph and graph1." << endl;

        DGraph graph2 = graph + graph1;

        if (graph2.EdgeArray1[0].getStart().getId() != 1)
            throw runtime_error("The addition of the two DGraph objects is unssuccessful.\nFail");
        else
            throw runtime_error("The addition of the two DGraph objects is successful.\nPass");
    }
    catch (exception& check_result) {
        cout << check_result.what() << endl;
    }

    cout << "\n***************************************************************************************************************\n" << endl;
}

void TestOperatorSubcript() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing the operator overload [] on object graph.\n" << endl;

    cout << "\nDefinition for graph is as follows : " << endl;

    Node n1(1, 10);
    Node n2(2, 20);
    Node n3(3, 50);
    Edge e1(n1, n2, 30);
    Edge e2(n2, n3, 40);
    Edge e3(n1, n3, 50);

    DGraph graph;

    graph.addNode(n1);
    graph.addNode(n2);
    graph.addNode(n3);
    graph.addEdge(e1);
    graph.addEdge(e2);
    graph.addEdge(e3);

    try {
        cout << "\n\nWe are now displaying the result of the operator overload [] on graph[0]." << endl;

        Node v4;
        v4 = graph[0];

        if (v4.getId() != n1.getId())
            throw runtime_error("\nThe operator overload is unsuccessful.\nFail");

        cout << "\nThe Node at position graph[0] has an id of " << v4.getId() << " and a value of " << v4.getValue() << "." << endl;
        throw runtime_error("\nThe operator overload is successful.\nPass");
    }
    catch (exception& check_result) {
        cout << check_result.what() << endl;
    }

    cout << "\n***************************************************************************************************************\n" << endl;
}

void TestOperatorStream() {

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "Testing the operator overload [] on object graph.\n" << endl;

    cout << "\nDefinition for graph is as follows : " << endl;

    Node n1(1, 10);
    Node n2(2, 20);
    Node n3(3, 50);
    Edge e1(n1, n2, 30);
    Edge e2(n2, n3, 40);
    Edge e3(n1, n3, 50);

    DGraph graph;

    graph.addNode(n1);
    graph.addNode(n2);
    graph.addNode(n3);
    graph.addEdge(e1);
    graph.addEdge(e2);
    graph.addEdge(e3);

    cout << "\n***************************************************************************************************************\n" << endl;
}

int main()
{
    cout << "In this assignment we create an undirected graph with 3 Nodes & 3 edges." << endl;
    cout << "\nWe will now begin Modular Testing.\n" << endl;

    int Test;

    do {

        cout << "\nWhich of the following tests would you like to invoke?\n" << endl;
        cout << "1. Test the Add Node and Remove Node function.\n"
            << "2. Test the Add Edge and Remove Edge function.\n"
            << "3. Test the Search Node amd Search Edge function.\n"
            << "4. Test the Display functions.\n"
            << "5. Test the operator == overload function.\n"
            << "6. Test the operator = overload function.\n"
            << "7. Test the operator ++ overload function.\n"
            << "8. Test the operator + overload function.\n"
            << "9. Test the operator [] overload function.\n"
            << "10. Test the operator (string) overload function.\n"
            << "11. Exit Modular Testing.\n" << endl;

        cout << "Enter the test number : ";
        cin >> Test;

        switch (Test) {
        case 1:
            TestAddandRemoveNode();
            continue;
        case 2:
            TestAddandRemoveEdge();
            continue;
        case 3:
            TestSearchNodeAndEdge();
            continue;
        case 4:
            TestDisplay();
            continue;
        case 5:
            TestOperatorEqualEqual();
            continue;
        case 6:
            TestOperatorEqual();
            continue;
        case 7:
            TestOperatorPlusPlus();
            continue;
        case 8:
            TestOperatorPlus();
            continue;
        case 9:
            TestOperatorSubcript();
            continue;
        case 10:
            TestOperatorStream();
            continue;
        case 11:
            break;
        }
    } while (Test != 11);

    cout << "\nModular Testing is completed. All results are wiped out and we restart from scratch to build the graph.\n" << endl;
   /* cout << "\nThis is the main:" << endl;

    // Definition for graph as follows

    Node v(1, 10);                          // creates object v and initialized with Object ID & Value.

    Node v1(2, 10);  // creates object v1 and initialized with Object ID & Value.

    Node v2(3, 10); // creates object v2 and initialized with Object ID & Value.

    Edge e(v, v1, 30);                 // creates Edge  e  and initialized with Source node ID , Destination node ID & weight.

    Edge e1(v, v2, 10);                 // creates Edge  e1  and initialized with Source node ID , Destination node ID & weight. 

    Edge e2(v1, v2, 50);                // creates Edge  e2  and initialized with Source node ID , Destination node ID & weight.   

    DGraph graph;    // create object graph in the derived class

    // Definition for graph 1 as follows

    Node v3(1, 10);                          // creates object v and initialized with Object ID & Value.

    Node v4(3, 20);  // creates object v1 and initialized with Object ID & Value.

    Node v5(6, 50); // creates object v2 and initialized with Object ID & Value.

    Edge e3(v3, v4, 40);                 // creates Edge  e  and initialized with Source node ID , Destination node ID & weight.

    Edge e4(v3, v5, 50);                 // creates Edge  e1  and initialized with Source node ID , Destination node ID & weight. 

    Edge e5(v4, v5, 60);                // creates Edge  e2  and initialized with Source node ID , Destination node ID & weight.   

    DGraph graph1;    // create object graph in the derived class

    //add Node for graph
    graph.addNode(v);
    graph.display(v);

    graph.addNode(v1);
    graph.display(v1);

    graph.addNode(v2);
    graph.display(v2);

    //add edges for graph
    graph.addEdge(e);
    graph.display();

    graph.addEdge(e1);
    graph.display();

    graph.addEdge(e2);
    graph.display();

    //add Node for graph 1
    graph1.addNode(v3);
    graph1.display(v3);

    graph1.addNode(v4);
    graph1.display(v4);

    graph1.addNode(v5);
    graph1.display(v5);

    //add edges for graph 1
    graph1.addEdge(e3);
    graph1.display();

    graph1.addEdge(e4);
    graph1.display();

    graph1.addEdge(e5);
    graph1.display();

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "\nWe are now displaying the result of the operator overload == on graph and graph1." << endl;

    if (graph1 == graph1)
        cout << "\nOject graph is equal to object graph 1\n";
    else
        cout << "\nObject graph is not equal to object graph 1\n";

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "\nCalling operator overload =" << endl;

    DGraph graph2;

    graph2 = graph1;

    cout << "\nWe are now displaying the result of the operator overload = on graph1 and graph2." << endl;

    cout << "\nDisplay of Graph1: ";
    graph1.display();

    cout << "\nDisplay of Graph2: ";
    graph2.display();

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "\nWe are now displaying the result of the operator overload prefix ++ on graph." << endl;

    cout << "\nWe will first display the graph:" << endl;
    graph.display();

    cout << "\nWe will now display the result of the operator overload prefix ++ on the graph. The weight incremented by 1." << endl;
    ++graph;
    graph.display();

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "\nWe are now displaying the result of the operator overload postfix ++ on graph." << endl;

    cout << "\nWe will first display the graph:" << endl;
    graph.display();

    cout << "\nWe will now display the result of the operator overload postfix ++ on the graph. The weight incremented by 1." << endl;
    graph++;
    graph.display();

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "\nWe are now displaying the result of the operator overload + on graph1 and graph2." << endl;

    graph1 + graph2;

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "\nWe are now displaying the result of the operator overload [] on graph[0]." << endl;

    Node v6;
    v6 = graph[0];

    cout << "\nThe Node at position graph[0] has an id of " << v6.getId() << " and a value of " << v6.getValue() << "." << endl;

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "\nWe are now displaying the result of the operator overload << on graph to replace cout.\n" << endl;

    cout << graph;

    cout << "\n***************************************************************************************************************\n" << endl;

    cout << "\nWe are now searching for the Node v." << endl;
    // Searching Node
    graph.searchNode(v1);

    // display the whole array
    graph.display();

    // display the whole array using string
    cout << graph.toString();

    //Remove Node
    int flag = 0;
    int choice = 0;
    cout << "\nRemoving a Node from the Graph, Please type in  1 for object 1, 2 for object 2, 3 for object 3 :  " << endl;
    cin >> flag;

    while (flag != 0) {
        if (flag == 1)
            graph.removeNode(v.getId());
        else   if (flag == 2)
            graph.removeNode(v1.getId());
        else  if (flag == 3)
            graph.removeNode(v2.getId());
        else
            cout << "\nWrong choice please enter 1 or 2 or 3 as a choice : " << endl;
        if (choice < 3) {
            cout << "\nEnter another object to remove." << endl;
            choice++;
            cin >> flag;
        }
        else
        {
            cout << "\nSorry, you have tried more than 3 times. You can no longer remove a Node." << endl;
            flag = 0;
            break;
        }
    }

    if (graph.remove(e1)) {

        cout << "\nnow we must delete the path(value) for the src node and the dest node in the NodeArray" << endl;

        int scr_node_id = e1.getStart().getId();
        int dest_node_id = e1.getEnd().getId();

        int i;
        for (i = 0; i < 3; i++) {

            if (graph.NodeArray[i].getId() == scr_node_id) {
                graph.NodeArray[i].setValue(0);
                break;
            }
        }

        int j;
        for (j = i; j < 3; j++) {

            if (graph.NodeArray[j].getId() == dest_node_id) {
                graph.NodeArray[j].setValue(0);
                break;
            }
        }

        cout << "\nThe path(value) for the src node and the dest node in the NodeArray is set to zero" << endl;
    }

    */
    return 0;
}