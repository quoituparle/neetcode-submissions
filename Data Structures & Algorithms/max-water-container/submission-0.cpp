class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int p1 = 0, p2 = n-1;
        int max_area = 0;

        while (p1 < p2) {
            int area = (p2-p1)*min(heights[p1],heights[p2]);
            if (heights[p1] < heights[p2]) p1++;
            else if (heights[p1] > heights[p2]) p2--;
            else {
                if (heights[p1+1] < heights[p2-1]) p2--;
                else if (heights[p1+1] > heights[p2-1]) p1++;
                else p1++;p2--;
            }

            max_area = max(max_area, area);
        }

        return max_area;
    }
};
