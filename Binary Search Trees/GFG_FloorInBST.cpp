class Solution{

public:
    int floor(Node* root, int x) 
    {
        if(root == NULL)
        {
            return -1;
        }
        if(root->data == x)
        {
            return root->data;
        }
        if(root->data > x)
        {
            return floor(root->left, x);
        }
        if(root->data < x)
        {
            int min = root->data;
            int ans = floor(root->right, x);
            if(ans != -1)
            {
                return max(min, ans);
            }
            if(ans == -1)
            {
                return min;
            }
        }
    }
};
