vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i=0; i<n;i++){
                int rem = target-nums[i];
                if(mp.find(rem) != mp.end()){
                    ans.push_back(mp[rem]);
                    ans.push_back(i);
                }
            mp[nums[i]]=i;
        }
        return ans;
}