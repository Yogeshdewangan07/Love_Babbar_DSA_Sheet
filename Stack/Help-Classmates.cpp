class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    {   
	//method 1 -> brute force
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++){
                if(arr[i]>arr[j]) {
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;

	//method 2 -> using stack
	vector<int> ans(n,-1);
        stack<int> s;
        s.push(-1);

        for(int i=n-1; i>=0; i--) {
            int curr = arr[i];
            while(s.top() >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(curr);
        }
        return ans;
    } 
};
