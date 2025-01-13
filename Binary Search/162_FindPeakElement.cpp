class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = n-2;
        int mid;
        if(n==1)
        {
            return 0;
        }
        if (nums[0] > nums[1]) 
            return 0;
        if (nums[n - 1] > nums[n - 2]) 
            return n - 1;

        while(left <= right)
        {
            mid = (left+right)/2;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            if(nums[mid]>nums[mid-1])
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return -1;
    }
};
