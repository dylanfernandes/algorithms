class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = -1;
        int sum = 0;
        
        while(n != 0){
            int currentDigit = n%10;
            
            sum += currentDigit;
            if(product == -1)
                product = currentDigit;
            else
                product *= currentDigit;
            
            n = n/10;
        }
        
        return product - sum;    
    }
};