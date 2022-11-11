#ifndef Graph_h
#define Graph_h

#include "Vertex.h"


template<class T>
class Graph {
private:
    vector< vector< Vertex<T> > > graph;
    vector<T> vertices;
    int size;
    int findVertex(T vertex);
public:
    Graph();
    Graph(vector<T> vertices);
    Graph(vector<T> vertices, vector< Vertex<T> > edges);
    void addEdges(vector< Vertex<T> > edges);
    void addEdge(Vertex<T> edge);
    void addVertex(T vertex); 
    void BFS(T vertex); 
    void print();
};

template<class T>
Graph<T>::Graph() {
    size = 0;
}


template<class T>
Graph<T>::Graph(vector<T> vertices) {
    this->vertices = vertices;
    size = vertices.size();
    graph.resize(size);
}

template<class T>
int Graph <T>::findVertex(T vertex) {
    typename vector<int>::iterator it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }     
}

template<class T>
Graph<T>::Graph(vector<T> vertices, vector< Vertex<T> > edges) {
    this->vertices = vertices;
    size = vertices.size();
    graph.resize(size);
    for (auto edge : edges) {
        int sourceIndex = findVertex(edge.source);
        if (sourceIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        graph[sourceIndex].push_back(edge);
    }
}

template<class T>
void Graph<T>::BFS(T vertex) {
    vector<bool> status(size, false);
    queue<int> adjQueue;
    int index =
        while(!adjQueue.empty())
            adjQueue.front
            cout << vertices[index] << " ";
}

template<class T>
void Graph<T>::print() {
    for (int i=0; i<size; i++) {
        cout << vertices[i] << " ";
        for (auto vertex : graph[i]) {
            cout << vertex.target << "," << vertex.weight << " ";
        }
        cout << endl;
    }
}

#endif