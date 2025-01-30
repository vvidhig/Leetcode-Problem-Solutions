class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        vector<int> mpp(256, -1);
        int left = 0;
        int right = 0;
        int n = s.length();
        int max1 = INT_MIN;
        while(right<n)
        {
            if(mpp[s[right]]!=-1)
            {
                left = max(mpp[s[right]]+1, left);
            }
            mpp[s[right]] = right;
            max1 = max(max1, right-left+1);
            right+=1;
        }
        return max1;
    }
};
