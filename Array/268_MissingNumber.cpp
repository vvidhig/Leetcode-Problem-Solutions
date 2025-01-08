class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int min = 0;
        int max = nums.size();
        int sum1 = 0;
        int sum2 = 0;
        while(min<=max)
        {
            sum1+=min;
            min+=1;
        }
        for(int i = 0; i<nums.size(); i++)
        {
            sum2+=nums[i];
        }
        return (sum1-sum2);
    }
};
