// // Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

// // Return true if there is a 132 pattern in nums, otherwise, return false.

 

// // Example 1:

// // Input: nums = [1,2,3,4]
// // Output: false
// // Explanation: There is no 132 pattern in the sequence.
// // Example 2:

// // Input: nums = [3,1,4,2]
// // Output: true
// // Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
// // Example 3:

// // Input: nums = [-1,3,2,0]
// // Output: true
// // Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

// // Constraints:

// // n == nums.length
// // 1 <= n <= 2 * 105
// // -109 <= nums[i] <= 109

// //My way 

// bool find132pattern(int* nums, int numsSize){
//     int *stack = (int*)malloc(sizeof(int) * 3);
//     int *index = (int*)malloc(sizeof(int) * numsSize);
//     int top = 0, min = 1000000001;
//     // memset(stack, 0, sizeof(int) * 3);
//     stack[0] = 1000000001; stack[1] = -1000000001; stack[2] = 0;
//     memset(index, 0, sizeof(int) * numsSize);
//     for(int i = 0; i < numsSize; i++){
//         if(nums[i] < stack[0] && top < 2){
//             stack[0] = nums[i];
//             min = nums[i];
//             top = 1;
//         }else if(nums[i] > stack[0] && nums[i] > stack[1]){
//             stack[1] = nums[i];
//             top = 2;
//         }else if(nums[i] < stack[0] && top == 2 && min > nums[i]){
//             index[i] = 1;
//             // if(find132pattern(&nums[i], numsSize-i)){
//             //     return true;
//             // }
//             min = nums[i];
//         }else if(nums[i] > stack[0] && nums[i] < stack[1]){
//             return true;
//         }
//     }
//     for(int i = numsSize-1; i > 0; i--){
//         if(index[i]){
//             top = 1;
//             stack[0] = nums[i]; stack[1] = -1000000001; stack[2] = 0;
//             for(int j = i; j < numsSize; j++){
//                 if(nums[j] < stack[0] && top < 2){
//                     stack[0] = nums[j];
//                     top = 1;
//                 }else if(nums[j] > stack[1]){
//                     stack[1] = nums[j];
//                     top = 2;
//                 }else if(nums[j] > stack[0] && nums[j] < stack[1]){
//                     return true;
//                 }
//             }
//             // printf("stack: %d %d %d\n",stack[0], stack[1], stack[2]);
//         }
//     }
//     return false;
// }

//Better way
#define MIN_INPUT -1000000001
#define MAX_INPUT 1000000001

bool find132pattern(int* nums, int numsSize){
    int *stack = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        stack[i] = MAX_INPUT;
    }
    int thirdElement = MIN_INPUT, top = -1;
    for(int i = numsSize-1; i >= 0; i--){
        if(nums[i] < thirdElement){
            return true;
        }else if(top == -1){
            stack[++top] = nums[i];
        }else if(nums[i] < stack[top]){
            stack[++top] = nums[i];
        }else if(nums[i] > stack[top]){
            while(top >= 0 && nums[i] > stack[top]){
                thirdElement = stack[top];
                stack[top] = MAX_INPUT;
                top--;
            }
            stack[++top] = nums[i];
        }
    }
    return false;
}