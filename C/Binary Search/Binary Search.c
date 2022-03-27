// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
 

// Constraints:

// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.

//My way
int search(int* nums, int numsSize, int target){
    int min = 0, max = numsSize-1;
    while(min != max && min < max){
        if(min == 0 && nums[min] > target || max == numsSize-1 && nums[max] < target){
            return -1;
        }
        if(nums[(min+max)/2] > target){
            max = (min+max) / 2 - 1;
        } else if(nums[(min+max)/2] < target){
            min = (min+max) / 2 + 1;
        } else {
            return (min+max)/2;
        }
    }
    if(nums[min] == target){
        return min;
    } else if(nums[max] == target){
        return max;
    }
    return -1;
}