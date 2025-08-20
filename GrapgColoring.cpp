#include <iostream>
#include <cstdlib>  // For abs()

using namespace std;
// Global array to store the column positions of queens
int x[100];
// Function to check if a queen can be placed at position (k, i)
bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        // Check if two queens are in the same column or on the same diagonal
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false; // Invalid position
        }
    }
    return true; // Valid position
}
// Function to print the chessboard
void PrintBoard(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << " Q ";  // Queen is placed here
            else
                cout << " . ";  // Empty space
        }
        cout << endl;
    }
    cout << endl;
}
// Backtracking function to find all solutions
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i; // Place the queen at row k, column i

            if (k == n) {
                // All queens are placed, print the solution
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " "; // Print the column position of queens
                }
                cout << endl;
                PrintBoard(n);
            } else {
                // Recur to place queens in the next row
                NQueens(k + 1, n);
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the value of n (size of the board and number of queens): ";
    cin >> n;
    NQueens(1, n); // Start placing queens from row 1
    return 0;
}
