class Solution {
public:
    //method 1 -> recursion + memorization
    int solve(int index, int operationNo, int k, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if(index == n) {
            return 0;
        }

        if(operationNo == 2*k) {
            return 0;
        }

        if(dp[index][operationNo] != -1) {
            return dp[index][operationNo];
        }

        int profit = 0;
        if(operationNo%2 == 0) {
            int buyKaro = -prices[index] + solve(index+1, operationNo+1, k, prices, dp);
            int skipKaro = 0 + solve(index+1, operationNo, k, prices, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solve(index+1, operationNo+1, k, prices, dp);
            int skipKaro = 0 + solve(index+1, operationNo, k, prices, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[index][operationNo] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k,-1));
        return solve(0,0,k,prices,dp);
    }

    //method 2 -> space optimization
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1,0));
        vector<vector<int>> next(2, vector<int>(k+1,0));
        
        for(int index=n-1; index>=0; index--) {
            for(int buy=1; buy>=0; buy--) {
                for(int limit=k; limit>=1; limit--) {

                    int profit = 0;
                    if(buy) {
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipKaro = 0 + next[1][limit];
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + next[1][limit-1];
                        int skipKaro = 0 + next[0][limit];
                        profit = max(sellKaro, skipKaro);
                    }
                    curr[buy][limit] = profit;
                }
                next = curr;
            }
        }
        
        return curr[1][k];
    }
};