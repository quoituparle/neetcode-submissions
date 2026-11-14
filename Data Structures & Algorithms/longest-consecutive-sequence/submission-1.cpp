class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) st.insert(num);

        int max_len = 0;
        for (int num : st) {
            if (st.contains(num - 1)) continue;

            int length = 0;
            while (st.contains(num)) {
                num++;
                length++;
            }
            max_len = max(max_len, length);
        }

        return max_len;
    }
};
