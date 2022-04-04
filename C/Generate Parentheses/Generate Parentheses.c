// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

//My way
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void generate(char ***ans, int left, int right, int n, char *temp, int tempIndex, int *returnSize){
    if(tempIndex == 2*n){
        temp[tempIndex] = '\0';
        char *new = (char*)malloc(sizeof(char) * 2 * n +1);
        memcpy(new, temp, sizeof(char) * 2 * n + 1);
        (*ans)[(*returnSize)++] = new;
    }
    if(left < n){
        temp[tempIndex] = '(';
        generate(ans,left+1,right,n,temp,tempIndex+1,returnSize);
    }
    if(right < left){
        temp[tempIndex] = ')';
        generate(ans,left,right+1,n,temp,tempIndex+1,returnSize);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char **ans = (char**)malloc(sizeof(char*) * 2000);
    char *temp = (char*)calloc(n*2+1,sizeof(char));
    int ansIndex = 0, tempIndex = 0, left = 0, right = 0;
    *returnSize = 0;
    generate(&ans, left, right, n, temp, tempIndex, returnSize);
    return ans;
}