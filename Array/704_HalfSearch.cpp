class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { 
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1; 
            } else if (nums[middle] < target) {
                left = middle + 1; 
            } else { // nums[middle] == target
                return middle; 
            }
        }
        // 
        return -1;
    }
};
