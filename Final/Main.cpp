//main.cpp

//at 60 in cs260_spring_2023 session 27 

#include <iostream>
#include "Graph.hpp"
#include "Graph.cpp"
#include "graph_node.h"
#include "Graph_node.cpp"
#include "edge.h"


using namespace std;

int main()
{
// edge *testEdge = new edge{nullptr, nullptr, 42};
// cout << "testEdge ->source: " << testEdge->source << "\ntestEdge->Destination: " << testEdge->destination << "\ntestEdge->weight: " << testEdge->weight << endl;

// GraphNode *newNode = new GraphNode("Albany"); 
// cout << "newNode->getValue: " << newNode->getValue() << "\nnewNode->getNeighbors().size(): "<< newNode->getNeighbor().size() << endl;

// newNode->addedge(newNode, 1);

// cout << "newNode->getNeighbor().size(): " << newNode->getNeighbor().size() << endl;
// cout << "newNode->getNeighbor().at(0)->destination->getValue(): " << newNode->getNeighbor().at(0)->destination->getValue() << endl;


// delete newNode;

Graph g;

g.addNode("A");
g.addNode("B");
g.addNode("C");
g.addNode("D");
g.addNode("E");

g.connectNodes("A","C", 2);
g.connectNodes("A","B", 4);
g.connectNodes("C","B", 3);
g.connectNodes("C","E", 5);
g.connectNodes("C","D", 4);
g.connectNodes("E","D", 1);
g.connectNodes("B","E", 3);
g.connectNodes("B","D", 2);


g.shortestPath("A");
g.minimumSpanningTree("A");

// cout << g.getSize() << endl;



cout << "end of program" << endl;


return 0;       
}
