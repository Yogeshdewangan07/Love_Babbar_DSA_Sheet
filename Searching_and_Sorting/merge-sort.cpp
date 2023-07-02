class Solution
{
    public:
    long long int merge(int arr[], int l, int mid, int r)
    {
         // Your code here
        // int mid = (l+r)/2;
        long long int inv = 0;
         
        int len1 = mid - l + 1;
        int len2 = r - mid;
         
        int* first = new int[len1];
        int* second = new int[len2];
         
        // copy values
        int mainArrayIndex = l;
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
            if(first[index1] < second[index2]){
                arr[mainArrayIndex++] = first[index1++];
            }else{
                arr[mainArrayIndex++] = second[index2++];
                inv = inv + (len1 - 1);
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
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l >= r){
            return;
        }
        
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
};
