class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for (char c : s) {
            int i = c - 'a';
            dp[i] = 1 + getMaxReachable(dp, i, k);
        }
        return *max_element(dp.begin(), dp.end());
    }
    int getMaxReachable(vector<int>& dp, int i, int k) {
        int first = max(0, i - k);
        int last = min(25, i + k);
        int maxReachable = 0;
        for (int j = first; j <= last; ++j) {
            maxReachable = max(maxReachable, dp[j]);
        }
        return maxReachable;
    }
};
