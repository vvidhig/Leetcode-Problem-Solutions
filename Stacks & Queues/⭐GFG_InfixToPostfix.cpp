//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int precedence(char ch)
    {
        if(ch=='^')
            return 3;
        if(ch=='*' || ch=='/')
            return 2;
        if(ch=='+' || ch=='-')
            return 1;
        else
            return -1;
    }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        // Your code here
        string result = "";
        stack<char> st;
        
        for(int i = 0; i<s.length(); i++)
        {
            char ch = s[i];
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
            {
                result += ch;
            }
            else if(ch=='(')
            {
                st.push(ch);
            }
            else if(ch==')')
            {
                while(st.top()!='(')
                {
                    result+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && (precedence(ch)<=precedence(st.top())))
                {
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }
        return result;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
