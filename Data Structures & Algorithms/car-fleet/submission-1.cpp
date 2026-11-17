class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // p + vt = p2 + vt2 => fleet;
        vector<pair<int, int>> stor;
        for (int i = 0; i < position.size(); i++) {
            stor.push_back({position[i], speed[i]});
        }

        sort(stor.rbegin(), stor.rend());

        vector<double> stack;
        for (auto p : stor) {
            double time = (double)(target - p.first) / p.second;
            if (!stack.empty()) {
                if (time <= stack.back()) continue;
                else stack.push_back(time);
            } else stack.push_back(time);
        }

        return stack.size();

    }
};
