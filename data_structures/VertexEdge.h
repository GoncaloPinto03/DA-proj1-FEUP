

#ifndef DA_TP_CLASSES_VERTEX_EDGE
#define DA_TP_CLASSES_VERTEX_EDGE

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "string"
#include "../Tests/Station.h"
#include "MutablePriorityQueue.h"

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

class Vertex {
public:
    Vertex();
    Vertex(Station station);
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue


    Station getStation() const;
    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    //Edge* addEdge(Vertex* dest, int weight, const std::string& service);
    unsigned int getIndegree() const;
    double getDist() const;
    Edge *getPath() const;
    std::vector<Edge *> getIncoming() const;
    bool isBlocked();
    double const getCapacity();

    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Edge *path);
    void setBlock();
    bool removeEdge(Station station);

    friend class MutablePriorityQueue<Vertex>;

    Edge *addEdge(Vertex *d, int w);

protected:
    Station station;
    /*
    std::string name;
    std::string district;
    std::string municipality;
    std::string township;
    std::string line;
     */
    std::vector<Edge *> adj;  // outgoing edges

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge *path = nullptr;

    std::vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

    bool blocked = false;

    double capacity = 0;
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge();
    Edge(Vertex *orig, Vertex *dest, int w);


    Vertex * getDest() const;
    double getWeight() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    Edge *getReverse() const;
    int getFlow() const;
    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setFlow(int flow);
protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    int flow; // for flow-related problems
};

#endif /* DA_TP_CLASSES_VERTEX_EDGE */