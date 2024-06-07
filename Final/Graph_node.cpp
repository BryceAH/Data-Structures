//Graph_node.cpp

#include "graph_node.h"
#include "edge.h"

GraphNode::GraphNode(string newName)
{
    value = newName;    

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
