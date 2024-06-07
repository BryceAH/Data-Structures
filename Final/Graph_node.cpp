//Graph_node.cpp

// 45min

#include "graph_node.h"
#include "edge.h"

GraphNode::GraphNode()
{
    value = "";    

}

void GraphNode::addedge(GraphNode *destination, int weight)
{
    edge *newEdge = new edge{this, destination, weight};
    neighbors.push_back(newEdge);
}

string GraphNode::getValue()
{
return value;

}

vector<edge *> GraphNode::getNeighbor()
{
    return neighbors;

}
