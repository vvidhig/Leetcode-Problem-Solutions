class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for(int i = 1; i<num.size(); i+=1)
        {
            while(!st.empty() && num[i]<st.top() && k>0)
            {
                k--;
                st.pop();
            }
            st.push(num[i]);
            if(st.size()==1 && num[i]=='0')
            {
                st.pop();
            }
        }
        while(k>0 && !st.empty())
        {
            k--;
            st.pop();
        }
        string res = "";
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        if(res.length()==0)
        {
            return "0";
        }
        return res;
    }
};
