class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int slow_ptr = 0;
        int fast_ptr = 0;
        int sum = 0;
        int minLength = INT_MAX;
        
        while (fast_ptr < n){
            sum += nums[fast_ptr];
            while (sum >= target){//滑动窗口
                minLength = min(minLength, fast_ptr - slow_ptr + 1);            
                sum -= nums[slow_ptr];
                slow_ptr++;
            }
            fast_ptr++;
        }
        if (minLength == INT_MAX){
            return 0;
        }
        return minLength;
    }
};
