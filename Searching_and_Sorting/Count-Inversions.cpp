class Solution{
  public:
    long long int merge(long long arr[], int l, int mid, int r) {
        
        long long int inv = 0;
        long long int len1 = mid - l + 1;
        long long int len2 = r - mid;
         
        long long int* first = new long long int[len1];
        long long int* second = new long long int[len2];
         
        // copy values
        long long int mainArrayIndex = l;
        for(int i=0; i<len1; i++){
            first[i] = arr[mainArrayIndex++];
        }
        
        mainArrayIndex = mid+1;
        for(int i=0; i<len2; i++){
            second[i] = arr[mainArrayIndex++];
        }
        
        
        // merge two sorted array
        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = l;
        
        while(index1 < len1 && index2 < len2){
            if(first[index1] <= second[index2]){
                arr[mainArrayIndex++] = first[index1++];
            }else{
                arr[mainArrayIndex++] = second[index2++];
                inv += len1 - index1;
            }
        }
        
        while(index1 < len1){
            arr[mainArrayIndex++] = first[index1++];
        }
        
        while(index2 < len2){
            arr[mainArrayIndex++] = second[index2++];
        }
        return inv;
    }
    
    long long int mergeSort(long long arr[], int l, int r)
    {
        if(l >= r){
            return 0;
        }

        long long int inv = 0;
        long long int mid = l+(r-l)/2;
        inv += mergeSort(arr,l,mid);
        inv += mergeSort(arr,mid+1,r);
        
        inv += merge(arr,l,mid,r);
        
        return inv;
    } 
 
    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans = mergeSort(arr,0,N-1);
        return ans;
    }

};
