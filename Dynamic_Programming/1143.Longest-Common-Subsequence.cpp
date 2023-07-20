class Solution {
public:
    //method 1 -> recursion
    int solve(string a, string b, int i, int j) {
        if(i == a.length()){
            return 0;
        }
        if(j == b.length()) {
            return 0;
        }

        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1 + solve(a, b, i+1, j+1);
        }else{
            ans = max(solve(a,b,i,j+1), solve(a,b,i+1,j));
        }

        return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2,0,0);
    }

    //method 2 -> recursion + memorization
    int solve(string& a, string& b, int i, int j, vector<vector<int>> &dp) {
        if(i == a.length()){
            return 0;
        }
        if(j == b.length()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1 + solve(a, b, i+1, j+1, dp);
        }else{
            ans = max(solve(a,b,i,j+1,dp), solve(a,b,i+1,j,dp));
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1,text2,0,0,dp);
    }

    //method 3 -> tabulation
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) {
                    ans = 1 + dp[i+1][j+1];
                }else{
                    ans = max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    
    //method 4 -> space optimization
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) {
                    ans = 1 + next[j+1];
                }else{
                    ans = max(curr[j+1], next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};