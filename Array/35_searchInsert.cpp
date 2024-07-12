class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { 
            int middle = left + ((right - left) / 2);// 防止溢出
            if (nums[middle] > target) {
                right = middle - 1; 
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        return right + 1;
    }
};
