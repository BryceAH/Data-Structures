//main.cpp

//at 60 in cs260_spring_2023 session 27 

#include <iostream>
#include "graph_node.h"
#include "edge.h"
#include "Graph_node.cpp"

using namespace std;

int main()
{
edge *testEdge = new edge{nullptr, nullptr, 42};
cout << "testEdge ->source: " << testEdge->source << "\ntestEdge->Destination: " << testEdge->destination << "\ntestEdge->weight: " << testEdge->weight << endl;

GraphNode *newNode = new GraphNode("Albany"); 
cout << "newNode->getValue: " << newNode->getValue() << "\nnewNode->getNeighbors().size(): "<< newNode->getNeighbor().size() << endl;

newNode->addedge(newNode, 1);

cout << "newNode->getNeighbor().size(): " << newNode->getNeighbor().size() << endl;
cout << "newNode->getNeighbor().at(0)->destination->getValue(): " << newNode->getNeighbor().at(0)->destination->getValue() << endl;


delete newNode;


cout << "end of program" << endl;


return 0;       
}
