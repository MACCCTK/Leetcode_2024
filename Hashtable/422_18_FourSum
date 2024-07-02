class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int len =nums.size();
        int res =0;
        for(int i =0;i<len-3;i++){
            int com =target-nums[i];
            if (nums[i] > target && nums[i] >= 0) {
            	break; // 这里使用break，统一通过最后的return返回
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len-2; j++) {
                if (nums[i] + nums[j] > target && nums[j] >= 0) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }//至少会进一轮
                int left = j + 1;
                int right = len - 1;
                while (right > left) {
                    if ((long) nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    } else if ((long) nums[i] + nums[j] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        right--;
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};
