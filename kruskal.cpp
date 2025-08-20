#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;  
int parent[MAX];      
int t[MAX][3];        

int Find(int u) {
    if (parent[u] == -1)
        return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    int parentU = Find(u);
    int parentV = Find(v);
    if (parentU != parentV) {
        parent[parentU] = parentV;
    }
}

void Heapify(int E[][2], int cost[][MAX], int m, int i) {
    int smallest = i;      
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < m && cost[E[left][0]][E[left][1]] < cost[E[smallest][0]][E[smallest][1]]) {
        smallest = left;
    }
    if (right < m && cost[E[right][0]][E[right][1]] < cost[E[smallest][0]][E[smallest][1]]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(E[i], E[smallest]);  
        Heapify(E, cost, m, smallest);
    }
}

void Adjust(int E[][2], int cost[][MAX], int& m) {
    if (m == 0) return;
    swap(E[0], E[m - 1]);  
    m--;  
    Heapify(E, cost, m, 0);  
}

int Kruskal(int E[][2], int cost[][MAX], int n, int m, int t[][3]) {
    for (int i = m / 2 - 1; i >= 0; i--) {
        Heapify(E, cost, m, i);
    }

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    int mincost = 0;
    int i = 0;  

    while (i < n - 1 && m > 0) {
        int u = E[0][0];
        int v = E[0][1];
        Adjust(E, cost, m);  

        int j = Find(u);
        int k = Find(v);

        if (j != k) {
            i++;
            t[i][0] = u;
            t[i][1] = v;
            t[i][2] = cost[u][v];
            mincost += cost[u][v];
            Union(j, k);  
        }
    }

    if (i != n - 1) {
        cout << "No spanning tree" << endl;
        return -1;
    }

    return mincost;
}

int main() {
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    int E[MAX][2];  
    int cost[MAX][MAX];  

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cost[i][j] = 1e9;  
        }
    }

    cout << "Enter edges (u, v) and their cost:\n";
    for (int i = 0; i < e; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        E[i][0] = u;
        E[i][1] = v;
        cost[u][v] = c;
        cost[v][u] = c;  
    }

    int mincost = Kruskal(E, cost, v, e, t);
    if (mincost != -1) {
        cout << "Minimum cost of the spanning tree: " << mincost << endl;
        cout << "Edges in the minimum spanning tree:\n";
        for (int i = 1; i <= v - 1; i++) {
            cout << t[i][0] << " - " << t[i][1] << " : " << t[i][2] << endl;
        }
    }

    return 0;
}
