// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
    // val: an integer representing Node.val
    // random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

// Your code will only be given the head of the original linked list.

/**
 * Definition for a Node.
  struct Node {
      int val;
      struct Node *next;
      struct Node *random;
  };
*/

struct Node* createNewNode(struct Node* head){
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node)*1);
    newHead->next = NULL; newHead->val = -1; newHead->random = NULL;
    struct Node *temp, *curr = newHead;
    while(head){
        temp = (struct Node*)malloc(sizeof(struct Node)*1);
        curr->next = temp;
        temp->next = NULL;
        temp->random = NULL;
        temp->val = head->val;
        head = head->next; curr = temp; temp = NULL;
    }
    temp = newHead;
    newHead = newHead->next;
    free(temp);
    return newHead;
}
//My way
struct Node* copyRandomList(struct Node* head){
    if(head == NULL)
        return head;
	struct Node* newHead = createNewNode(head);
    struct Node* oldCur = head->next, *oldPreCur = head,*newCur = newHead;
    //先把 old link 跟 new link 一樣 index 的 node 連起來
    while (newCur){
        oldPreCur->next = newCur;
        newCur->random = oldPreCur;        
        if(oldCur == NULL){
            break;
        }
        oldPreCur = oldCur;
        oldCur = oldCur->next;
        newCur = newCur->next;
    }
    newCur = newHead;
    //把 new link 的random 導向正確的 node
    while (newCur){
        if(newCur->random->random != NULL){
            newCur->random = newCur->random->random->next;
        } else {
            newCur->random = NULL;
        }
        newCur = newCur->next;
    }
    return newHead;
}