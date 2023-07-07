// User function Template for C++

class Solution{
  public:
    

    // method 1 -> using recursion
    int solve(int ind, int N, int price[]){
        if(ind == 0){
            return N * price[0];
        }
        
        int notTake = 0 + solve(ind-1, N, price);
        int take = INT_MIN;
        int rodLength = ind + 1;
        if(rodLength <= N){
            take = price[ind] + solve(ind, N-rodLength, price);
        }
        
        return max(take, notTake);
    }
    
    int cutRod(int price[], int n) {
        return solve(n-1, n, price);
    }

    // method 2 -> using recursion + memorization
    int solve(int ind, int N, int price[], vector<vector<int>> dp){
        if(ind == 0){
            return N * price[0];
        }
        
        if(dp[ind][N] != -1) return dp[ind][N];
        
        int notTake = 0 + solve(ind-1, N, price, dp);
        int take = INT_MIN;
        int rodLength = ind + 1;
        if(rodLength <= N){
            take = price[ind] + solve(ind, N-rodLength, price, dp);
        }
        
        return dp[ind][N] = max(take, notTake);
    }
    
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n-1, n, price, dp);
    }

    // method 3 -> using tabulation
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        for(int N = 0; N <= n; N++){
            dp[0][N] = N * price[0];
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int N = 0; N <= n; N++){
                int notTake = 0 + dp[ind-1][N];
                int take = INT_MIN;
                int rodLength = ind + 1;
                if(rodLength <= N){
                    take = price[ind] + dp[ind][N-rodLength];
                }
                
                dp[ind][N] = max(take, notTake);
            }
        }
        
        return dp[n-1][n];
    }

    // method 4 -> space optimization (create prev and curr vector)
    int cutRod(int price[], int n) {

        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        
        for(int N = 0; N <= n; N++){
            prev[N] = N * price[0];
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int N = 0; N <= n; N++){
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodLength = ind + 1;
                if(rodLength <= N){
                    take = price[ind] + curr[N-rodLength];
                }
                
                curr[N] = max(take, notTake);
            }

            prev = curr;
        }

        return prev[n];
    }

    // method 5 -> space optimization (create single vector) 
    int cutRod(int price[], int n) {

        vector<int> prev(n+1, 0);
        
        for(int N = 0; N <= n; N++){
            prev[N] = N * price[0];
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int N = 0; N <= n; N++){
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodLength = ind + 1;
                if(rodLength <= N){
                    take = price[ind] + prev[N-rodLength];
                }
                
                prev[N] = max(take, notTake);
            }
        }

        return prev[n];
    }
};
