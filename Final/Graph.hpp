#pragma once

#include "graph_node.h"   

class Graph
{

public:

    Graph();
    ~Graph();

    void addNode(string newName); // to add the verticies / nodes to the graph

    void connectNodes(string sourceName, string destinationName, int weight); // to connect the nodes together with a weight

    int getSize(); // gets total amount of nodes in graph

    string shortestPath(string sourceName); // finds shortest distance from chosen node to every other node

    void minimumSpanningTree(string sourceName); // finds the shortest distance to touch every node

    void printPath(GraphNode* node); // used to print the shortest distances

    void display(); // displays the nodes that are added

    void printSlash(); // this is to print the slashes in the output

    void Tests(); // used to test the various functions

private:

    vector<GraphNode *> nodes;
};
