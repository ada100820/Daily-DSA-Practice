class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int n, int j, vector<int> &nums, vector<int> &multipliers){
        if (j == multipliers.size()) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        int left = solve(i + 1, n, j + 1, nums, multipliers) + (nums[i] * multipliers[j]);
        int right = solve(i, n, j + 1, nums, multipliers) + (nums[(n - 1) - (j - i)] * multipliers[j]);
        return dp[i][j] = max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {   
        int n = nums.size(), m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, n, 0, nums, multipliers);
    }
};

/*
Intuition:
The maximum score is the maximum of the sum of the first i elements of nums and the last i elements of nums. Thus, we require something like a dp that stores the maximum score for the first i elements of nums and the last i elements of nums.

Approach:
We will need dp for :-
--> Because we need to find the maximum score for each i.
--> So we need to find the maximum score for each i-1 and then add the last element of multipliers to it.
So we need to find the maximum score for eachi-2 and then add the last two elements of multipliers to it & so on.
And dp is the best way to do that.
dp will be a 2d array of size (m+1)*(m+1) where m is the size of multipliers.
dp will store the maximum score for each i.
dp[i][j] will store the maximum score for the first i elements of nums and the last j elements of multipliers.
using dp we will make sure that we don't calculate the same thing twice
and we will calculate the maximum score for each i.

Time Complexity: O(M*M)
Space Complexity: O(M*M)
*/