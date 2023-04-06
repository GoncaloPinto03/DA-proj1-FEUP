#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "MutablePriorityQueue.h"

#include "VertexEdge.h"
using namespace std;

class Graph {
public:

    Graph();
    // Graph(int nrVertex);
    /*
    * Auxiliary function to find a vertex with a given ID.
    */

    /**
     * @brief Find a vertex in the graph with the given id, if it does not exists return nullptr
     *
     * @param id Vertex id
     * @return Vertex* vertex
     */
    Vertex *findVertex(const int &id) const;


    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */

    /**
 * @brief Add a vertex to the graph
 *
 * @param id Vertex id
 * @return true Vertex was added
 * @return false Vertex with that id already exists
 */
    bool addVertex(const int &id, string name ,string district, string municipality, string township, string line);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */


    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);

    bool addEdge(const int &sourc, const int &dest, double w);

    int getNumVertex() const;
    std::vector<Vertex *> getVertexSet() const;
protected:

    /**
     * @brief Vector of graph vertexes
     */
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;

    int edKarp(int source, int target) const;


    /**
     * @brief Remove a vertex from the graph
     *
     * @param id Name of the station to remove
     * @return true Vertex was removed
     * @return false Vertex was not found
     */
    bool removeVertex(const int &id);

    bool find_augmentigPath(Vertex *sourc, Vertex *dest) const;
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */