/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root->val > val){
        if(root->left == NULL)
            return NULL;
        return searchBST(root->left, val);
    }else if(root->val < val){
        if(root->right == NULL)
            return NULL;
        return searchBST(root->right, val);
    }else if(root->val == val){
        return root;
    }
    return NULL;
}