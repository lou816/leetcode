// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


//My way
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct frequency{
    /* data */
    int val;
    int cnt;
}Freq;

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int cmpFreq(const void *a, const void *b){
    Freq *A = (Freq*)a;
    Freq *B = (Freq*)b;
    return (B->cnt - A->cnt);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    *returnSize = k;
    int *result =(int*)malloc(sizeof(int) * k);
    memset(result, 0 , sizeof(int) * k);
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int size = nums[numsSize-1] - nums[0] + 1, start = nums[0];
    
    Freq arr[size];
    
    arr[0].val = nums[0];
    arr[0].cnt = 1;
    for(int i = 0, j = start; i < size; i++, j++){
        arr[i].val = j;
        arr[i].cnt = 0;
    }

    for(int i = 0; i < numsSize; i++){
        arr[nums[i]-start].cnt++;
    }

    qsort(arr, size, sizeof(arr[0]), cmpFreq);
    
    for(int i = 0; i < k; i++){
        result[i] = arr[i].val;
    }

    return result;
}