
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> solution;
        vector<int>::iterator it;

        for(int i = 0; i < index.size(); ++i) {
            vector<int>::iterator it = solution.begin() + index[i];
            solution.insert(it, nums[i]);
        }
        
        return solution;
    }
};