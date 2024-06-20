#include <iostream>

using namespace std;

const int MAXN = 100; // Maximum number of vertices

// Custom queue implementation using an array
struct Queue {
    int data[MAXN];
    int front;
    int back;

    Queue() : front(0), back(0) {}

    bool empty() {
        return front == back;
    }

    void push(int x) {
        data[back++] = x;
    }

    int pop() {
        return data[front++];
    }

    int peek() {
        return data[front];
    }
};

// Function to perform topological sorting
void topologicalSort(int n, int m, int graph[][MAXN], int indegree[]) {
    // Step 1: Initialize a queue with vertices having indegree zero
    Queue q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 2: Process vertices until the queue is empty
    while (!q.empty()) {
        int u = q.pop();
        cout << u << " "; // Print the vertex (or store in result)

        // Step 3: Decrease the indegree of neighboring vertices
        for (int v = 0; v < n; ++v) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v); // Step 4: If the indegree becomes zero, add it to the queue
                }
            }
        }
    }
}

int main() {
    int n, m; // n: number of vertices, m: number of edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    int graph[MAXN][MAXN] = {0}; // Adjacency matrix representation of graph
    int indegree[MAXN] = {0};     // Array to store indegree of each vertex

    cout << "Enter the edges (from vertex u to vertex v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        indegree[v]++;
    }

    // Perform topological sorting
    cout << "Topological order: ";
    topologicalSort(n, m, graph, indegree);

    return 0;
}

/*
Enter the number of vertices and edges: 6 8
Enter the edges (from vertex u to vertex v):
0 1
1 2
0 3
3 1
3 4
2 4
4 5
2 5
Topological order: 0 3 1 2 4 5
*/