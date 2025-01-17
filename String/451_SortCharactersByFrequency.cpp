class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> m;
        for(int i = 0; i<n; i++)
        {
            m[s[i]]+=1;
        }
        string ans = "";
        while(m.size()>0)
        {
            int maximum = INT_MIN;
            char ch;
            for(auto x:m)
            {
                if(x.second>maximum)
                {
                    maximum = x.second;
                    ch = x.first;
                }
            }
            for(int i = 0; i<maximum; i++)
            {
                ans+=ch;
            }
            m.erase(ch);
        }
        return ans;
    }
};
