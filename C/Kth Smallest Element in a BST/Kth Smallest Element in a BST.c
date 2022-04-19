// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

// Example 1:


// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:


// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
 

// Constraints:

// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
 

// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

//My way


// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findK(struct TreeNode *root, int *k){
    int value = -1;
    if(!root){
        return -1;
    }

    value = findK(root->left, k);

    if(!*k)
        return value;

    if(!--(*k)){
        return root->val;
    }

    value = findK(root->right, k);

    if(!*k)
        return value;

    return -1;
}

int kthSmallest(struct TreeNode* root, int k){
    return findK(root, &k);
}