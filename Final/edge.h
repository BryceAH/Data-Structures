/*
edge.h
Name: Bryce Hillsman
Student id: x00505693
Date: 6/10/2024

    This is the header file for the edge struct that sets the values for the source, desination and weight
*/

#pragma once

#include "graph_node.h"

class GraphNode;

struct edge
{
    GraphNode * source; // the node your coming from
    GraphNode * destination; // the node your going to
    int weight; // distance between the source and dest
};
