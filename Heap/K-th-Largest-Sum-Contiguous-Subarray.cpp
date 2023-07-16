class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
	//method 1 -> Naive Approach
        vector<int> ans;
        for(int i=0;i<N;i++) {
            int sum =0;
            for(int j=i;j<N;j++){
                sum += Arr[j];
                ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        
        return ans[ans.size()-K];

	//method 2 -> Optimal Approach (using heap)
	priority_queue<int, vector<int>, greater<int> > mini;
        
        for(int i=0;i<N;i++) {
            int sum = 0;
            for(int j=i;j<N;j++) {
                sum += Arr[j];
                
                if(mini.size() < K) {
                    mini.push(sum);
                }else{
                    if(sum > mini.top()) {
                        mini.pop();
                        mini.push(sum);
                    }
                }
                
            }
        }
        
        return mini.top();
    }
};
