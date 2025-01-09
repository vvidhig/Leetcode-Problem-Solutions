class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        int n = nums.size();
        vector<int> num(n, 0);
        int k = 0;
        while(k<n)
        {
            if(nums[k]>=0)
            {
                num[pos] = nums[k];
                pos+=2;
            }
            else
            {
                num[neg] = nums[k];
                neg+=2;
            }
            k+=1;
        }
        return num;
    }
};
