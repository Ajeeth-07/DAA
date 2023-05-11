#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted subarrays into one sorted array
void merge(vector<int>& arr, int low, int mid, int high, int& compCount)
{
    int n1 = mid - low + 1;     // Size of left subarray
    int n2 = high - mid;        // Size of right subarray

    // Create temporary arrays to hold left and right subarrays
    vector<int> left(n1);
    vector<int> right(n2);

    // Copy data from main array to temporary arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    // Merge the two subarrays into one sorted array
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        compCount++;
        k++;
    }

    // Copy remaining elements of left subarray
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort on an array
void mergeSort(vector<int>& arr, int low, int high, int& compCount)
{
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid, compCount);
        mergeSort(arr, mid + 1, high, compCount);

        merge(arr, low, mid, high, compCount);
    }
}

// Function to count the number of comparisons in Merge Sort
int countComparisons(vector<int>& arr)
{
    int compCount = 0;
    mergeSort(arr, 0, arr.size() - 1, compCount);
    return compCount;
}

// Main function to test the program
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int compCount = countComparisons(arr);
    cout << "Number of comparisons: " << compCount << endl;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
