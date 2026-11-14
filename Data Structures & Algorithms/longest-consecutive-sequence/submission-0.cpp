class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }

        int max_sq = 0;
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.contains(nums[i])) continue;

            int temp = nums[i];
            int sq = 0;
            while (st.contains(temp)) {
                seen.insert(temp);
                temp++;
                sq++;
            }

            max_sq = max(max_sq, sq);
        }

        return max_sq;
    }
};
