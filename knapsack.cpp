#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n)
{
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main()
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int max_val = knapsack(W, wt, val, n);
    cout << "The maximum value that can be obtained is: " << max_val << endl;

    return 0;
}
