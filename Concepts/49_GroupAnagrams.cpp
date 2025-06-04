class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> ans;
        for(int i = 0; i<strs.size(); i++)
        {
            string word = strs[i];
            sort(word.begin(), word.end());
            ans[word].push_back(strs[i]);
        }
        for(auto& x : ans)
        {
            result.push_back(x.second);
        }
        return result;
    }
};
