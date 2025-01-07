class Solution {
public:
    void reverse(vector<int>& nums, int start, int end)
    {
        while(start<=end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start+=1;
            end-=1;
        }
    }
    void rotate(vector<int>& nums, int k) {

        int n = nums.size()-1;
        k = k%(n+1);
        if(n>=1)
        {
        reverse(nums, 0, n-k);
        reverse(nums, n-k+1, n);
        reverse(nums, 0, n);
        }
    }
};
