#pragma once

#include "graph_node.h"

class GraphNode;

struct edge
{
    GraphNode * source; // the node your coming from
    GraphNode * destination; // the node your going to
    int weight; // distance between the source and dest
};
