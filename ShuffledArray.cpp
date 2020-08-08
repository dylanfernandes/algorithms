class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffledArray;
        for(int i = 0;i < nums.size()/2;i++) {
            shuffledArray.push_back(nums.at(i));
            shuffledArray.push_back(nums.at(n+i));
        }
        return shuffledArray;
    }
};