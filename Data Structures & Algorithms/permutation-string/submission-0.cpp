class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        unordered_map<char, int> mp, curr;

        for (char c : s1) {
            mp[c]++;
        }

        for (int i = 0; i < m; i++) {
            curr[s2[i]]++;

            if (i >= n) {
                char c = s2[i - n];
                curr[c]--;

                if (curr[c] == 0) {
                    curr.erase(c);
                }
            }

            if (curr == mp) return true;
        }

        return false;
    }
};
