class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //method 1 -> Naive Approach 
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];

        //method 2 -> Optimal Approach
        priority_queue<int, vector<int>, greater<int>> minpq;
        for(int i=0;i<nums.size();i++){
            if(minpq.size()<k){
                minpq.push(nums[i]);
            }else{
                if(minpq.top()<nums[i]){
                    minpq.pop();
                    minpq.push(nums[i]);
                }
            }
        }
        return minpq.top();
    }
};
