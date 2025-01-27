class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);  // Initialize result array with -1
        stack<int> st;           // Monotonic decreasing stack

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();  // Remove smaller elements
            }
            if (!st.empty()) {
                res[i % n] = st.top();  // Assign the next greater element
            }
            st.push(nums[i % n]);  // Push current element onto stack
        }
        return res;
    }
};
