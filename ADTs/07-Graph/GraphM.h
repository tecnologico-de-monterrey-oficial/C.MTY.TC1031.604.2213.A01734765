#ifndef GraphM_h
#define GraphM_h

#include "Vertex.h"

template<class T>
class GraphM{
    private:
        vector< vector<int> > graph;
        vector<T> vertices;
        int size; 
        int findVertex(T vertex);
    public:
        GraphM();
        GraphM(vector<T> vertices);
        GraphM(vector<T> vertices, vector< Vertex<T> > edges);
        void addEdges(vector< Vertex<T> > edges);
        void addEdge(Vertex<T> edge);
        void addVertex(T vertex); 
        void print();
};

template<class T>
GraphM<T>::GraphM() {
    size = 0;
}

template<class T>
GraphM<T>::GraphM(vector<T> vertices) {
    this->vertices = vertices;
    size = vertices.size();
    vector<int> row(size, 0);
    graph.resize(size, row);
}

template<class T>
int GraphM<T>::findVertex(T vertex) {
    typename vector<int>::iterator it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }     
}

template<class T>
GraphM<T>::GraphM(vector<T> vertices, vector< Vertex<T> > edges) {
    this->vertices = vertices;
    size = vertices.size();
    vector<int> row(size, 0);
    graph.resize(size, row);
    for (auto vertex : edges) {
        int sourceIndex = findVertex(vertex.source);
        if (sourceIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        int targetIndex = findVertex(vertex.target);
        if (targetIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        graph[sourceIndex][targetIndex] = vertex.weight;
    }
}


template<class T>
void GraphM<T>::print() {
    for (int i=0; i<vertices.size(); i++ ) {
        cout << vertices[i] << " ";
        for (int j=0; j<vertices.size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
void GraphM<T>::addEdges(vector< Vertex<T> > edges) {
    for (auto vertex : edges) {
        int sourceIndex = findVertex(vertex.source);
        if (sourceIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        int targetIndex = findVertex(vertex.target);
        if (targetIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        graph[sourceIndex][targetIndex] = vertex.weight;
    }
}

template<class T>
void GraphM<T>::addEdge(Vertex<T> edge) {
    int sourceIndex = findVertex(vertex.source);
    if (sourceIndex == -1) {
        throw out_of_range("El vértice no se encuentra en el grafo");
        return;
    }
    int targetIndex = findVertex(vertex.target);
    if (targetIndex == -1) {
        throw out_of_range("El vértice no se encuentra en el grafo");
        return;
    }
    graph[sourceIndex][targetIndex] = vertex.weight;
}

#endif