#include <iostream>
#include "Graph.hpp"
#include "Graph.cpp"
#include "graph_node.h"
#include "Graph_node.cpp"
#include "edge.h"

using namespace std;

int main()
{

///////////////////////////////Graph g////////////////////////////////

Graph g;

g.Tests();

g.printSlash();

cout << "Graph number one \n" << endl;

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

g.printSlash();

//////////////////////////////////////////////////////////////////////

///////////////////////////////Graph b////////////////////////////////

cout << "Graph number 2 \n" << endl;
Graph b;

b.addNode("A");
b.addNode("B");
b.addNode("C");
b.addNode("D");
b.addNode("E");

b.connectNodes("C","A", 9);
b.connectNodes("C","E", 18);
b.connectNodes("A","E", 14);
b.connectNodes("A","D", 29);
b.connectNodes("A","B", 24);
b.connectNodes("D","B", 5);
b.connectNodes("E","D", 14);
b.connectNodes("E","B", 9);

cout << "Added 5 nodes A,B,C,D,E" << endl;

b.display();

b.shortestPath("A");

b.minimumSpanningTree("A");

//////////////////////////////////////////////////////////////////////
///////////////////////////////Graph Oregon///////////////////////////

g.printSlash();

cout << "Graph Oregon \n" << endl;
Graph o;

o.addNode("Corvallis");
o.addNode("Tangent");
o.addNode("Brownsville");
o.addNode("Sweet Home");
o.addNode("Albany");
o.addNode("Lebanon");
o.addNode("I-5");

o.connectNodes("Corvallis", "Albany", 9);
o.connectNodes("Corvallis", "Tangent", 8.2);
o.connectNodes("Albany", "Tangent", 6.8);
o.connectNodes("Albany", "Lebanon", 12);
o.connectNodes("Albany", "I-5", 5.8);
o.connectNodes("Tangent", "I-5", 0.5);
o.connectNodes("Tangent", "Brownsville", 11.9);
o.connectNodes("Lebanon", "I-5", 9.8);
o.connectNodes("Lebanon", "Brownsville", 10.8);
o.connectNodes("Sweet Home", "Lebanon", 12.6);
o.connectNodes("Brownsville", "I-5", 12);
o.connectNodes("Brownsville", "Sweet Home", 12.4);

cout << "Added 7 nodes Corvallis,Tangent,Brownsville,Sweet Home,Albany,Lebanon,I-5" << endl;

o.display();

o.shortestPath("Sweet Home");

o.minimumSpanningTree("Lebanon");

g.printSlash();

//////////////////////////////////////////////////////////////////////

cout << "end of program" << endl;

return 0;       
}
