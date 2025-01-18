class Solution {
public:
    int beauty(vector<int> freq)
    {
        int mf = INT_MIN;
        int lf = INT_MAX;
        for(int i = 0; i<freq.size(); i++)
        {
            if(freq[i]>mf)
            {
                mf = freq[i];
            }
            if(freq[i]<lf && freq[i]>0)
            {
                lf = freq[i];
            }
        }
        return mf-lf;
    }
    int beautySum(string s) {
        int n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            vector<int> freq(26,0);
            for(int j = i; j < n; j++)
            {
                freq[s[j]-'a']+=1;
                res += beauty(freq);
            }
        }
        return res;
    }
};
