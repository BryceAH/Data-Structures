//Graph.hpp

// starts at 60 in cs260_spring_2023 session 27 

#pragma once

#include "graph_node.h"   

class Graph
{

public:

    Graph();
    ~Graph();

    void addNode(string newName); // to add the verticies / nodes to the graph

    //add edge
    void connectNodes(string sourceName, string destinationName, int weight); // to connect the nodes together with a weight

    int getSize(); // gets total amount of nodes in graph

    string shortestPath(string sourceName); // finds shortest distance from chosen node to every other node

    void minimumSpanningTree(string sourceName);

    void printPath(GraphNode* node);
private:

    vector<GraphNode *> nodes;



};
