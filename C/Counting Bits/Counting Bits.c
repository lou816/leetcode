// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
// Input: n = 2
// Output: [0,1,1]
// Input: n = 5
// Output: [0,1,1,2,1,2]

// Constraints:
//     0 <= n <= 10^5
 

// Follow up:
//     It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
//     Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int *returnSize)
{
    n++;
    *returnSize = n;
    int* arr = (int*)malloc(sizeof(int)*n);
    arr[0] = 0;
    for(int i = 1; i < n; i++){
        printf("%d\t%d\n",i,(i&1));
        arr[i] = (i&1)? arr[i>>1]+1 : arr[i>>1];

    }
    return arr;
}