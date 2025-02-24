class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) 
    {
        queue<pair<Node*, pair<int, int>>> q;
        map<int, map<int, int>> mp;
        q.push({root, {0,0}});
        while(q.size()>0)
        {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            if(mp[col].find(row) == mp[col].end())
            {
                mp[col][row] = node->data;
            }
            if(node->left!=NULL)
            {
                q.push({node->left, {col-1, row+1}});
            }
            if(node->right!=NULL)
            {
                q.push({node->right, {col+1, row+1}});
            }
        }
        vector<int> ans;
        for(auto p:mp)
        {
            ans.push_back(p.second.begin()->second);
        }
        return ans;
    }
};
