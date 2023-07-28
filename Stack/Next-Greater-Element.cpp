class Solution
{
    public:
    //method 1-> brute force (TLE)
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n,-1);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++){
                if(arr[i]<arr[j]) {
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;

	//method 2-> optimal opproach (using stack)
	vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n);
        stack<long long> s;

        for(int i=n-1; i>=0; i--) {
            long long curr = arr[i];
            while(!s.empty() && s.top() <= curr) {
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }else{
                ans[i] = -1;
                s.push(-1);
            }

            s.push(curr);
        }
        return ans;
    }
};
