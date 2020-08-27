class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> uniqueNumbers;
        bool hasZero = n%2 == 1;
        int midPoint = n/2;
        
        for(int i = midPoint;i >= 0; i--) {
            if(i == 0)
                if(!hasZero)
                    break;
                else
                    uniqueNumbers.push_back(i);
            else {
                uniqueNumbers.push_back(i);
                uniqueNumbers.push_back(-1 * i);
            }
        }
        
        return uniqueNumbers;
    }
};