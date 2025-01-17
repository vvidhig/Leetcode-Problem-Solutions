class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int max1 = 0;
        int b = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i]=='(')
            {
                b+=1;
                max1 = max(max1, b);
            }
            if(s[i]==')')
            {
                b-=1;
            }
        }
        return max1;
    }
};
