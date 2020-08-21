class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxes[2] = {0,0};
        
        for(int i = 0; i < nums.size();i++){
            if(nums[i] > maxes[0]){
                maxes[1] = maxes[0];
                maxes[0] = nums[i];
            } 
            else if(nums[i] > maxes[1]) {
                maxes[1] = nums[i];
            }
        }
        
        return (maxes[0]-1)*(maxes[1]-1);
    }
};