#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

const int MAX_N = 1000;  
int cost[MAX_N][MAX_N];
int A[MAX_N][MAX_N];

// Function to calculate the shortest path between all pairs of vertices
void AllPaths(int cost[MAX_N][MAX_N], int A[MAX_N][MAX_N], int n) {
    // Initialize A with the cost matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = cost[i][j];
        }
    }

    // Floyd-Warshall algorithm to compute shortest paths
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Only update if there is a valid path from i to k and k to j
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX) {
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of directed edges: ";
    cin >> m;

    // Initialize cost matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) 
                cost[i][j] = 0;  // Distance to self is 0
            else 
                cost[i][j] = INT_MAX;  // No edge between vertices is set to infinity
        }
    }

    // Input edges and their costs
    cout << "Enter each edge in the format: start_vertex end_vertex cost\n";
    cout << "(Note: vertices are numbered from 1 to " << n << ")\n";
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        // Ensure vertices are valid and adjust for 0-based indexing
        if (u > 0 && v > 0 && u <= n && v <= n) {
            cost[u - 1][v - 1] = c;  // Convert to 0-based indexing for array
        } else {
            cout << "Invalid vertex numbers!" << endl;
        }
    }

    // Call the AllPaths function to calculate shortest paths
    AllPaths(cost, A, n);

    // Output the matrix of shortest path costs
    cout << "The matrix of shortest path costs between every pair of vertices:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == INT_MAX)
                cout << "INF ";  // INF for unreachable paths
            else
                cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
