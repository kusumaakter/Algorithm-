#include <iostream>
using namespace std;

#define MAX 100  // Maximum number of vertices

int G[MAX][MAX];  // Graph adjacency matrix
int x[MAX];       // Array to store colors assigned to each vertex
int n, m; 
int Total_Solution =0;        // n = number of vertices, m = number of colors

// Function to check if the current color assignment is safe for vertex k
bool isSafe(int k, int color) {
    for (int j = 0; j < n; j++) {
        // If there is an edge between vertex k and j and they have the same color
        if (G[k][j] && x[j] == color) {
            return false;
        }
    }
    return true;
}

// Function to assign the next color to vertex k
void next_value(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1);  // Assign the next color

        if (x[k] == 0) return;  // If all colors are used, backtrack

    } while (!isSafe(k, x[k]));  // Repeat until a valid color is found
}

// Backtracking function to perform m-coloring
void mcoloring(int k) {
    while (true) {
        next_value(k);  // Assign a color to vertex k
        if (x[k] == 0) return;  // No color possible, backtrack

        if (k == n - 1) {
            Total_Solution ++;
            // If all vertices are colored, print the solution
            for (int i = 0; i < n; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        } else {
            mcoloring(k + 1);  // Recur to color the next vertex
        }
    }
}

int main() {
    // Input number of vertices and number of colors
    cout << "Enter number of vertices (n): ";
    cin >> n;
    cout << "Enter number of colors (m): ";
    cin >> m;

    // Input the graph as an adjacency matrix
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    // Initialize the color array
    for (int i = 0; i < n; i++) {
        x[i] = 0;  // Initially, no vertex is colored
    }

    // Start m-coloring from the first vertex
    mcoloring(0);
    cout<<"Total number of solution :"<<Total_Solution<<endl;

    return 0;
}
