// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

 

// Example 1:

// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 0
// Example 3:

// Input: nums = [1]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 104
// -105 <= nums[i] <= 105
 

// Follow up: Can you solve it in O(n) time complexity?
//My way

int findUnsortedSubarray(int* nums, int numsSize){
    int left = 0, right = 0;
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] > nums[i+1]){
            left = i;
            break;
        }
    }
    for(int i = numsSize-1; i > 0; i--){
        if(nums[i] < nums[i-1]){
            right = i;
            break;
        }
    }
    int min = 100001, max = -100001;
    for(int i = left; i <= right; i++){
        if(nums[i] > max){
            max = nums[i];
        }
        if(nums[i] < min){
            min = nums[i];
        }
    }
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > min){
            left = i;
            break;
        }
    }
    for(int i = numsSize-1; i >= 0; i--){
        if(nums[i] < max){
            right = i;
            break;
        }
    }
    return left == 0 && right == 0 ? 0:right-left+1;
};