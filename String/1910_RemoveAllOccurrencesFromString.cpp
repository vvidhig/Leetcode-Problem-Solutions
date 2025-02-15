class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        string result;
        int n = s.length();
        int m = part.length();
        for(int i = 0; i<s.length(); i++)
        {
            result.push_back(s[i]);
            if(result.size()>=m && result.substr(result.size()-m)==part)
            {
                result.erase(result.length()-m);
            }
        }
        return result;
    }
};
