class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> greatestPossibilities;
        int max = 0;
        
        for(int i = 0; i < candies.size(); i++) {
            int currentCount = candies.at(i) ;
            if(max < currentCount)
                max = currentCount;
            greatestPossibilities.push_back(false);
        }
        
        for(int i = 0; i < candies.size(); i++) {
            int maxCount = candies.at(i) + extraCandies;
            if(max <= maxCount)
                greatestPossibilities[i] = true;
        }
        
        return greatestPossibilities;
    }
};