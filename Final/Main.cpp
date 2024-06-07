//main.cpp

//at 31:38 in cs260_spring_2023 session 27 

#include <iostream>
#include "graph_node.h"
#include "edge.h"

using namespace std;

int main()
{
edge *testEdge = new edge{nullptr, nullptr, 42};
cout << "testEdge ->source: " << testEdge->source << "\ntestEdge->Destination: " << testEdge->destination << "\ntestEdge->weight: " << testEdge->weight << endl;

GraphNode newNode; 
// cout << "newNode.getValue: " << newNode.getValue() << "\nnewNode.getNeighbors().size(): "<< newNode.getNeighbor().size() << endl;

cout << "end of program" << endl;


return 0;       
}
