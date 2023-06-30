int firstOccurrence(int arr[], int n, int x){
    int s = 0;
    int e = n-1;
    int ans = -1;
    
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==x){
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid] > x){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    
    return ans;
}

int lastOccurrence(int arr[], int n, int x){
    int s = 0;
    int e = n-1;
    int ans = -1;
    
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==x){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid] > x){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    int first = firstOccurrence(arr,n,x);
    int last = lastOccurrence(arr,n,x);
    ans.push_back(first);
    ans.push_back(last);

    return ans;
}

