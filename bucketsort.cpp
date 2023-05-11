#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    vector<float> buckets[n];
    
    // Put array elements in their respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }
    
    // Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    
    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    float arr[n];
    cout << "Enter the elements (between 0 and 1): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    bucketSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
