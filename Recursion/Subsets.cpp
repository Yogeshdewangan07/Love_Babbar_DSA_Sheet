class Solution
{
    public:
    void solve(vector<int>& A, int index, vector<int> output, vector<vector<int>>& ans){
        // base case
        if(index >= A.size()){
            ans.push_back(output);
            return;
        }
        
        // include
        int element = A[index];
        output.push_back(element);
        solve(A, index+1, output, ans);
        output.pop_back();
        
        // exclude
        solve(A, index+1, output, ans);
        
    }
    
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(A,index, output, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
