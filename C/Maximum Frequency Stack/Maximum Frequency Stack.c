// Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

// Implement the FreqStack class:

// FreqStack() constructs an empty frequency stack.
// void push(int val) pushes an integer val onto the top of the stack.
// int pop() removes and returns the most frequent element in the stack.
// If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
 

// Example 1:

// Input
// ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
// [[], [5], [7], [5], [7], [4], [5], [], [], [], []]
// Output
// [null, null, null, null, null, null, null, 5, 7, 5, 4]

// Explanation
// FreqStack freqStack = new FreqStack();
// freqStack.push(5); // The stack is [5]
// freqStack.push(7); // The stack is [5,7]
// freqStack.push(5); // The stack is [5,7,5]
// freqStack.push(7); // The stack is [5,7,5,7]
// freqStack.push(4); // The stack is [5,7,5,7,4]
// freqStack.push(5); // The stack is [5,7,5,7,4,5]
// freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
// freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
// freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
// freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
 

// Constraints:

// 0 <= val <= 109
// At most 2 * 104 calls will be made to push and pop.
// It is guaranteed that there will be at least one element in the stack before calling pop.

//My way
typedef struct freqStack{
    int val;
    int freq;
    struct freqStack *next;
    struct freqStack *before;
} FreqStack;

FreqStack* freqStackCreate() {
    FreqStack *head = (FreqStack*)malloc(sizeof(FreqStack)*1);
    head->val = -1;
    head->freq = -1;
    head->next = NULL;
    head->before = NULL;
    return head;
}

void freqStackPush(FreqStack* curr, int val) {
    // FreqStack *check = curr, *check1 = curr, *check2 = curr;
    // printf("\nbefore:\n");
    // while(check1->next != NULL){
        // printf("%d\t%d-->",check1->val, check1->freq);
        // printf("%d-->", check1->val);
        // check1 = check1->next;
    // }
    // printf("%d-->NULL\n",check1->val);
    // while(check2->next != NULL){
        // printf("%d\t%d-->",check2->val, check2->freq);
        // printf("%d-->", check2->freq);
        // check2 = check2->next;
    // }
    // printf("%d-->NULL\n",check2->freq);

    if(curr->val == -1){
        curr->val = val;
        curr->freq = 1;
        return;
    }
    int newFreq = -1;
    while(curr->next != NULL){
        if(curr->val == val){
            curr->freq++;
            if(curr->freq > newFreq){
                newFreq = curr->freq;
            } else {
                curr->freq = newFreq;
            }
        }
        curr = curr -> next;
    }
    if(curr->val == val && newFreq != -1){
        curr->freq = newFreq;
    } else if(curr->val == val && newFreq == -1){
        curr->freq++;
        if(curr->freq > newFreq){
            newFreq = curr->freq;
        } else {
            curr->freq = newFreq;
        }
    }
    FreqStack *tmp = (FreqStack*)malloc(sizeof(FreqStack)*1);
    curr->next = tmp;
    tmp->before = curr;
    tmp->next = NULL; 
    tmp->val = val;
    if(newFreq == -1){
        tmp->freq = 1;
    } else {
        tmp->freq = newFreq;
    }
    
    //check
    // printf("after:\n");
    // while(check->next != NULL){
        // printf("%d\t%d-->",check->val, check->freq);
        // printf("%d-->", check->val);
        // check = check->next;
    // }
    // printf("%d-->NULL\n\n",check->val);
}

int freqStackPop(FreqStack* curr) {
    int target = -1, freq = -1;
    if(curr->before == NULL && curr->next == NULL){
        target = curr->val;
        curr->val = -1;
        curr->freq = -1;
        return target;
    }
    // FreqStack *check = curr, *check1 = curr, *check2 = curr;
    // printf("\nbefore:\n");
    // while(check1->next != NULL){
        // printf("%d\t%d-->",check1->val, check1->freq);
        // printf("%d-->", check1->val);
        // check1 = check1->next;
    // }
    // printf("%d-->NULL\n",check1->val);
    // while(check2->next != NULL){
        // printf("%d\t%d-->",check2->val, check2->freq);
        // printf("%d-->", check2->freq);
        // check2 = check2->next;
    // }
    // printf("%d-->NULL\n",check2->freq);
    // printf("start finding\n");
    while(curr->next != NULL){
        // printf("%d\t%d\n",curr->val,curr->freq);
        if(curr->freq >= freq){
            target = curr->val;
            freq = curr->freq;
        }
        curr = curr->next;
    }
    // printf("%d\t%d\n",curr->val,curr->freq);
    if(curr->freq >= freq){
        target = curr->val;
        freq = curr->freq;
    }
    // printf("finish finding\n");
    while(curr->val != target){
        curr = curr->before;
    }

    //popping
    // printf("target is %d\n",target);
    if(curr->next == NULL){
        // printf("my back is null\n");
        FreqStack *preCurr = curr->before;
        preCurr->next = NULL;
        curr->before = NULL;
        free(curr);
        curr = preCurr;
    } else if(curr->before == NULL){
        // printf("my before is null\n");
        FreqStack *nextCurr = curr->next;
        nextCurr->before = NULL;
        free(curr);
        curr = nextCurr;
    } else {
        // printf("i'm in middle\n");
        FreqStack *preCurr = curr->before, *nextCurr = curr->next;
        // printf("%d\t%d\n",preCurr->val, nextCurr->val);
        preCurr->next = nextCurr;
        nextCurr->before = preCurr;
        curr->before = NULL; curr->next = NULL;
        free(curr);
        curr = preCurr;
        // printf("myPre:%d\tmyNext:%d\n",curr->before->val,curr->next->val);
    }
    
    while(curr->before != NULL){
        if(curr->val == target){
            curr->freq = freq-1;
        }
        curr = curr->before;
    }
    if(curr->val == target){
        curr->freq = freq-1;
    }
    //check
    // printf("after:\n");
    // while(check->next != NULL){
        // printf("%d\t%d-->",check->val, check->freq);
        // printf("%d-->", check->val);
        // check = check->next;
    // }
    // printf("%d-->NULL\n\n",check->val);

    return target;
}

void freqStackFree(FreqStack* curr) {
    FreqStack *nextCurr = curr->next;
    while(nextCurr){
        free(curr);
        curr = nextCurr;
        nextCurr = nextCurr->next;
    }
    free(curr);
}

/**
 * Your FreqStack struct will be instantiated and called as such:
 * FreqStack* obj = freqStackCreate();
 * freqStackPush(obj, val);
 
 * int param_2 = freqStackPop(obj);
 
 * freqStackFree(obj);
*/