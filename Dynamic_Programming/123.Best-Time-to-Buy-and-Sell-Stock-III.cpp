class Solution {
public:
    //method 1 -> using recursion 
    int solve(int index, int buy, int limit, vector<int>& prices) {
        int n = prices.size();
        if(index == n) {
            return 0;
        }

        if(limit == 0) {
            return 0;
        }

        int profit = 0;
        if(buy) {
            int buyKaro = -prices[index] + solve(index+1, 0, limit, prices);
            int skipKaro = 0 + solve(index+1, 1, limit, prices);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solve(index+1, 1, limit-1, prices);
            int skipKaro = 0 + solve(index+1, 0, limit, prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return solve(0,1,2,prices);
    }

    //method 2 -> recursion + memorization
    int solve(int index, int buy, int limit, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if(index == n) {
            return 0;
        }

        if(limit == 0) {
            return 0;
        }

        if(dp[index][buy][limit] != -1) {
            return dp[index][buy][limit];
        }

        int profit = 0;
        if(buy) {
            int buyKaro = -prices[index] + solve(index+1, 0, limit, prices, dp);
            int skipKaro = 0 + solve(index+1, 1, limit, prices, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solve(index+1, 1, limit-1, prices, dp);
            int skipKaro = 0 + solve(index+1, 0, limit, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][buy][limit] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }

    //method 3 -> tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        
        for(int index=n-1; index>=0; index--) {
            for(int buy=1; buy>=0; buy--) {
                for(int limit=2; limit>=1; limit--) {
                    int profit = 0;
                    if(buy) {
                        int buyKaro = -prices[index] + dp[index+1][0][limit];
                        int skipKaro = 0 + dp[index+1][1][limit];
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + dp[index+1][1][limit-1];
                        int skipKaro = 0 + dp[index+1][0][limit];
                        profit = max(sellKaro, skipKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    //method 4 -> space optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3,0));
        vector<vector<int>> next(2, vector<int>(3,0));
        
        for(int index=n-1; index>=0; index--) {
            for(int buy=1; buy>=0; buy--) {
                for(int limit=2; limit>=1; limit--) {

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
        
        return curr[1][2];
    }
};