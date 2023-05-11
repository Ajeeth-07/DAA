#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum element in the array
int findMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform the counting sort algorithm on each digit
void countSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    // Count the number of occurrences of each digit
    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Compute the running sum of the counts
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Place the elements in their sorted positions
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort on the array
void radixSort(vector<int>& arr) {
    int max = findMax(arr);

    // Perform counting sort on each digit from right to left
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {
    // Read in the input array
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array using Radix Sort
    radixSort(arr);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
