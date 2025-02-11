class Solution {
public:
    void maxHeapify(vector<int>& nums, int i, int n)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;
        if(left<n && nums[left]>nums[largest])
        {
            largest = left;
        }
        if(right<n && nums[right]>nums[largest])
        {
            largest = right;
        }
        if(largest!=i)
        {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest, n);
        }
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        if(k>nums.size())
        {
            return -1;
        }
        int n = nums.size();
        for(int i = nums.size()/2 - 1; i>=0; i--)
        {
            maxHeapify(nums, i, n);
        }
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[n - 1 - i]);  // Move max to end
            maxHeapify(nums, 0, n - 1 - i);  // Restore heap property
        }
        return nums[0];
    }
};
