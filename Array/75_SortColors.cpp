class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        int temp;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low+=1;
                mid+=1;
            }
            else if(nums[mid]==1)
            {
                mid+=1;
            }
            else
            {
                temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high-=1;
            }
        }
        
    }
};
