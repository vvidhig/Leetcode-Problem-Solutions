class Solution {
public:
    int countPartitions(vector<int> nums, int mid)
    {
        int cap = 0;
        int maxi = INT_MIN;
        int partitions = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            if((cap+nums[i])<=mid)
            {
                cap += nums[i];
            }
            else
            {   
                partitions += 1;
                cap = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left<=right)
        {
            int mid = (left+right)/2;
            int part = countPartitions(nums, mid);
            if(part <= k)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
