#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int arr[], int low, int high, int& count) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            count++;
        }
    }
    swap(arr[i+1], arr[high]);
    count++;
    return i+1;
}

int randomizedPartition(int arr[], int low, int high, int& count) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    count++;
    return partition(arr, low, high, count);
}

int quickSort(int arr[], int low, int high, int& count) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high, count);
        quickSort(arr, low, pi - 1, count);
        quickSort(arr, pi + 1, high, count);
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
    int count = 0;
    quickSort(arr, 0, n - 1, count);
    cout << "Sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << count << endl;
    return 0;
}
