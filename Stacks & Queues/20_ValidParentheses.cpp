class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0 || s.length()==1)
        {
            return false;
        }
        stack<char> st;
        for(int i = 0; i<s.length(); i+=1)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char top = st.top();
                if ((s[i] == ')' && top == '(') || (s[i] == '}' && top == '{') || (s[i] == ']' && top == '[')) 
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;
    }
};
