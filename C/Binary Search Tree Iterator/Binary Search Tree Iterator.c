// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

 

// Example 1:


// Input
// ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
// [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
// Output
// [null, 3, 7, true, 9, true, 15, true, 20, false]

// Explanation
// BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
// bSTIterator.next();    // return 3
// bSTIterator.next();    // return 7
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 9
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 15
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 20
// bSTIterator.hasNext(); // return False
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 0 <= Node.val <= 106
// At most 105 calls will be made to hasNext, and next.
 

// Follow up:

// Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?

//My way

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define NULL 0

typedef struct iterator{
    int val;
    struct iterator *next;
} BSTIterator;

static int move = 0;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    move = 0;
    BSTIterator *head = (BSTIterator*)malloc(sizeof(BSTIterator) * 1);
    head->next = NULL;
    head->val = -1;
    BSTIterator *iterator = head;
    struct TreeNode *curr = root;
    while(curr){
        if(!curr->left){
            BSTIterator *temp = (BSTIterator*)malloc(sizeof(BSTIterator) * 1);
            temp->val = curr->val;
            temp->next = NULL;
            iterator->next = temp;
            iterator = iterator->next;
            temp = NULL;
            curr = curr->right;
        }else{
            struct TreeNode *predecessor = curr->left;
            while(predecessor->right && predecessor->right != curr){
                predecessor = predecessor->right;
            }
            if(!predecessor->right){
                predecessor->right = curr;
                curr = curr->left;
            }else{
                predecessor->right = NULL;
                BSTIterator *temp = (BSTIterator*)malloc(sizeof(BSTIterator) * 1);
                temp->val = curr->val;
                temp->next = NULL;
                iterator->next = temp;
                iterator = iterator->next;
                temp = NULL;
                curr = curr->right;
            }
        }
    }
    return head;
}

int bSTIteratorNext(BSTIterator* obj) {
    move++;
    for(int i = 0; i < move; i++){
        obj = obj->next;
    }
    return obj->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    for(int i = 0; i < move; i++){
        obj = obj->next;
    }
    return obj->next == NULL ? false : true;
}

void bSTIteratorFree(BSTIterator* obj) {
    BSTIterator *preobj = obj;
    while(obj){
        obj = obj->next;
        free(preobj);
        preobj = obj;
    }
    free(preobj);
    return;
}
// ,"next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"
/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/