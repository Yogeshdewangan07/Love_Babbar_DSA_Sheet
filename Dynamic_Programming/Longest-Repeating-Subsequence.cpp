class Solution {
	public:
	    int solve(string& a, int i, int j, vector<vector<int>> &dp) {
        if(i >= a.length() || j >= a.length()){
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == a[j] && i != j) {
            ans = 1 + solve(a, i+1, j+1, dp);
        }else{
            ans = max(solve(a,i,j+1,dp), solve(a,i+1,j,dp));
        }

        return dp[i][j] = ans;
    }
	    
	int LongestRepeatingSubsequence(string str){
 	    int n = str.length();
            vector<vector<int>> dp(n, vector<int>(n, -1));
            return solve(str,0,0,dp);
	}

};
