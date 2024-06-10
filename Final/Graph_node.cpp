/*
Graph_node.cpp
Name: Bryce Hillsman
Student id: x00505693
Date: 6/10/2024

    Graph_node.cpp contains all the functions for the GraphNode class such as GraphNode() which is the constructor that initializes the value
to a provided name, the previous to null-pointer, and the distance to a very large number to simulate infinity. addedge() that adds the edges to the 
graph. The getValue() which returns the value of the node. getNeighbor() which returns a vector of neighbors to the node. getDistance() which 
returns the distance from the node to the source node. setDistance() which sets the distance from the node to the source node. setPrevious() which sets the 
previous node in the path to the source node. getPrevious() which returns the previous node.
*/

#pragma once

#include "graph_node.h"
#include "edge.h"
#include <iostream>
#include <limits>


using namespace std;

GraphNode::GraphNode(string newName)
{
    value = newName; 
    prev = nullptr;
    distance =  numeric_limits<int>::max(); // infinity-ish  
}

void GraphNode::addedge(GraphNode *destination, int weight)
{
    edge *newEdge = new edge{this, destination, weight};
    neighbors.push_back(newEdge);
}

GraphNode::~GraphNode()
{
for (auto neighbor: neighbors)
{
    delete neighbor;
}
neighbors.clear();
}

string GraphNode::getValue()
{
    return value;
}

vector<edge *> GraphNode::getNeighbor()
{
    return neighbors;
}

int GraphNode::getDistance()
{
    return distance;
}

void GraphNode::setDistance(int input)
{
    distance = input;
}

void GraphNode::setPrevious(GraphNode *input)
{
    prev = input;
}

GraphNode *GraphNode::getPrevious()
{
    return prev;
}
