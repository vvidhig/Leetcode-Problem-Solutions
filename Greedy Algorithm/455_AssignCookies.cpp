class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0;
        int right = 0;
        int cookies = s.size();
        int greed = g.size();
        int cnt = 0;
        while(left<cookies && right<greed)
        {
            if(s[left] >= g[right])
            {
                cnt += 1;
                left += 1;
                right += 1;
            }
            else
            {
                left += 1;
            }
        }
        return cnt;
    }
};
