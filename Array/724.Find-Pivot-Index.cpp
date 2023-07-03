class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int lsum = 0;
        int rsum = 0;
        for(int i=0 ;i<n; i++){
            rsum += nums[i];
        }

        for(int i=0; i<n; i++){
            lsum += nums[i]; 
            if(lsum == rsum){
                return i;
            }
            
            rsum -= nums[i];
        }

        return -1;
    }
};
