// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */

//My way

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL){
        return list2;
    } else if(list2 == NULL){
        return list1;
    }

    struct ListNode *head, *curr;
    if(list1->val > list2->val){
        head = list2;
        list2 = list2->next;
    } else {
        head = list1;
        list1 = list1->next;
    }
    curr = head;
    while(list1 != NULL && list2 != NULL){
        if(list1->val > list2->val){
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
        } else {
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
        }
    }
    if(list1 == NULL){
        curr->next = list2;
        return head;
    }
    curr->next = list1;
    return head;
}