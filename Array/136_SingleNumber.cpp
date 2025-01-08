class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int xor1 = nums[0];
        for(int i = 1; i<nums.size(); i++)
        {
            xor1 = xor1 ^ nums[i];
        }
        return xor1;
    }
};
