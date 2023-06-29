class Solution{
    public:

    long long count = 0;
    void helper(int n, int src, int des, int aux){
        if(n==0) return;
        
        helper(n-1, src, aux, des);
        
        cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<des<<endl;
        count++;
        
        helper(n-1, aux, des, src);
    }

    
    long long toh(int N, int from, int to, int aux) {
        helper(N,from,to,aux);
        return count;
    }

};
