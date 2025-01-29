class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,-1);
        for(int i = 0; i<s.length(); i++)
        {
            lastIndex[s[i]-'a'] = i;
        }
        vector<bool> visited(26, false);
        stack<char> st;
        string res = "";
        for(int i = 0; i<s.length(); i++)
        {
            if(visited[s[i]-'a'])
            {
                continue;
            }
            while(!st.empty() && st.top() > s[i] && i<lastIndex[st.top()-'a'])
            {
                visited[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
