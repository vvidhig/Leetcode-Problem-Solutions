//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int precedence(char ch)
    {
        if(ch=='^')
        {
            return 3;
        }
        if(ch=='/' && ch=='*')
        {
            return 2;
        }
        if(ch=='+' && ch=='-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
  public:
    string preToInfix(string pre_exp) {
        string result = "";
        stack<string> st;
        for(int i = pre_exp.length()-1; i>=0; i--)
        {
            char ch = pre_exp[i];
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
            {
                string s = string(1, pre_exp[i]); 
                st.push(s);
            }
            else
            {
                string ch1 = st.top();
                st.pop();
                string ch2 = st.top();
                st.pop();
                result = '(' + ch1 + ch + ch2 + ')';
                st.push(result);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
