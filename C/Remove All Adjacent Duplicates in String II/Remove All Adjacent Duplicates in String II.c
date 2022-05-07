// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

// Example 1:

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.
// Example 2:

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"
// Example 3:

// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps"
 

// Constraints:

// 1 <= s.length <= 105
// 2 <= k <= 104
// s only contains lower case English letters.

//My way

char * removeDuplicates(char * s, int k){
    char *stack = (char*)malloc(sizeof(char) * strlen(s)+1);
    strncpy(stack, s, k-1);
    int top = k-1;
    for(int i = k-1; i < strlen(s); i++){
        for(; top < k-1; top++, i++){
            stack[top] = s[i];
        }
        int isDuplicate = 1;
        for(int j = 0; j < k-1; j++){
            if(stack[top-k+1+j] != s[i]){
                isDuplicate = 0;
                break;
            }
        }
        if(isDuplicate){
            top -= k-1;
        }else{
            stack[top++] = s[i];
        }
    }
    stack[top] = '\0';

    return stack;
}

//Better case
//use another array count duplicate times 

char* removeDuplicates(char *s, int k){
    int len = strlen(s);
    
    if(len < k)
        return s;
    
    char *stack = calloc(len + 1, sizeof(char));
    int count[len];
    memset(count, 0, len * sizeof(int));
    
    int top = 0;
    for(int i = 0; i < len; i++, top++){
        stack[top] = s[i];
        if(top == 0)
            count[top] = 1;
        else if(stack[top] == stack[top - 1]){
            count[top] = count[top - 1] + 1;
        }
        else{
            count[top] = 1;
        }
       
        if(count[top] == k)
            top -= k;

    }
    stack[top] = '\0';
    
    return stack;
}