#include "Graph.h"
#include <limits>
#include <queue>
#include <algorithm>
#include <iostream>

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
/*
Vertex * Graph::findVertex(const std::string &name) const {
    for (auto v : vertexSet)
        if (v->getName() == name)
            return v;
    return nullptr;
}*/
Vertex* Graph::findVertex(const std::string& name)const {
    // Percorra todos os vértices do grafo
    for (auto v : vertexSet) {
        // Se o nome do vértice atual for igual ao nome da estação procurada, retorne-o
        if (v->getStation().get_name() == name) {
            return v;
        }
    }
    // Se a estação não for encontrada, retorne nullptr
    return nullptr;
}


bool Graph::removeVertex(const std::string &name) {
    Vertex* v = findVertex(name);
    if (v == nullptr) {
        return false;
    }

    for (auto e : v->getAdj()) {
        auto w = e->getDest();
        w->removeEdge(v->getStation());
        v->removeEdge(w->getStation());
    }

    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++) {
        if ((*it)->getStation().get_name() == name){
            vertexSet.erase(it);
            break;
        }
    }
    delete v;
    return true;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const std::string &name) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getStation().get_name() ==name)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(Station station) {
    if (findVertex(station.get_name()) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(station));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const std::string& source, const std::string& dest, double w) {
    auto v1 = findVertex(source);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}



bool Graph::addBidirectionalEdge(const std::string& source, const std::string& dest, double w) {
    auto v1 = findVertex(source);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}


void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}


Graph::Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}


    int Graph::edKarp(const std::string& source, const std::string& dest) const {
        auto s = findVertex(source);
        auto t = findVertex(dest);

        // Check if source and destination are valid
        if (s == nullptr || t == nullptr || s == t) {
            return -1;
        }

        // Reset the flow in the edges
        for (auto v: vertexSet) {
            for (auto e: v->getAdj()) {
                e->setFlow(0);
            }
        }

        double maxflow = 0;
        while (find_augmentigPath(s, t)) {
            int pathFlow = std::numeric_limits<int>::max();

            // Find the minimum flow in the path
            for (auto v = t; v != s;) {
                auto e = v->getPath();
                if (e->getDest() == v) {
                    if (pathFlow < e->getWeight() - e->getFlow()) pathFlow = pathFlow;
                    else pathFlow = e->getWeight() - e->getFlow();
                    v = e->getOrig();
                } else {
                    if (pathFlow < e->getFlow()) pathFlow = pathFlow;
                    else pathFlow = e->getFlow();
                    v = e->getDest();
                }
            }

            // Update the flow in the path
            for (auto v = t; v != s;) {
                auto e = v->getPath();
                if (e->getDest() == v) {
                    e->setFlow(e->getFlow() + pathFlow);
                    v = e->getOrig();
                } else {
                    e->setFlow(e->getFlow() - pathFlow);
                    v = e->getDest();
                }
            }

            maxflow += pathFlow;
        }
        return maxflow;

    }


bool Graph::find_augmentigPath(Vertex *source, Vertex *dest) const{

    for (auto v: vertexSet) {
        v->setVisited(false);
    }

    source->setVisited(true);
    std::queue<Vertex *> q;
    q.push(source);

    while (!q.empty() && !dest->isVisited()) {
        auto v = q.front(); q.pop();

        for (auto e: v->getAdj()) {
            auto w = e->getDest();
            if (!w->isVisited() && e->getWeight() - e->getFlow() > 0) {
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }

        for (auto e: v->getIncoming()) {
            auto w = e->getOrig();
            if (!w->isVisited() && e->getFlow() > 0) {
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }
    }

    return dest->isVisited();
}

int Graph::getNumVertex() const{
    return this->vertexSet.size();
}

