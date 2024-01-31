#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
private:
    int numVertices; 
    list<int> *adjacencyList; 
public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjacencyList = new list<int>[numVertices]; 
    }

    void addEdge(int startVertex, int endVertex) {
        adjacencyList[startVertex].push_back(endVertex); 
    }

    void removeEdge(int startVertex, int endVertex) {
        adjacencyList[startVertex].remove(endVertex); 
    }

    void addVertex() {
        numVertices++; 
        list<int> *newAdjacencyList = new list<int>[numVertices]; 
        for (int i = 0; i < numVertices - 1; i++) {
            newAdjacencyList[i] = adjacencyList[i]; 
        }
        delete[] adjacencyList; 
        adjacencyList = newAdjacencyList; 
    }

    void removeVertex(int vertex) {
        for (int i = 0; i < numVertices; i++) {
            adjacencyList[i].remove(vertex); 
        }
        list<int> *newAdjacencyList = new list<int>[numVertices - 1]; 
        int k = 0;
        for (int i = 0; i < numVertices; i++) {
            if (i != vertex) {
                newAdjacencyList[k] = adjacencyList[i]; 
                k++;
            }
        }
        delete[] adjacencyList; 
        adjacencyList = newAdjacencyList; 
        numVertices--; 
    }

    void depthFirstSearchUtil(int vertex, bool visited[]) {
        visited[vertex] = true; 
        cout << vertex << " "; 

        for (auto i = adjacencyList[vertex].begin(); i != adjacencyList[vertex].end(); ++i) {
            if (!visited[*i]) {
                depthFirstSearchUtil(*i, visited); 
            }
        }
    }

    void depthFirstSearch(int startVertex) {
        bool *visited = new bool[numVertices]; 
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false; 
        }

        depthFirstSearchUtil(startVertex, visited); 
    }
};

int main() {
    Graph graph(4); 
    graph.addEdge(0, 1); 
    graph.addEdge(0, 2);
    graph.addEdge(1, 2); 
    graph.addEdge(2, 3); 

    cout << "Depth First Traversal starting from vertex 2: ";
    graph.depthFirstSearch(2); 
    cout << endl;

    graph.removeEdge(1, 2); 
    cout << "Graph after removing edge (1, 2):" << endl;
    graph.depthFirstSearch(0); 
    cout << endl;

    graph.addVertex(); 
    graph.addEdge(3, 4); 
    cout << "Graph after adding vertex 4 and edge (3, 4):" << endl;
    graph.depthFirstSearch(0); 
    cout << endl;

    graph.removeVertex(0); 
    cout << "Graph after removing vertex 0:" << endl;
    graph.depthFirstSearch(2);
    cout << endl;

    return 0;
}



    