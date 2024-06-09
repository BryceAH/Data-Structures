// main.cpp

#include <iostream>
#include "Graph.hpp"
#include "Graph.cpp"
#include "graph_node.h"
#include "Graph_node.cpp"
#include "edge.h"


using namespace std;

int main()
{
Graph g;

cout << "Graph number one " << endl;
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

cout << "Added 5 nodes A,B,C,D,E" << endl;

g.display();

g.shortestPath("A");

g.minimumSpanningTree("A");

cout << "Graph number 2 \n" << endl;
Graph b;

b.addNode("A");
b.addNode("B");
b.addNode("C");
b.addNode("D");
b.addNode("E");

b.connectNodes("A","C", 4);
b.connectNodes("A","B", 8);
b.connectNodes("C","B", 6);
b.connectNodes("C","E", 10);
b.connectNodes("C","D", 8);
b.connectNodes("E","D", 2);
b.connectNodes("B","E", 6);
b.connectNodes("B","D", 4);



cout << "Added 5 nodes A,B,C,D,E" << endl;

b.display();

b.shortestPath("A");

b.minimumSpanningTree("A");




cout << "end of program" << endl;

return 0;       
}
