class Solution {
    public int climbStairs(int n) {
     List<Integer> cache = new ArrayList<Integer>();
     cache.add(1);
     cache.add(1); 
     //store previously computed values for stair increasing stair size
     for(int i = 2; i <= n;i++) {
         cache.add(cache.get(i-1) + cache.get(i-2));
     }
        return cache.get(n);
    }
    
}