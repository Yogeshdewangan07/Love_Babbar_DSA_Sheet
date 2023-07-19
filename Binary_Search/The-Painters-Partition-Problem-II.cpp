class Solution
{
  public:
    long long findFeasible(int arr[], int n, long long limit) {
    long long sum = 0;
    int painters = 1;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum > limit) {
            sum = arr[i];
            painters++;
        }
    }

    return painters;
}

    long long minTime(int arr[], int n, int k)
    {
    long long totalLen = 0;
    int maxi = 0;
    for(int i=0; i<n; i++) {
        maxi = max(maxi, arr[i]);
        totalLen += arr[i];
    }

    long long low = maxi;
    long long high = totalLen;
    while(low < high) {
        long long mid = (low+high)/2;
        int painters = findFeasible(arr, n, mid);
        if(painters <= k) {
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    return low;
    }
};
