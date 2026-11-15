class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);

        vector<int> temp;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!temp.empty() && temperatures[i]>temperatures[temp.back()])
            {   
                ans[temp.back()] = i - temp.back();
                temp.pop_back();
            }

            temp.push_back(i);
        }

        return ans;
    }
};
