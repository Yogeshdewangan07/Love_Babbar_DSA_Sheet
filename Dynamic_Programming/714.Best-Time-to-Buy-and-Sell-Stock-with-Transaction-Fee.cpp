class Solution {
public:
    //method 1 -> recursion
    int solve(int index, int buy, vector<int>& prices, int fee) {
        if(index == prices.size()){
            return 0;
        }
        
        int profit = 0;
        if(buy) {
            int buykaro = -prices[index] + solve(index+1, 0, prices, fee);
            int skipkaro = 0 + solve(index+1, 1, prices, fee);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solve(index+1, 1, prices, fee) - fee;
            int skipkaro = 0 + solve(index+1, 0, prices, fee);
            profit = max(sellkaro, skipkaro);
        }
        return profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        return solve(0, 1, prices,fee);
    }

    //method 2 -> recursion + memorization
    int solve(int index, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee) {
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = 0;
        if(buy) {
            int buykaro = -prices[index] + solve(index+1, 0, prices, dp, fee);
            int skipkaro = 0 + solve(index+1, 1, prices, dp, fee);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solve(index+1, 1, prices, dp, fee) - fee;
            int skipkaro = 0 + solve(index+1, 0, prices, dp, fee);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 1, prices, dp, fee);
    }

    //method 3 -> tabulation
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index >= 0; index--) {
            for(int buy = 1; buy >= 0; buy--) {
                int profit = 0;
                if(buy) {
                    int buykaro = -prices[index] + dp[index+1][0];
                    int skipkaro = 0 + dp[index+1][1];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = prices[index] + dp[index+1][1] - fee;
                    int skipkaro = 0 + dp[index+1][0];
                    profit = max(sellkaro, skipkaro);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    //method 4 -> space optimization
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index = n-1; index >= 0; index--) {
            for(int buy = 1; buy >= 0; buy--) {
                int profit = 0;
                if(buy) {
                    int buykaro = -prices[index] + next[0];
                    int skipkaro = 0 + next[1];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = prices[index] + next[1] - fee;
                    int skipkaro = 0 + next[0];
                    profit = max(sellkaro, skipkaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

};