// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

 

// Example 1:

// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
// Example 2:

// Input: nums = [0]
// Output: [0]
 

// Constraints:

// 1 <= nums.length <= 5000
// 0 <= nums[i] <= 5000

//My way

// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */

int cmp(const void *a, const void *b){
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    if(a1 % 2 == 1 && b1 % 2 == 0){
        return 1;
    }
    return 0;
}



int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    qsort((void*)nums, numsSize,sizeof(nums[0]), cmp);
    *returnSize = numsSize;
    return nums;
}