#include <map>
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> valuesMap;
        map<int, int>::iterator it;
        int sum = 0;
            
        for(int i = 0; i < nums.size();i++) {
            int currentValue = nums.at(i);
            it = valuesMap.find(currentValue);
            
            if (it != valuesMap.end())
                it->second = it->second + 1;
            else
                valuesMap[currentValue] = 1;
        }
        
        for ( it = valuesMap.begin(); it != valuesMap.end(); it++ )
        {
           sum += calculateDecreasingSum(it->second);
        }
        return sum;
    }
    
    int calculateDecreasingSum(int count){
        return (count*(count -1))/2;
    }
};