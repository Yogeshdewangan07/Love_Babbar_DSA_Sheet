class Solution {
  public:
    long long solve(int dice, int faces, int target){
        //base case
        if(target < 0) return 0;
        if(dice == 0 && target != 0) return 0;
        if(target == 0 && dice != 0) return 0;
        if(dice == 0 && target == 0) return 1;
        
        long long ans = 0;
        for(int i=1; i<=faces; i++){
            ans = ans + solve(dice-1, faces, target-i);
        }
        
        return ans;
    }
  
    long long noOfWays(int M , int N , int X) {
        return solve(N, M, X);
    }
};
