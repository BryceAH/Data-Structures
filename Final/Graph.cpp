//Graph.cpp

#pragma once

#include "Graph.hpp"
#include <iostream>
#include <algorithm>
#include <limits>


using namespace std;

//https://moodle.linnbenton.edu/mod/page/view.php?id=1552132&inpopup=1

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

// for (auto node:unvisitedNodes) //prints table and all values
// {
//     cout << node->getValue()<< ": " << node->getDistance() << endl;

// }

// cout << "unvisitedNodes.size(): "<< unvisitedNodes.size()<<endl;
// for (auto node:unvisitedNodes) //prints table and all values
// {
// cout << node->getValue()<< ": " << node->getDistance() << endl;

// }
// for (auto node:unvisitedNodes) //prints table and all values
// {
//     cout << node->getValue()<< ": " << node->getDistance() << endl;

// }
//     for (auto node:unvisitedNodes) //prints table and all values
// {
//     cout << node->getValue()<< ": " << node->getDistance() << endl;

// }

string Graph::shortestPath(string sourceName)
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
while(unvisitedNodes.size() != 0) // does most of the graphing
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
        



        
    GraphNode *lowestNode = new GraphNode("lowestNode"); //borrowed
    for (auto node:unvisitedNodes) // loops through list of unvisited nodes to find node with smallest distance
    {
        if(node->getDistance() < lowestNode->getDistance())
        {
            lowestNode = node;
        }
    }

    // cout << "currentNode->getValue(): " << currentNode->getValue() << " currentNode->getDistance(): " << currentNode->getDistance() << endl<<endl;


    
    currentNode = lowestNode;
}

for (auto node:nodes) //prints table and all values
{
cout << node->getValue()<< ": " << node->getDistance() << endl;

}
cout<<"\n";
return "";
}



// //////////////////////////////
// int index = 0;
// string deleteNode = "B";
// for (auto node:unvisitedNodes) //earases nodes
// {

//     if(node->getValue() == deleteNode)
//     {
//         unvisitedNodes.erase(unvisitedNodes.begin() + index);
//     }else
//     {
//         index += 1;
//     }
//     // cout << node->getValue() << endl;
// }
// /////////////////////////////////





void Graph::minimumSpanningTree(string sourceName) //Prim's algorithm
{
    Graph m;

    GraphNode *sourceNode = nullptr;
    GraphNode *currentNode = nullptr;

    vector<GraphNode *> visited;
    vector<GraphNode *> unvisited;

    for (auto node : nodes)
    {
    unvisited.push_back(node);
    }


    for (auto i:unvisited)
    {
        if (sourceName == i->getValue()) // finds node with source name
        {
            sourceNode = i;
            cout << "sourceNode->getValue(): "<< sourceNode->getValue() << endl;
            break;
        }
    }

        if (sourceNode == nullptr)
        {
            cout << "Souce node not found" << endl;
            return;
        }
        
        currentNode = sourceNode;

    
    int smallest = numeric_limits<int>::max();
    edge *smallestEdge;
    while(visited.size() < unvisited.size()){
        for (auto edge : currentNode->getNeighbor()) // find shortest edge->weight
        {
            // cout<<"edge->destination->getValue: " << edge->destination->getValue() << " edge->weight: "<<edge->weight <<endl;
            if (edge->weight < smallest)
            {
                smallestEdge = edge; // finds the smallest edge weight in the neighbors
            }
        }

        if (smallestEdge == nullptr)
        {
            cout<<"no connecting edges" <<endl;
            break;
        }
        
        visited.push_back(currentNode);
        m.addNode(smallestEdge->source->getValue());
        m.addNode(smallestEdge->destination->getValue());

        m.connectNodes(smallestEdge->source->getValue(),smallestEdge->destination->getValue(),smallestEdge->weight);


        int index = 0;
        for (auto node:unvisited) //erases nodes
        {
            if(node == currentNode)
            {
                visited.push_back(node);
                unvisited.erase(unvisited.begin() + index);
            }
            index += 1;
        }
    currentNode = unvisited.front();

    // here

    // for (auto node:m.nodes) //prints table and all values
    // {
    //     cout << node->getValue()<< ": " << node->getDistance() << endl;

    // }
}
}

