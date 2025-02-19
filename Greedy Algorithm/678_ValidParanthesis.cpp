class Solution {
public:
    bool checkValidString(string s) 
    {
        int open = 0;
        int close = 0;
        int n = s.length();
        for(int i = 0; i<n; i++)
        {
            char ch = s[i];
            if(ch=='(')
            {
                open++;
                close++;
            }
            else if(ch==')')
            {
                open--;
                close--;
            }
            else
            {
                open--;
                close++;
            }
            if(close<0)
            {
                return false;
            }
            if(open<0)
            {
                open = 0;
            }
        }
        return open==0;
    }
};
