// Graph_node.h

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

        int getDistance();

        void setDistance(int input);

        void setPrevious(GraphNode *input);

        GraphNode *getPrevious();
        

    private:
        int distance;

        GraphNode *prev;

        string value;

        vector<edge *> neighbors;
    };

    
