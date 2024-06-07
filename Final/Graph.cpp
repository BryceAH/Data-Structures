#include "Graph.hpp"

//https://moodle.linnbenton.edu/mod/page/view.php?id=1552132&inpopup=1

Graph::Graph()
{

}
Graph::Graph()
{

}

void Graph::addNode(string newName)
{
    GraphNode *newNode = new GraphNode(newName);
    nodes.push_back(newNode);
}

void Graph::addEdge(string sourceName, string destinationName, int weight)
{
    GraphNode *sourceNode = nullptr;
    GraphNode *destinationNode = nullptr;

    for(auto node : nodes)
    {
        if (sourceName == node->getValue())
        {
            sourceNode = node;
        } 
        if (destinationName == node->getValue())
        {
            destinationNode = node;
        } 
    }

    if (sourceNode != nullptr && destinationNode != nullptr)
    {
        sourceNode->addedge(destinationNode, weight);
        destinationNode->addedge(sourceNode, weight);
    }
    
}

int Graph::getSize()
{
    return nodes.size();
}

string Graph::shortestPath(string sourceName)
{

}

string Graph::minimumSpanningTree()
{

}

