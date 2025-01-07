class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pt1 = 0;
        int pt2 = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                pt1 = i;
                pt2 = i+1;
                break;
            }
        }
        while(pt2<nums.size())
        {
            if(nums[pt1]==0 && nums[pt2]!=0)
            {
                int temp = nums[pt1];
                nums[pt1] = nums[pt2];
                nums[pt2] = temp;
                pt1 += 1;
                pt2 += 1;
            }
            else
            {
                //pt1 += 1;
                pt2 += 1;
            }
        }
    }
};
