class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSumArray;
        
        for(int i = 0; i < nums.size();i++) {
            if(i == 0)
                runningSumArray.push_back(nums.at(i));
            else {
                int currentValue = runningSumArray.at(i-1) + nums.at(i);
                runningSumArray.push_back(currentValue);
            }
        }
        
        return runningSumArray;
    }
};