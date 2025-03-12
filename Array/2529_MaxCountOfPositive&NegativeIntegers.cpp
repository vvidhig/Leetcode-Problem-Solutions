class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int n = nums.size();
        if(nums[0]>0 || nums[n-1]<0)
        {
            return n;
        }
        int pos1 = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]>=0)
            {
                pos1 = i;
                break;
            }
        }
        int pos2 = pos1;
        while(pos2<n && nums[pos2]==0)
        {
            pos2+=1;
        }
        return max((n-pos2), pos1);
    }
};
