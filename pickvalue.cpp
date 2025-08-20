#include <bits/stdc++.h>
using namespace std;

// Function to find a peak element
int findPeak(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;

    // Check if mid is a peak
    if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&
        (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
        return mid;
    }

    // If left neighbor is bigger, search left
    if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeak(arr, low, mid - 1, n);
    }

    // Otherwise, search right
    return findPeak(arr, mid + 1, high, n);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int peakIndex = findPeak(arr, 0, n - 1, n);
    cout << "A peak element is " << arr[peakIndex]
         << " at index " << peakIndex << endl;

    return 0;
}

