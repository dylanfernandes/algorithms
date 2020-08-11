class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        string palindromeCandidate = to_string(x);
        int candidateLength = palindromeCandidate.length();
        
        for(int i = 0; i < candidateLength/2; i++){
            int endIndex = candidateLength - i - 1;
            if(palindromeCandidate.at(i) != palindromeCandidate.at(endIndex))
                return false;
        }
        return true;
    }
};