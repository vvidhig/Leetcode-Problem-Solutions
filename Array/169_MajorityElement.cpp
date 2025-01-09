class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = NULL;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]==element)
            {
                count+=1;
            }
            else
            {
                if(count>0)
                {
                    count-=1;
                }
                else
                {
                    count = 0;
                    element = nums[i];
                }
            }
        }
        return element;
    }
};
