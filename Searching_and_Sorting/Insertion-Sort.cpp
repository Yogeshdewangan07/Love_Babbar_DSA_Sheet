class Solution
{
    public:
    void insert(int arr[], int n){
        for(int i=1; i<n; i++){
            
            int current = arr[i];
            int j = i-1;
            
            while(arr[j] > current && j >= 0){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = current;
        }
    }
    
    void insertionSort(int arr[], int n)
    {
        //code here
        insert(arr,n);
    }
};