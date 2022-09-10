public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for(int i = 0; i < nums.Length; i++) {
            int current = nums[i];
            for(int j = i+1; j < nums.Length; j++) {
                if(current + nums[j] == target)
                    return new int[]{i,j};
            }
        }
        return new int[]{};
    }
}