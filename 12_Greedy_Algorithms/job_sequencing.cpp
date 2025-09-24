//GFH:Job Sequencing
//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline, profit;
};

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();

        // Pack jobs into a struct
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {deadline[i], profit[i]};
        }

        // Sort by profit descending
        sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
            return a.profit > b.profit;
        });

        // Find max deadline
        int max_deadline = 0;
        for (auto &j : jobs) max_deadline = max(max_deadline, j.deadline);

        // Slot array to track free slots
        vector<int> slot(max_deadline, -1);

        int jobCount = 0, maxProfit = 0;

        for (int i = 0; i < n; i++) {
            // Try to put this job in the latest possible free slot
            for (int j = jobs[i].deadline - 1; j >= 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;   // job placed
                    jobCount++;
                    maxProfit += jobs[i].profit;
                    break;
                }
            }
        }

        return {jobCount, maxProfit};
    }
};

int main() {
    Solution s;
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit   = {100, 19, 27, 25, 15};

    vector<int> ans = s.jobSequencing(deadline, profit);
    cout << "Jobs done = " << ans[0] << ", Profit = " << ans[1] << endl;
    return 0;
}
