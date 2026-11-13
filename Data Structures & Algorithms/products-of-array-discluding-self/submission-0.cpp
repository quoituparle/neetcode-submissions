class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int null_count = 0;
        int total = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                null_count++;
                continue;
            }
            total *= nums[i];
        }

        vector<int> ans(n,0);
        if (null_count > 1) return ans;
        for (int i = 0; i < n; i++) {
            if (null_count == 1) {
                if (nums[i] == 0) {
                    ans[i] = total;
                    return ans;
                }
            } else {
                ans[i] = total/nums[i];
            }

        }

        return ans;
    }
};
