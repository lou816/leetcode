// Given the head of a linked list, rotate the list to the right by k places.
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// Constraints:
//     The number of nodes in the list is in the range [0, 500].
//     -100 <= Node.val <= 100
//     0 <= k <= 2 * 109

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//My way
struct ListNode* getTail(struct ListNode* head){
    struct ListNode* tail = head;
    while(tail->next != head && tail->next != NULL) tail = tail->next;
    return tail;
}

int getLength(struct ListNode* head){
    struct ListNode* tail = head;
    int cnt = 1;
    while(tail->next != NULL){
        tail = tail->next;
        cnt++;
    }
    return cnt;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head){
        return NULL;
    } else if(!head->next){
        return head;
    }
    k = k%getLength(head);
    struct ListNode* tail = getTail(head);
    for(int i = 0; i < k; i++){
        tail->next = head;
        head = tail;
        tail = getTail(head);
    }
    tail->next = NULL;
    return head;
}

//Better way
struct ListNode* getTail(struct ListNode* head){
    struct ListNode* tail = head;
    while(tail->next != head && tail->next != NULL) tail = tail->next;
    return tail;
}

int getLength(struct ListNode* head){
    struct ListNode* tail = head;
    int cnt = 1;
    while(tail->next != NULL){
        tail = tail->next;
        cnt++;
    }
    return cnt;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL||k==0) return head;
    k = k%getLength(head);
    struct ListNode* tail = getTail(head);
    for(int i = 0; i < k; i++){
        tail->next = head;
        head = tail;
        tail = getTail(head);
    }
    tail->next = NULL;
    return head;
}