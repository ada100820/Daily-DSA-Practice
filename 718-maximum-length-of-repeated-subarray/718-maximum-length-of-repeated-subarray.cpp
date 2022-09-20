class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};



/* By (DP Tabulation):

Intuition:
We can use a 2D DP array to store the length of the longest common subarray ending at nums1[i] and nums2[j].
The recurrence relation is dp[i][j] = dp[i-1][j-1] + 1 if nums1[i] == nums2[j], otherwise dp[i][j] = 0.

Approach:
--> Create a 2D DP array of size (nums1.size() + 1) * (nums2.size() + 1) and initialize it with 0.
--> Iterate over the DP array and update the values using the recurrence relation.
--> Return the maximum value in the DP array.
--> Time Complexity: O(n*m), where n is the size of nums1 and m is the size of nums2.
--> Space Complexity: O(n*m)
*/