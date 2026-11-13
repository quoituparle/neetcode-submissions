class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, f] : freq) {
            buckets[f].push_back(num);
        }
        vector<int> ans;
        for (int i = nums.size(); i >=1 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};
