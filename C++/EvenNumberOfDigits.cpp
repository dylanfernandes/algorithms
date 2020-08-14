class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenNumbers = 0;
        for(int i = 0; i < nums.size();i++) {
            if(numDigits(nums[i])%2 == 0)
                evenNumbers++;
        }
        return evenNumbers;
    }
    
    int numDigits(int number){
        int numberOfDigits = 0;
        while(number > 0) {
            number/=10;
            numberOfDigits++;
        }
        return numberOfDigits;
    }
};