class Solution {
    private:
    Node* buildParent(Node* root, unordered_map<Node*, Node*>& parent, int target)
    {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = NULL;
        while(!q.empty())
        {
            Node* node = q.front();
            if(node->data == target)
            {
                targetNode = node;
            }
            q.pop();
            if(node->left)
            {
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right)
            {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        return targetNode;
    }
    public:
    int minTime(Node* root, int target) 
    {
        if(root==NULL)
        {
            return 0;
        }
        unordered_map<Node*, Node*> parent;
        Node* targetNode = buildParent(root, parent, target);
        unordered_map<Node*, bool> visited;
        visited[targetNode] = true;
        queue<pair<Node*, int>> q;
        int t;
        q.push({targetNode, 0});
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i<size; i++)
            {
                Node* node = q.front().first;
                t = q.front().second;
                q.pop();
                if(node->left != NULL && visited[node->left]==false)
                {
                    q.push({node->left, t+1});
                    visited[node->left] = true;
                }
                if(node->right != NULL && visited[node->right]==false)
                {
                    q.push({node->right, t+1});
                    visited[node->right] = true;
                }
                if (parent.find(node) != parent.end() && !visited[parent[node]])
                {
                    q.push({parent[node], t+1});
                    visited[parent[node]] = true;
                }
            }
        }
        return t;
    }
};
