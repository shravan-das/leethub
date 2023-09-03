class Solution {
public:
    int uniquePaths(  int m , int n) {
        
        int N = m+n-2;
        int y = m-1;
        
        double result = 1;
        
        
        for(int i = 1; i<=y ; i++){
            result = result *(N-y+i)/i;
        }
        
        return (int) result;
        
       
        
        
    }
};