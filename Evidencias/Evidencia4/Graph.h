#ifndef Graph_h
#define Graph_h

#include <queue>
#include <stack>
#include "Vertex.h"
#include "HashPuerto.h"

using namespace std;

template<class T>
class Graph {
private:
    vector< vector< Vertex<T> > > graph;
    vector<T> vertices;
    int size;
    int findVertex(T vertex);
    void DFSR(int vertexIndex, vector<bool> &status);
    int getSmallIndex(vector<bool> status, vector<int> cost);
public:
    Graph();
    Graph(vector<T> vertices);
    Graph(Hash vertices, vector< Vertex<T> > edges);
    void addEdges(vector< Vertex<T> > edges);
    void addEdge(Vertex<T> edge);
    void addVertex(T vertex); 
    void BFS(T vertex); 
    void DFS(T vertex); 
    void print();
    void Dijkstra(T origen, T destino);
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
    typename vector<string>::iterator it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }     
}

template<class T>
Graph<T>::Graph(Hash vert, vector< Vertex<T> > edges) {
    for(int i=0;i<99;i++){
        if(vert.findIndex(i) != ""){
            this->vertices.push_back(vert.findIndex(i));
        }
    }
    
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
    int index = findVertex(vertex);
    if (index >= 0) {
        adjQueue.push(index);
        status[index] = true;
        while (!adjQueue.empty()) {
            index = adjQueue.front();
            cout << vertices[index] << " ";
            for (auto adjVertex : graph[index]) {
                int adjIndex = findVertex(adjVertex.target);
                if (!status[adjIndex]) {
                    adjQueue.push(adjIndex);
                    status[adjIndex] = true;
                }
            }
            adjQueue.pop();
        }
        cout << endl;
    }


}

template<class T>
void Graph<T>::DFSR(int vertexIndex, vector<bool> &status) {
    cout << vertices[vertexIndex] << " ";
    status[vertexIndex] = true;
    for (auto vertexAdj : graph[vertexIndex]) {
        int index = findVertex(vertexAdj.target);
        if (!status[index]) {
            DFSR(index, status);
        }
    }
}

template<class T>
void Graph<T>::DFS(T vertex) {
    int index = findVertex(vertex);
    if (index >= 0) {
        vector<bool> status(size, false);
        DFSR(index, status);
        cout << endl;
    }
}

template<class T>
int Graph<T>::getSmallIndex(vector<bool> status, vector<int> cost) {
    int minCost = INT_MAX;
    int minIndex = -1;
    for (int i=0; i<size; i++) {
        if (!status[i]) {
            if (cost[i] < minCost) {
                minCost = cost[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
}

template<class T>
void Graph<T>::Dijkstra(T origen, T destino) {
    int origenIndex = findVertex(origen);
    int destinoIndex = findVertex(destino);
    if (origenIndex >= 0 && destinoIndex >= 0) {

        vector<bool> status(size, false); 
        vector<int> cost(size, INT_MAX); 
        cost[origenIndex] = 0;
        vector<int> path(size, -1); 
        int smallIndex = getSmallIndex(status, cost);
        while (smallIndex >= 0) {
            status[smallIndex] = true;
            for (auto adjVertex : graph[smallIndex]) {
                int adjIndex = findVertex(adjVertex.target);
                if (!status[adjIndex]) {
                    if (cost[adjIndex] > cost[smallIndex] + adjVertex.weight) {
                        cost[adjIndex] = cost[smallIndex] + adjVertex.weight;
                        path[adjIndex] = smallIndex;
                    }
                }
            }
            smallIndex = getSmallIndex(status, cost);
        }


        vector < stack<string> > pathStack(size);
        for (int index = 0; index < size; index++) {
            if (cost[index] < INT_MAX) {

                int pathIndex = index;
                while (path[pathIndex] != -1) {
                    pathStack[index].push(vertices[pathIndex]);
                    pathIndex = path[pathIndex];
                }
            }
        }
        if(cost[destinoIndex] != INT_MAX){

            cout<<"La ruta mas optima entre el puerto origen y el destino es."<<endl;
            cout << vertices[origenIndex] << " ";
            while (!pathStack[destinoIndex].empty()) {
                cout << pathStack[destinoIndex].top() << " ";
                pathStack[destinoIndex].pop();
            }
            cout<<endl<<"Millas Nauticas: "<<cost[destinoIndex]<<endl<<endl;
        }
        else{
            cout<<"No se puede llegar al destino"<<endl<<endl;
        }
        

        int costomayor = 0;
        int imayor;
        for(int i=0;i<=cost.size()-1;i++){
            if(cost[i] > costomayor && cost[i] != INT_MAX){
                costomayor = cost[i];
                imayor = i;
            }
        }


        cout<<"La ruta mas larga entre el puerto origen y los puertos que se encuentran en el grafo es."<<endl;
        cout << vertices[origenIndex] << " ";
        while (!pathStack[imayor].empty()) {
            cout << pathStack[imayor].top() << " ";
            pathStack[imayor].pop();
        }
        cout<<endl<<"Millas Nauticas "<<cost[imayor]<<endl<<endl;

        bool puertosin = false;
        cout<<"Puertos a los que no se puede llegar."<<endl;
        for(int i=0;i<=cost.size()-1;i++){
            if(cost[i] == INT_MAX){
                cout<<vertices[i]<< " ";
                puertosin = true;
            }
        }
        if(puertosin == false){
            cout<<"Este puerto puede llegar a todos los puertos"<<endl;
        }

    } else {

        cout << "Uno de los vertices no existe" << endl;
    }
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