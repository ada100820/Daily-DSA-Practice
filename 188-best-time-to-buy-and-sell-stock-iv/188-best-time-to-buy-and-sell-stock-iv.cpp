class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int> (k+1,0));
        vector<vector<int>> cur(2,vector<int> (k+1,0));
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy==0){// We can buy the stock
                        cur[buy][cap] = max(0+ahead[0][cap],-prices[ind] + ahead[1][cap]);
                    }
                    if(buy==1){// We can sell the stock
                        cur[buy][cap] = max(0+ahead[1][cap],prices[ind] + ahead[0][cap-1]);
                    }
                }
            }
            ahead = cur;
        }
        return ahead[0][k];
    }
};



/*
Intuition:
Every day, we will have two choices, either to do nothing and move to the next day or to buy/sell (based on the last transaction and the number of transactions left) and find out the profit. Therefore we need to generate all the choices in order to compare the profit. As we need to try out all the possible choices, we will use recursion and then further optimize it using Dp because of overlapping sub-problems.


Tabulation to Space Optimization:
If we see carefully, one thing that we can notice is that: dp[ind][buy][cap] = max( dp[ind+1][buy][cap] , max( dp[ind+1][!buy][cap])
So, to calculate a value of a cell of the dp array, we need only the next row values(say ahead of ind+1). So, we don’t need to store an entire 2-D array. Hence we can Space Optimize it.
Steps:

We create two 2D vector ahead and cur both initialized to 0 (base condition)
Then we set three nested loops to calculate the cur array’s values.
We replace dp[ind] with cur and dp[ind+1] with ahead in our tabulation code.
After the inner loop execution is done, we set ahead as cur for the next outer loop iteration.
At last, we return ahead[0][k] as our answer.
C++:(Space Optimized)

Time Complexity: O(N*2xK)
Space Complexity: O(K) We are using two external arrays of size ‘2*K’.

*/