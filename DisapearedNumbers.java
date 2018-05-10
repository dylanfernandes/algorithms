class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> solution = new ArrayList<Integer>();
        boolean[] found = new boolean[nums.length];
        int location = 0;
        
        //locate found numbers
        for(int i = 0; i < nums.length; i++) {
            found[nums[i]-1] = true;
        }
        
        //create list of missing numbers
        for(int i = 0; i < found.length; i++){
            if(!found[i])
                solution.add(i+1);
        }
        return solution;
    }
}