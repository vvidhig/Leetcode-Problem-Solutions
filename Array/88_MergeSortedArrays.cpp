class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m+n-1;
        int right = n-1;
        int key = m-1;
        while(right>=0)
        {
            if(key>=0 && nums1[key]>nums2[right])
            {
                nums1[left] = nums1[key];
                key -= 1;
            }
            else
            {
                nums1[left] = nums2[right];
                right -= 1;
            }
            left -= 1;
        }
    }
};
