class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> set = new HashMap<Integer, Integer>();
        int[] sol = new int[2];
        int comp;
        for(int i = 0; i < nums.length; i++) {
            comp = target - nums[i];
            if(set.containsKey(comp)) {
                if(i < set.get(comp)) {
                    sol[0] = i;
                    sol[1] = set.get(comp);
                }
                else {
                    sol[0] = set.get(comp);
                    sol[1] = i;
                }
                return sol;
            }
            else {
                set.put(nums[i], i);
            }
        }
        return null;
    }
}