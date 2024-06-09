// Graph_node.cpp

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
