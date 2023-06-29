class Solution
{
    public:
    int select(int arr[], int n){
        
        for(int i=0; i<n-1; i++){
            int index = i;
            for(int j=i+1; j<n; j++){
                if(arr[j] < arr[index]){
                    index = j;
                }
            }
            swap(arr[i], arr[index]);
        }
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       select(arr,n);
    }
};