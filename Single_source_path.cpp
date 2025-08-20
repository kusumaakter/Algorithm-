#include<bits/stdc++.h>
using namespace std;

void printPath(int vertex, int parent[]) {
    if (vertex == -1)
        return;
    printPath(parent[vertex], parent);  // Recursively print the path
    cout << vertex << " ";
}
void shortestPath(int v, int cost[100][100], int dist[], int parent[], int n) {
    bool S[100];  // Set of vertices shortest path is found

    // Step 1: Initialize distances and the set S
    for (int i = 1; i <= n; i++) {
        S[i] = false;  // No vertex set initially
        dist[i] = cost[v][i];  // Initialize distances with cost from source vertex
        if (dist[i] != INT_MAX && i != v) {
            parent[i] = v;  // Initialize the parent of each vertex to the source
        } else {
            parent[i] = -1;
        }
    }
    S[v] = true;  // Include source vertex in the set
    dist[v] = 0;  // Distance from source to itself is 0
    parent[v] = -1;  // No parent for the source

    //Find shortest paths for the remaining vertices
    for (int num = 2; num <= n; num++) {
        // Find the vertex u not in S with the minimum distance
        int u = -1;
        int minDist = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (!S[i] && dist[i] < minDist) {
                u = i;
                minDist = dist[i];
            }
        }

        if (u == -1) break;  // If there's no reachable vertex, break the loop
        S[u] = true;

        //Update distances for vertices adjacent to u
        for (int w = 1; w <= n; w++) {
            if (!S[w] && cost[u][w] != INT_MAX && dist[w] > dist[u] + cost[u][w]) {
                dist[w] = dist[u] + cost[u][w];
                parent[w] = u;
            }
        }
    }
}
int main() {
    int n, v, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int cost[100][100], dist[100], parent[100];
    //Initialize the cost matrix with infinity (no direct edges)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INT_MAX;
        }
    }
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter the edges with their weights (format: u v w):" << endl;
    for (int i = 0; i < e; i++) {
        int u, w, weight;
        cin >> u >> w >> weight;
        cost[u][w] = weight;
    }
    cout << "Enter the source vertex: ";
    cin >> v;
    shortestPath(v, cost, dist, parent, n);
    // Print the shortest distances and paths
    cout << "Vertex\tDistance\tPath" << endl;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << "\tINF\t\tNo path" << endl;
        } else {
            cout << i << "\t" << dist[i] << "\t\t";
            printPath(i, parent);  // Print the path
            cout << endl;
        }
    }
    return 0;
}