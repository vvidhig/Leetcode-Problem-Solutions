class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }
        for(int i = 0; i<n; i++)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum<0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};
