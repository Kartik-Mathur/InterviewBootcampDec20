class Solution {
public:
    int numSquares(int n) {
        while(n%4 == 0){
            n/=4;
        }
        if(n%8 == 7) return 4;
        
        int y = ((int)sqrt(n))*((int)sqrt(n));
        cout<<y<<endl;
        if(y == n) return 1;
        
        for(int i = 1 ; i * i <= n ; i++){
            int diff = n-i*i;
            // check if x is a perfect square
            // then we can represent n, using two perfect squares
            // sqrt(x)*sqrt(x) + i*i
            int y = ((int)sqrt(diff))*((int)sqrt(diff));
            if(y == diff){
                return 2;
            }
        }
        
        return 3;
    }
};