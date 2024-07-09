class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        // 将slowIndex之后的冗余元素赋值为0
        for (int i = slowIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = 0; // 合并后的指针

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[index], nums[i]);
                index++;
            }
        }
    }
};
