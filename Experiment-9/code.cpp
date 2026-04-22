class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int x : arr) sum += x;

        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for(int num : arr){
            for(int j = sum; j >= num; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }

        int mini = INT_MAX;

        for(int s1 = 0; s1 <= sum/2; s1++){
            if(dp[s1]){
                int s2 = sum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }

        return mini;
    }
};

