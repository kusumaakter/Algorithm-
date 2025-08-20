#include <iostream>
using namespace std;

const int N = 7; // You can modify this for different sizes
int w[N] = {5, 7, 10, 12, 15, 18, 20}; // Set of elements
int x[N]; // To track inclusion (1) or exclusion (0) of elements
int m = 35; // Target sum

void SumOfSub(int s, int k, int r) {
    // Include the current element (Left child)
    x[k] = 1;
    if (s + w[k] == m) {
        // If a valid subset is found, print it
        cout << "Subset found: { ";
        for (int i = 0; i <= k; ++i) {
            if (x[i] == 1) {
                cout << w[i] << " ";
            }
        }
        cout << "}" << endl;
    } else if (s + w[k] + w[k + 1] <= m) {
        // Explore further by including the current element
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }
    // Exclude the current element (Right child)
    if (s + r - w[k] >= m && (s+ w[k+1] <=m)) {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}
int main() {
    int s = 0; // Initial sum
    int r = 0; // Remaining sum (total sum of elements in w)
    // Calculate the total sum of the set w (r)
    for (int i = 0; i < N; ++i) {
        r += w[i];
    }
    // Call the SumOfSub function starting from index 0
    SumOfSub(s, 0, r);
    return 0;
}
