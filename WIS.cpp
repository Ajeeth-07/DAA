#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data structure to store a job
struct Job {
    int start, finish, profit;
};

// Function to perform binary search on the start time of jobs
int binarySearch(vector<Job> &jobs, int index)
{
    int lo = 0, hi = index - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start) {
            if (jobs[mid + 1].finish <= jobs[index].start) {
                lo = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            hi = mid - 1;
        }
    }

    return -1;
}

// Function to print the optimal solution
void printOptimalSolution(vector<Job> &jobs, vector<int> &dp, int n)
{
    int profit = dp[n - 1];
    cout << "Optimal profit is " << profit << endl;

    vector<int> selectedJobs;
    int index = n - 1;
    while (index >= 0 && profit > 0) {
        if (jobs[index].profit <= profit) {
            int i = binarySearch(jobs, index);
            if (i != -1) {
                selectedJobs.push_back(jobs[index].profit);
                profit -= jobs[index].profit;
                index = i;
            }
            else {
                index--;
            }
        }
        else {
            index--;
        }
    }

    cout << "Selected Jobs: ";
    for (int i = selectedJobs.size() - 1; i >= 0; i--) {
        cout << selectedJobs[i] << " ";
    }
}

// Function to compute the optimal solution
void weightedIntervalScheduling(vector<Job> &jobs)
{
    // Sort jobs by finish time
    sort(jobs.begin(), jobs.end(), [](const Job &j1, const Job &j2) {
        return j1.finish < j2.finish;
    });

    int n = jobs.size();
    vector<int> dp(n);
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int includeProfit = jobs[i].profit;
        int j = binarySearch(jobs, i);
        if (j != -1) {
            includeProfit += dp[j];
        }
        dp[i] = max(includeProfit, dp[i - 1]);
    }

    printOptimalSolution(jobs, dp, n);
}

// Driver code
int main()
{
    vector<Job> jobs = {
        {1, 3, 5},
        {2, 5, 6},
        {4, 6, 5},
        {6, 7, 4},
        {5, 8, 11},
        {7, 9, 2}
    };

    weightedIntervalScheduling(jobs);

    return 0;
}
