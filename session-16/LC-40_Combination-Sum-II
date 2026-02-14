class Solution {
public:
    void solve(vector<int>& nums, int target, int idx, vector<int>& temp,vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])continue;
            if (nums[i] > target)break;
            
            temp.push_back(nums[i]);
            solve(nums, target - nums[i], i + 1, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;

        solve(candidates, target, 0, temp, result);
        return result;
    }
};
