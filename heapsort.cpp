#include <iostream>
using namespace std;

int heapify(int arr[], int n, int i, int count) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
        count++;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
        count++;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        count++;
        count = heapify(arr, n, largest, count);
    }

    return count;
}

int heapSort(int arr[], int n) {
    int count = 0;

    for (int i = n/2 - 1; i >= 0; i--) {
        count = heapify(arr, n, i, count);
    }

    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        count++;
        count = heapify(arr, i, 0, count);
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = heapSort(arr, n);
    cout << "Sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << count << endl;
    return 0;
}
