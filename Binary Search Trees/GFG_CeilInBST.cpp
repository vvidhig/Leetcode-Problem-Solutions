int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    if(root->data==input) return root->data;
    
    if(root->data < input){
        return findCeil(root->right, input);
    }
    
    if(root->data > input){
        int maxi=root->data;
        int ans=findCeil(root->left, input);
        if(ans!=-1){
            return min(maxi, ans);
        }
        if(ans==-1){
            return maxi;
        }
    }
}
