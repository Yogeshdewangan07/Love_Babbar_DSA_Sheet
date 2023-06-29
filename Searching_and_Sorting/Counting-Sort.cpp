class Solution{
    public:
    
    string countSort(string arr){
        // step 1 -> create count array
        vector<int> count(26,0);
        
        // step 2 -> count frequency of each element
        for(int i=0; i<arr.length(); i++){
            int number = arr[i] - 'a';
            count[number]++;
        }
        
        // step 3 -> add previous index value to the current index value
        for(int i=0; i<26; i++){
            count[i] += count[i-1];
        }
        
        // step 4 -> create ans array with size of original array
        string ans(arr.length(), ' ');
        
        // step 5 -> store element count from the originay array to the ans array
        for(int i=0; i<arr.length(); i++){
            int x = --count[arr[i] - 'a'];
            ans[x] = arr[i];
        }
        
        return ans;
    }
};
