class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        int ans = -1;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(target <= nums[mid])
            {
                ans = mid;
                right = mid-1;
            }
            else if(target > nums[mid])
            {
                left = mid+1;
            }
        }
        if(ans == -1)
        {
            return n;
        }
        return ans;
    }
};
