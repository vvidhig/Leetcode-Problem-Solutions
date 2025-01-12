class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = n/2;
        int left = 0;
        int right  = n-1;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            if(nums[mid]>target)
            {
                right = mid-1;
            }
            if(nums[mid]<target)
            {
                left = mid+1;
            }
            if(nums[mid]==target)
            {
                return mid;
            }
        }
        return -1;
    }
};
