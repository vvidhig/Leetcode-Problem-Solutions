class Solution 
{
  private:
   void findPath(Node* root, vector<int>& path, vector<vector<int>>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        path.push_back(root->data);
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(path);
        }
        else
        {
            findPath(root->left, path, ans);
            findPath(root->right, path, ans);
        }
        path.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) 
    {
        vector<vector<int>> ans;
        vector<int> path;
        findPath(root, path, ans);
        return ans;
    }
};
