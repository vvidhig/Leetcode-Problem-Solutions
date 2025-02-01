class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int maxfreq = 0;
        vector<int> freq(26, 0);
        int left = 0;
        for(int right = 0; right<s.size(); right+=1)
        {
            freq[s[right]-'A']+=1;
            maxfreq = max(maxfreq, freq[s[right]-'A']);
            while((right-left+1)-maxfreq>k)
            {
                freq[s[left]-'A']-=1;
                left+=1;
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
