class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int n = s.length();
        unordered_map<char, int> key = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        for(int i = 0; i<n; i++)
        {
            if(i<n-1 && key[s[i]]<key[s[i+1]])
            {
                num -= key[s[i]];
            }
            else
            {
                num += key[s[i]];
            }
        }
        return num;
    }
};
