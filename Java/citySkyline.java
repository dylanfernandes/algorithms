class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] udMax = new int[grid.length];
        int[] lrMax = new int[grid[0].length];
        Arrays.fill(udMax, 0);
        Arrays.fill(lrMax, 0);
        int curr;
        int value;
        int sum = 0;

        //set row and column max
        for(int lr = 0; lr < grid.length; lr++) {
            for(int ud = 0; ud < grid[lr].length; ud++) {
                curr = grid[lr][ud];
                if(lrMax[lr] < curr)
                    lrMax[lr] = curr;
                if(udMax[ud] < curr)
                    udMax[ud] = curr;
            }
        }
        
        //increase height depending on max of row and column of building
         for(int lr = 0; lr < grid.length; lr++) {
            for(int ud = 0; ud < grid[lr].length; ud++) {
                curr = grid[lr][ud];
                if(lrMax[lr] > curr && udMax[ud] > curr) {
                    if(lrMax[lr] < udMax[ud])
                        value = lrMax[lr];
                    else 
                        value = udMax[ud];
                    sum += value - curr;
                    grid[lr][ud] = value;
                }
            }
        }
        return sum;
    }
}