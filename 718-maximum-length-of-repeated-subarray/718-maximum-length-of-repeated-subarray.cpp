class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = m-1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    if (i == 0 || j == 0) dp[j] = 1;
                    else dp[j] = dp[j-1] + 1;
                    ans = max(ans, dp[j]);
                }
                else dp[j] = 0;
            }
        }
        return ans;
    }
};




/* 
(DP Space Optimization):

Intuition:
We can use a 1D DP array to store the length of the longest common subarray ending at nums1[i] and nums2[j].
The recurrence relation is dp[j] = dp[j-1] + 1 if nums1[i] == nums2[j], otherwise dp[j] = 0.

Approach:
--> Create a 1D DP array of size (nums2.size() + 1) and initialize it with 0.
--> Iterate over the DP array and update the values using the recurrence relation.
--> Return the maximum value in the DP array.
--> Time Complexity: O(n*m), where n is the size of nums1 and m is the size of nums2.
--> Space Complexity: O(m)

*/