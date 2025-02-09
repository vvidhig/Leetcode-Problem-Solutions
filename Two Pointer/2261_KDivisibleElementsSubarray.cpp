class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> uniqueSubarrays;
        vector<int> A(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % p == 0) {
                A[i] = 1;
            }
        }

        int n = nums.size();

        for (int left = 0; left < n; left++) {
            vector<int> subarray;
            int countDivisible = 0;

            for (int right = left; right < n; right++) {
                subarray.push_back(nums[right]); 
                countDivisible += A[right];

                if (countDivisible > k) {
                    break; 
                }

                uniqueSubarrays.insert(subarray);
            }
        }

        return uniqueSubarrays.size();
    }
};
