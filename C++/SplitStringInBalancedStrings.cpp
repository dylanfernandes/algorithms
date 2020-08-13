class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int numBalancedStrings = 0;
        
        for(int i = 0; i < s.length();i++){
            if(s.at(i) == 'L')
                balance--;
            else
                balance++;
            if(balance == 0) {
                numBalancedStrings++;
            }
        }
        return numBalancedStrings;
    }
};