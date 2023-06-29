class Solution {
  public:
  
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        int count = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[a[i]] = 1;
        }
        
        for(int j=0; j<m; j++){
            if(mp[b[j]] == 1){
                count++;
                mp[b[j]] = 0;
            }
        }
        
        return count; 
    }
};
