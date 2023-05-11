#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Partition the array based on a pivot element
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Pick a random element as the pivot and partition the array
int randomized_partition(vector<int>& arr, int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

// Find the kth smallest element in the array using randomized select algorithm
int randomized_select(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int q = randomized_partition(arr, low, high);
    int i = q - low + 1;

    if (i == k) {
        return arr[q];
    }
    else if (i > k) {
        return randomized_select(arr, low, q - 1, k);
    }
    else {
        return randomized_select(arr, q + 1, high, k - i);
    }
}

int main() {
    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int kth_smallest = randomized_select(arr, 0, n - 1, k);
    cout << "The kth smallest element is: " << kth_smallest << endl;

    return 0;
}
