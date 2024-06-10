/*
Graph.cpp
Name: Bryce Hillsman
Student id: x00505693
Date: 6/10/2024

    This is the file with most of the code, it contains the addNode() function that adds the vertices / nodes to the graph.
The connectNodes() connects the nodes together with a weight. shortestPath() which finds the shortest distance from a chosen node to every other node. 
minimumSpanningTree() which is used to find the shortest distance to touch every node. printPath() which is used to display the path on the screen. 
display() which I used to display the names of the nodes that had been added, Tests() which is a function to test various parts of my program. and lastly 
printSlash() which just prints 50 slashes to break up the graphs in the display.
*/

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
for (auto node : nodes){ //O(V)
    unvisitedNodes.push_back(node);
}

GraphNode *sourceNode = nullptr;

for (auto i:nodes) // sets all values to inf //O(V)
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
while(unvisitedNodes.size() != 0) // loop that runs until there is no more unvisited nodes //O(V)
{


for (auto edge : currentNode->getNeighbor()) //O(V^2) becuase it is a for loop in the while loop
{

    GraphNode *TempDest = edge->destination;
    if (edge->source->getDistance() + edge->weight < edge->destination->getDistance()) // determinds distance from source is less than current distacnce
    {
        TempDest->setDistance(currentNode->getDistance() + edge->weight);
        TempDest->setPrevious(currentNode);
    }
}

        int index = 0;
        for (auto node:unvisitedNodes) //erases nodes //O(V^2)
        {
            if(node == currentNode)
            {
             unvisitedNodes.erase(unvisitedNodes.begin() + index);
            }
            index += 1;
        }
        
    GraphNode *lowestNode = new GraphNode("lowestNode");

    for (auto node:unvisitedNodes) // loops through list of unvisited nodes to find node with smallest distance //O(V^2)
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

    for (auto i:unvisited) //O(V)
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
        
    visited.push_back(sourceNode);
    int index = 0;
    for (auto node:unvisited) //erases nodes //O(V)
    {
        if(node == sourceNode)
        {
            unvisited.erase(unvisited.begin() + index);
        }
        index += 1;
    }

    
    while(visited.size() < nodes.size()){ //O(V)
        int smallest = numeric_limits<int>::max();
        edge *smallestEdge = nullptr;


        for(auto node : visited) //O(E^2)
        {
            for (auto edge : node->getNeighbor()) // find shortest edge->weight
            {

                if (find(visited.begin(), visited.end(), edge->destination) == visited.end() && edge->weight < smallest) // checks if the destination node is not present in the visted vector and it also checks if edge weight is less than the current smallest weight 
                {
                    smallestEdge = edge; // finds the smallest edge weight in the neighbors
                    smallest = edge->weight;
                }
            }
        }    

        if (smallestEdge == nullptr)
        {
            cout<<"no connecting edges" <<endl;
            break;
        }
        
        visited.push_back(smallestEdge->destination);
        int index = 0;
        for (auto node:unvisited) //erases nodes //O(E)
        {
            if(node == smallestEdge->destination)
            {
             unvisited.erase(unvisited.begin() + index);
            }
            index += 1;
        }
        m.addNode(smallestEdge->source->getValue());
        m.addNode(smallestEdge->destination->getValue());

        m.connectNodes(smallestEdge->source->getValue(),smallestEdge->destination->getValue(),smallestEdge->weight);
        

        shortestEdges.push_back(smallestEdge);
    }

        cout << "Minimum Spanning Tree:" << endl;
        for (auto edge : shortestEdges) //O(E)
        {
            cout << edge->source->getValue() << " -> " << edge->destination->getValue() << " Weight: " << edge->weight << endl;
        }
        cout << endl;
}

void Graph::printSlash()
{
for(int i = 0; i<50; ++i)
    {
        cout << "/";
    }
cout << endl;
}

void Graph::Tests()
{
    Graph t;

    cout << "addNode test, Adding A and B\n" << endl;
    t.addNode("A");
    t.addNode("B");
    if (t.getSize() == 2)
    {
        cout << "Successfully added 2 nodes\n" << endl;
        cout << "Testing display\n" << endl;
        t.display();
    } else
    {
        cout << "Failed at adding 2 nodes\n" << endl;
    }

    cout << "connectNodes test, Connecting A and B\n" << endl;
    t.connectNodes("A", "B", 5);
    
    vector<GraphNode *> neighborVector;
    for (auto node : t.nodes) 
    {
        if (node->getValue() == "A")
        {
            for(auto i : node->getNeighbor())
            {
                neighborVector.push_back(i->destination);
            }
            break;
        }
        
    }

    if (neighborVector.empty() == false)
    {
        cout << "connectNodes Passed\n" << endl;
    } else 
    {
        cout << "connectNodes Failed\n" << endl;

    }

    cout << "Testing getSize with 2 nodes\n" << endl;
    if (t.getSize() == 2)
    {
        cout<<"getSize Passed\n" << endl;
    } else
    {
        cout << "getSize Falied\n" << endl;
    }
    

}
