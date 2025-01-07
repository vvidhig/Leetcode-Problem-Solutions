class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 0;
        for(int i = 0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
            {
                c+=1;
            }
        }
        if((c==1 && nums[0]>=nums[nums.size()-1]) || c==0)
        {
            return true;
        }
        return false;
    }
};

// EXPLANATION - https://www.youtube.com/watch?v=Z7_nMTHROZo
