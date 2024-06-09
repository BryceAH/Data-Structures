// Graph.cpp

#pragma once

#include "Graph.hpp"
#include <iostream>
#include <algorithm>
#include <limits>


using namespace std;


Graph::Graph()
{

}
Graph::~Graph()
{

}

void Graph::addNode(string newName)
{
    GraphNode *newNode = new GraphNode(newName);
    nodes.push_back(newNode);
}

void Graph::connectNodes(string sourceName, string destinationName, int weight)
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

void Graph::display(){
    for (auto node : nodes)
    {
        cout << node->getValue(); 
        cout << endl;
    }
    cout << endl;
}

string Graph::shortestPath(string sourceName) //dijkstra's algorithm
{
vector<GraphNode *> unvisitedNodes;
for (auto node : nodes){
    unvisitedNodes.push_back(node);
}

GraphNode *sourceNode = nullptr;

for (auto i:nodes) // sets all values to inf
{
    if (sourceName == i->getValue()) // finds node with source name
    {
        sourceNode = i;
    }
    i->setDistance(numeric_limits<int>::max());
    i->setPrevious(nullptr);
    
}

sourceNode->setDistance(0); // sets source to 0



GraphNode *currentNode = sourceNode;
while(unvisitedNodes.size() != 0) // loop that runs until there is no more unvisited nodes
{


for (auto edge : currentNode->getNeighbor())
{

    GraphNode *TempDest = edge->destination;
    if (edge->source->getDistance() + edge->weight < edge->destination->getDistance()) // determinds distance from source is less than current distacnce
    {
        TempDest->setDistance(currentNode->getDistance() + edge->weight);
        TempDest->setPrevious(currentNode);
    }
}

        int index = 0;
        for (auto node:unvisitedNodes) //erases nodes
        {
            if(node == currentNode)
            {
             unvisitedNodes.erase(unvisitedNodes.begin() + index);
            }
            index += 1;
        }
        
    GraphNode *lowestNode = new GraphNode("lowestNode");

    for (auto node:unvisitedNodes) // loops through list of unvisited nodes to find node with smallest distance
    {
        if(node->getDistance() < lowestNode->getDistance())
        {
            lowestNode = node;
        }
    }

    currentNode = lowestNode;
}

    cout << "Distances and paths from " << sourceName << ":\n";
    for (auto node : nodes)
    {
        cout << node->getValue() << ": " << node->getDistance() << ", Path: "; // prints the value of the node and its distance from the source
        printPath(node); // calls printpath function to print the path from source to this node
        cout << endl;
    }

cout<<"\n";
return "";
}

void Graph::printPath(GraphNode* node) // used to print the shortest paths
{
    if (node->getPrevious() != nullptr) // checks if get previous is null pointer to get to the source node
    {
        printPath(node->getPrevious()); // if get previous is not null pointer is recursivly calls the print path until it is
        cout << " -> ";
    }
    cout << node->getValue(); // prints the value of the current node
}


void Graph::minimumSpanningTree(string sourceName) //Prim's algorithm
{
    Graph m;

    GraphNode *sourceNode = nullptr;

    vector<GraphNode *> visited;
    vector<GraphNode *> unvisited = nodes;
    vector<edge *> shortestEdges;

    for (auto i:unvisited)
    {
        if (sourceName == i->getValue()) // finds node with source name
        {
            sourceNode = i;
            break;
        }
    }

        if (sourceNode == nullptr)
        {
            cout << "Souce node not found" << endl;
            return;
        }
        
        GraphNode *currentNode = sourceNode;

    
    while(visited.size() < unvisited.size()){ 
        int smallest = numeric_limits<int>::max();
        edge *smallestEdge = nullptr;


        for (auto edge : currentNode->getNeighbor()) // find shortest edge->weight
        {

            if (find(visited.begin(), visited.end(), edge->destination) == visited.end() && edge->weight < smallest) // checks if the destination node is not present in the visted vector and it also checks if edge weight is less than the current smallest weight 
            {
                smallestEdge = edge; // finds the smallest edge weight in the neighbors
                smallest = edge->weight;
                shortestEdges.push_back(edge);
            }
        }

        if (smallestEdge == nullptr)
        {
            cout<<"no connecting edges" <<endl;
            break;
        }
        
        visited.push_back(currentNode);
        int index = 0;
        for (auto node:unvisited) //erases nodes
        {
            if(node == currentNode)
            {
             unvisited.erase(unvisited.begin() + index);
            }
            index += 1;
        }
        m.addNode(smallestEdge->source->getValue());
        m.addNode(smallestEdge->destination->getValue());

        m.connectNodes(smallestEdge->source->getValue(),smallestEdge->destination->getValue(),smallestEdge->weight);
        

        currentNode = smallestEdge->destination;
    }

        cout << "Minimum Spanning Tree:" << endl;
        for (auto edge : shortestEdges)
        {
            cout << edge->source->getValue() << " -> " << edge->destination->getValue() << " Weight: " << edge->weight << endl;
        }
        cout << endl;
}
