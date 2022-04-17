
//  * Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
//  */

int addBST(struct TreeNode *root, int sum){
    if(root->right != NULL)   {
        sum = addBST(root->right, sum);
    }
    root->val += sum;
    sum = root->val;
    if(root->left != NULL){
        sum = addBST(root->left, sum);
    }
    return sum;
}

struct TreeNode* convertBST(struct TreeNode* root){
    if(root == NULL){
        return root;
    }
    addBST(root, 0);
    return root;
}

