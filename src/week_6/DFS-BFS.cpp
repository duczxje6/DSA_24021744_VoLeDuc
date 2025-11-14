#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1000;
int n; // Số đỉnh
bool adj[MaxN][MaxN]; 

void add_edge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; 
}

void DFS(int u, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) {
            DFS(v, visited);
        }
    }
}

void BFS(int start) {
    vector<bool> visited(n, false);
    vector<int> queue;
    visited[start] = true;
    queue.push_back(start);
    int front = 0;

    while (front < queue.size()) {
        int u = queue[front++];
        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                queue.push_back(v);
            }
        }
    }
}
