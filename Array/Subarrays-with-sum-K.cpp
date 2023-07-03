class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int preSum = 0, count = 0;
        for(int i=0; i<N; i++){
            preSum += Arr[i];
            int remove = preSum - k;
            count += mp[remove];
            mp[preSum] += 1;
        }

        return count;
    }
};
