// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Implement KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 

// Example 1:

// Input
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]

// Explanation
// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3);   // return 4
// kthLargest.add(5);   // return 5
// kthLargest.add(10);  // return 5
// kthLargest.add(9);   // return 8
// kthLargest.add(4);   // return 8
 

// Constraints:

// 1 <= k <= 104
// 0 <= nums.length <= 104
// -104 <= nums[i] <= 104
// -104 <= val <= 104
// At most 104 calls will be made to add.
// It is guaranteed that there will be at least k elements in the array when you search for the kth element.

//My way
typedef struct Array {
    int val;
    int k;
    struct Array *next;
    struct Array *pre;
} KthLargest;

// void print(KthLargest *head){
//     printf("here is start print\n");
//     for(;head != NULL; head = head->next){
//         printf("%d\n",head->val);
//     }
// }

KthLargest* add(KthLargest *head, int val, int K){
    if(head->val == -10001){
        head->val = val;
        return head;
    }
    KthLargest *curr = head;
    KthLargest *temp = (KthLargest*)malloc(sizeof(KthLargest) * 1);
    temp->val = val;
    temp->k = K;
    if(curr->val <= temp->val){
        temp->pre = NULL;
        temp->next = curr;
        curr->pre = temp;
        curr = temp;
        return curr;
    }else{
        while(curr->val > temp->val && curr->next != NULL){
            curr = curr->next;
        }
        if(curr->next == NULL && curr->val > temp->val){
            curr->next = temp;
            temp->pre = curr;
            temp->next = NULL;
            temp = NULL;
            free(temp);
            return head;
        }
        temp->pre = curr->pre;
        curr->pre->next = temp;
        temp->next = curr;
        curr->pre = temp;
        temp = NULL;
        free(temp);
    }
    return head;
}

KthLargest* kthLargestCreate(int K, int* nums, int numsSize) {
    KthLargest *head = (KthLargest*)malloc(sizeof(KthLargest) * 1), *precurr, *curr;
    if(numsSize > 0){
        head->val = nums[0];
    }else{
        head->val = -10001;
    }
    head->k = K;
    head->next = NULL;
    head->pre = NULL;
    for(int i = 1 ; i < numsSize; i++){
        // printf("here start %d add\tvalue:%d\n",i,nums[i]);
        head = add(head, nums[i], K);
        // printf("%d\n",head->val);
    }
    // print(head);
    return head;
}

int kthLargestAdd(KthLargest* obj, int val) {
    while(obj->pre != NULL){
        obj = obj->pre;
    }
    obj = add(obj, val, obj->k);
    int K = obj->k;
    // printf("%d\n",K);
    for(int i = 0; i < K-1; i++){
        obj = obj->next;
    }
    return obj->val;
}

void kthLargestFree(KthLargest* obj) {
    while(obj->pre != NULL){
        obj = obj->pre;
    }
    KthLargest *pre = obj;
    while(obj != NULL){
        obj = obj->next;
        free(pre);
        pre = obj;
    }
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/

