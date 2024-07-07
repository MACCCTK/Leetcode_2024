class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end()); 
        int hash[101];
        for (int i = vec.size() - 1; i >= 0; i--) {
            hash[vec[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};

// 创建频率数组
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(const vector<int>& nums) {
        vector<int> freq(*max_element(nums.cbegin(), nums.cend()) + 1, 0);
        for(auto num: nums){
            freq[num]++;
        }
        for(int i = 1; i < freq.size(); i++){
            freq[i] += freq[i - 1];
        }
        vector<int> ans;
        ans.reserve(nums.size());

        // 对于每个数字 num，如果 num 不是 0，则它左侧比它小的数的数量为 freq[num - 1]
        for(auto num: nums){
            ans.push_back(num == 0 ? 0 : freq[num - 1]);
        }
        return ans;
    }
};
