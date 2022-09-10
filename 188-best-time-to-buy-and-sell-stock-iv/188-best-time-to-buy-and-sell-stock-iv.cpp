class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy==0){// We can buy the stock
                        dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], -prices[ind] + dp[ind+1][1][cap]);
                     }
                    if(buy==1){// We can sell the stock
                        dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],prices[ind] + dp[ind+1][0][cap-1]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};


/*
Intuition:
Every day, we will have two choices, either to do nothing and move to the next day or to buy/sell (based on the last transaction and the number of transactions left) and find out the profit. Therefore we need to generate all the choices in order to compare the profit. As we need to try out all the possible choices, we will use recursion and then further optimize it using Dp because of overlapping sub-problems.


Recursive Solution to Tabulation:
Approach:(Tabulation DP)

First we declare the dp array of size [n+1][2][k+1] as zero.
As we have initialized the array as 0, we have automatically set the base condition i.e if( ind == n || cap == 0) return 0
Now, when we are traversing the array in the opposite direction of that of the memoization technique. We will start from ind = n-1 -> ind =0, absolutely in the reverse fashion.
In every iteration copy the recursive code logic.
At last dp[0][0][k] ( maximum profit generated on ith day, when we can buy the stock on 0th day and can have a total k transactions) gives us the final answer.
C++:(Tabulation)


Time Complexity: O(N*2xK)
Space Complexity: O(N*2xK)

*/