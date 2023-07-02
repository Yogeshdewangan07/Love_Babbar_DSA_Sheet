class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low >= high){
            return;
        }
        
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[low];
       int cnt = 0;
       for(int i=low+1; i<=high; i++){
           if(arr[i] <= pivot){
               cnt++;
           }
       }
       
       int p = low+cnt;
       swap(arr[low],arr[p]);
       int i=low, j=high;
       
       while(i<p && j>p){
           while(arr[i] <= pivot){
               i++;
           }
           
           while(arr[j] > pivot){
               j--;
           }
           
           if(i<p && j>p){
               swap(arr[i], arr[j]);
               i++, j--;
           }
       }
       
       return p;
    }
};
