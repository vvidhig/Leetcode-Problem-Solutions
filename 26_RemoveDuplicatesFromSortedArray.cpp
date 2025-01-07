class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pt1 = 0;
        int pt2 = 1;
        while(pt2<nums.size())
        {            
            if(nums[pt1]!=nums[pt2])
            {
                pt1 += 1;
                nums[pt1]=nums[pt2];
            }
            pt2 += 1;
        }
        return pt1+1;
    }
};
