class Solution {
public:
    string removeOuterParentheses(string s) {
        int oc = 0;
        int cc = 0;
        int n = s.length();
        int start = 0;
        string result = "";
        for(int i = 0; i<n; i++)
        {
            char ch = s[i];
            if(ch=='(')
            {
                oc+=1;
            }
            else if(ch==')')
            {
                cc+=1;
            }
            if(oc==cc)
            {
                result+= s.substr(start+1, i-start-1);
                start = i+1;
            }
        }
        return result;
    }
};
