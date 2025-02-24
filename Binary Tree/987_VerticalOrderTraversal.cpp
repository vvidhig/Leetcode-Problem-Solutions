/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0,0}});
        while(q.size()>0)
        {
            auto val = q.front();
            q.pop();
            TreeNode* node = val.first;
            int col = val.second.first;
            int row = val.second.second;
            mp[col][row].insert(node->val);
            if(node->left!=NULL)
            {
                q.push({node->left, {col-1, row+1}});
            }
            if(node->right!=NULL)
            {
                q.push({node->right, {col+1, row+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p : mp)
        {
            vector<int> column;
            for(auto r : p.second)
            {
                column.insert(column.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
};
