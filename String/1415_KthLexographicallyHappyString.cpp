class Solution {
private:
    string s;
    string space = "abc";
    vector<string> res;
    void solve(int n)
    {
        if(s.length()==n)
        {
            res.push_back(s);
            return;
        }
        else
        {
            for(char ch:space)
            {
                if(s.empty() || ch != s.back())
                {
                    s.push_back(ch);
                    solve(n);
                    s.pop_back();
                }
            }
        }
    }
public:
    string getHappyString(int n, int k) 
    {
        solve(n);
        if(k>res.size())
        {
            return "";
        }
        return res[k-1];
    }
};
