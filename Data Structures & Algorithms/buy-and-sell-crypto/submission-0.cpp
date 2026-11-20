class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int mprofit = 0;
        
        int left = 0, right = 0;
        while (left <= right && right < n) {
            int profit = prices[right] - prices[left];
            mprofit = max(mprofit, profit);
            if (prices[left] > prices[right]) left = right;
            right++;
        }

        return mprofit;
    }
};
