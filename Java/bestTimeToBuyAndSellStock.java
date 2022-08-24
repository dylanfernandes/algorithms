class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        if(prices.length > 0) {
            int currentMin = prices[0];
            for(int i = 0; i < prices.length; i++) {
                int currentPrice = prices[i];
                if(currentPrice < currentMin)
                    currentMin = currentPrice;
                else {
                    int currentProfit = currentPrice - currentMin;
                    if(currentProfit > profit)
                        profit = currentProfit;
                }
            }
        }
        return profit;
    }
}