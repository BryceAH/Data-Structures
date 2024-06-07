//graph_node.h

#pragma once


#include <string>
#include <vector>
#include "edge.h"


using namespace std;
using std::vector;

struct edge;

class GraphNode
    {

    public:
        GraphNode(string newName);
        ~GraphNode();


        void addedge(GraphNode *destination, int weight);

        string getValue();

        vector<edge *> getNeighbor();
        

    private:

        string value;

        vector<edge *> neighbors;
    };

    
