// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Input: head = [1,1,1,2,3]
// Output: [2,3]

// Constraints:
//     The number of nodes in the list is in the range [0, 300].
//     -100 <= Node.val <= 100
//     The list is guaranteed to be sorted in ascending order.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//My way (尚未精簡)
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    //確認頭
    while(1){    
        struct ListNode* preCurrent = head;
        struct ListNode* current = head->next;
        int isHeadDuplicate = 0;
        while(current){
            if(current->val == head->val){
                isHeadDuplicate = 1;
                preCurrent->next = current->next;
                free(current);
                current = preCurrent->next;
                continue;
            }
            preCurrent = current;
            current = current->next;
        }
        if(isHeadDuplicate){
            struct ListNode* remove = head;
            head = head->next;
            free(remove);
            if(head){
                continue;
            } else {
                return NULL;
            }
        } else {
            break;
        }
    }

    struct ListNode* preCurrent = head;
    struct ListNode* current = head->next;
    
    while(current){
        struct ListNode* preTarget = current;
        struct ListNode* target = preTarget->next;
        int isDuplicate = 0;
        while(target){
            if(current->val == target->val){
                isDuplicate = 1;
                preTarget->next = target->next;
                free(target);
                target = preTarget->next;
                continue;
            }
            preTarget = target;
            target = target->next;
        }
        if(isDuplicate){
            preCurrent->next = current->next;
            free(current);
            current = preCurrent->next;
            continue;
        }
        preCurrent = current;
        current = current->next;
    }
    if(head){
        return head;
    } else {
        return NULL;   
    }
}