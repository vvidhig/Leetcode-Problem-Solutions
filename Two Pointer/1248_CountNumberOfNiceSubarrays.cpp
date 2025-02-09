class Solution {
public:
    int atmost(vector<int> A, int k)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int n = A.size();
        int count = 0;
        while(right<n)
        {
            sum += A[right];
            while(sum>k)
            {
                sum -= A[left];
                left+=1;
            }
            count += (right-left+1);
            right+=1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> A(nums.size(), 0);
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]%2!=0)
            {
                A[i]=1;
            }
        }
        return (atmost(A, k)-atmost(A, k-1));
    }
};
