class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int start = -1;
        int end = -1;
        while(left<n)
        {
            if(nums[left]==target)
            {
                start = left;
                break;
            }
            left += 1;
        }
        while(right>=0)
        {
            if(nums[right]==target)
            {
                end = right;
                break;
            }
            right -= 1;
        }
        vector<int> result = {start, end};
        return result;
    }
};
