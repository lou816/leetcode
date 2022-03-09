// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };

bool hasCycle(struct ListNode *head) {
    if(head == NULL){
        return false;
    }
    struct ListNode *preCurrent = head;
    for(struct ListNode *current = head->next;current != NULL; current = current->next){
        if(current == preCurrent)
            return true;      
        if(current->val == -10001)
            return true;
        preCurrent->val = -10001;
        current->val = -10001;
        preCurrent = current;
    }
    return false; if(head == NULL) return false;
}