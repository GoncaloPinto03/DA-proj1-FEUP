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
bool Graph::addEdge(const std::string& source, const std::string& dest, int w) {
    auto v1 = findVertex(source);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}







bool Graph::addBidirectionalEdge(const std::string& source, const std::string& dest, int w) {
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


// funcs TP3 - ex7
void Graph::testAndVisit(std::queue< Vertex*> &q, Edge *e, Vertex *w, double residual) {
    if (! w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}
bool Graph::findAugmentingPath(Vertex *s, Vertex *t) {
    for(auto v : vertexSet) {
        v->setVisited(false);
    }
    s->setVisited(true);
    std::queue<Vertex *> q;
    q.push(s);
    while( ! q.empty() && ! t->isVisited()) {
        auto v = q.front();
        q.pop();
        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }
        for(auto e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
    return t->isVisited();
}
double Graph::findMinResidualAlongPath(Vertex *s, Vertex *t) {
    double f = INF;
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        }
        else {
            //f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
    return f;
}
void Graph::augmentFlowAlongPath(Vertex *s, Vertex *t, double f) {
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}
int Graph::edmondsKarp(std::string source, std::string target) {
    int result_final=0;
    Vertex* s = findVertex(source);
    Vertex* t = findVertex(target);
    if (s == nullptr || t == nullptr || s == t)
        throw std::logic_error("Invalid source and/or target vertex");

    // Reset the flows
    for (auto v : vertexSet) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }
    // Loop to find augmentation paths
    while( findAugmentingPath(s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
        result_final += f;
    }
    return result_final*2;
}

int Graph::getNumVertex() const{
    return this->vertexSet.size();
}


// our funcs
int Graph::edmondsKarp2(std::string source, std::string target) {
    // TODO
    for(auto v : vertexSet){
        for(auto e : v->getAdj()){
            e->setFlow(0);
        }
    }
    double total_flow = 0;
    while(bfskarp(source, target)){
        int mrc = INT32_MAX;
        std::string current_node_id = target;
        while(current_node_id != source){
            auto edge = findVertex(current_node_id)->getPath();
            int residual;
            if(edge->getDest()->getStation().get_name() == current_node_id){
                residual = edge->getWeight() - edge->getFlow();
                current_node_id = edge->getOrig()->getStation().get_name();
            }
            else{
                residual = edge->getFlow();
                current_node_id = edge->getDest() ->getStation().get_name();
            }
            if(residual < mrc) mrc = residual;
        }

        current_node_id = target;
        while(current_node_id != source){
            auto edge = findVertex(current_node_id)->getPath();
            if(edge->getDest()->getStation().get_name() == current_node_id){
                edge->setFlow(edge->getFlow() + mrc);
                current_node_id = edge->getOrig()->getStation().get_name();
            }
            else{
                edge->setFlow(edge->getFlow() - mrc);
                current_node_id = edge->getDest() ->getStation().get_name();
            }
        }
        total_flow += mrc;
    }
    return total_flow;
}
bool Graph::bfskarp(std::string source, std::string target) {
    std::queue<Vertex *> q;
    for (auto v: vertexSet) {
        v->setVisited(false);
        v->setPath(nullptr);
    }
    q.push(findVertex(source));
    q.front()->setVisited(true);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto e: v->getAdj()) {
            auto w = e->getDest();
            if (!w->isVisited() && e->getWeight() - e->getFlow() > 0) {
                w->setPath(e);
                w->setVisited(true);
                q.push(w);
                if (w->getStation().get_name() == target) return true;
            }
        }
        for (auto e: v->getIncoming()) {
            auto w = e->getOrig();
            if (!w->isVisited() && e->getFlow() != 0) {
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }
    }
    return false;
}