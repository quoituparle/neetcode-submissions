class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }

        int s = bin_find(nums, 0, nums.size() - 1);
        if (nums.back() < target) {
            return tar_find(nums, 0, s - 1, target);
        } else {
            return tar_find(nums, s, nums.size() - 1, target);
        }

    }
private:
    int bin_find(vector<int>& nums, int left, int right) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int tar_find(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
