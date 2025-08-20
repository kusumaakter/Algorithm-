#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 1000;  
int cost[MAX_N][MAX_N];
int A[MAX_N][MAX_N];

void AllPaths(int cost[MAX_N][MAX_N], int A[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = cost[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
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

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) 
                cost[i][j] = 0; 
            else 
                cost[i][j] = INT_MAX; 
        }
    }

    cout << "Enter each edge in the format: start_vertex end_vertex cost\n";
    cout << "(Note: vertices are numbered from 1 to " << n << ")\n";
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        cost[u - 1][v - 1] = c; 
    }

    AllPaths(cost, A, n);

    cout << "The matrix of shortest path costs between every pair of vertices:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
