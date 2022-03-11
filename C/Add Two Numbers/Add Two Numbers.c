// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]

// Input: l1 = [0], l2 = [0]
// Output: [0]

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

//My way
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = l1, *precur, *cur = head, *temp;
    while(1){
        cur->val = l1->val + l2->val;
        if(!cur->next){
            l2 = l2->next;
            break;
        }
        precur = cur;
        cur = cur->next;
        if(precur->val >= 10){
            cur->val += 1;
            precur->val -= 10;
        }
        l1 = l1->next; l2 = l2->next;         
        if(!l2){
            break;
        }
    }
    if(cur->next == NULL){
        cur->next = l2;
    } 
    while(cur->val >= 10){
        cur->val -= 10;
        if(cur->next == NULL){
            temp = (struct ListNode*)malloc(sizeof(struct ListNode) * 1); temp->val = 0; temp->next = NULL;
            cur->next = temp;
            temp = NULL;
        }
        cur = cur->next;
        cur->val++;
    }
    return head;
}