/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) 
    {
        if(root == NULL)
        {
            return "";
        }
        queue<TreeNode*> q;
        string data = "";
        q.push(root);
        while(q.size()>0)
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL)
            {
                data += "#,";
            }
            else
            {
                data += to_string(temp->val) + ",";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return data;
    }

    TreeNode* deserialize(string data) 
    {
        if(data.length()==0)
        {
            return NULL;
        }
        string rootVal = "";
        int i=0, n = data.length();
        while(i<n && data[i]!=',')
        {
            rootVal += data[i++];
        }
        i++;
        TreeNode* root = new TreeNode(stoi(rootVal));
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0)
        {
            TreeNode* temp = q.front();
            q.pop();
            if(i<n)
            {
                string leftVal = "";
                while(i<n && data[i] !=',')
                {
                    leftVal += data[i++];
                }
                i++;
                if(leftVal != "#")
                {
                    TreeNode* left = new TreeNode(stoi(leftVal));
                    temp->left = left;
                    q.push(left);
                }
            }
            if(i<n)
            {
                string rightVal = "";
                while(i<n && data[i] !=',')
                {
                    rightVal += data[i++];
                }
                i++;
                if(rightVal != "#")
                {
                    TreeNode* right = new TreeNode(stoi(rightVal));
                    temp->right = right;
                    q.push(right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
