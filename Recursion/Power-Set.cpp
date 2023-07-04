class Solution{
	public:
	    void solve(string s, int index, int n, vector<string>& ans, string output){

	        if(index >= n){
	            if(output != "")
	                ans.push_back(output);
	            return;
	        }
	        
	        // include
	        char element = s[index];
	        output.push_back(element);
	        solve(s, index+1, n, ans, output);
	        output.pop_back();
	        
	        // exclude
	        solve(s, index+1, n, ans, output);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string output = "";
		    int n = s.length();
		    solve(s, 0, n, ans, output);
		    
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
