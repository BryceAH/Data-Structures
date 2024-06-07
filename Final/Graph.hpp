//Graph.hpp

// starts at 60 in cs260_spring_2023 session 27 


#include "graph_node.h"   

class Graph
{

public:

    Graph();
    ~Graph();

    void addNode(string newName);

    void addEdge(string sourceName, string destinationName, int weight);

    int getSize();

    string shortestPath(string sourceName);

    string minimumSpanningTree();
private:

    vector<GraphNode *> nodes;



};
