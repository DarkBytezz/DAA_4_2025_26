#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        vector<pair<int,int>> jobs;
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        
        sort(jobs.rbegin(), jobs.rend());

        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int cnt = 0, totalProfit = 0;

        for (auto &job : jobs) {
            int prof = job.first;
            int dead = job.second;

            int slot = find(dead);
            if (slot > 0) {
                cnt++;
                totalProfit += prof;
                parent[slot] = find(slot - 1); 
            }
        }

        return {cnt, totalProfit};
        
    }
};

int main() {
    Solution s;

    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit   = {100, 19, 27, 25, 15};

    vector<int> ans = s.jobSequencing(deadline, profit);

    cout << "Jobs done: " << ans[0] << endl;
    cout << "Total profit: " << ans[1] << endl;

    return 0;
}
