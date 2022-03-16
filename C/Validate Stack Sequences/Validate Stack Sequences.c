// Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

// Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// Output: true
// Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
// Output: false

// Constraints:
//     1 <= pushed.length <= 1000
//     0 <= pushed[i] <= 1000
//     All the elements of pushed are unique.
//     popped.length == pushed.length
//     popped is a permutation of pushed.

//My way
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    if(poppedSize > pushedSize){
        return false;
    }
    int* stack = (int*)malloc(sizeof(int)*(pushedSize+1));
    memset(stack,-1,sizeof(int)*(pushedSize+1));
    int top = 0, i = 0; 
    for(int index = 0; index < pushedSize; index++){
        stack[++top] = pushed[index];
        while(i<poppedSize){
            if(stack[top] == popped[i]){
                stack[top] = -1; top--; popped[i] = -1; i++;
            } else {
                break;
            }
        }
    }
    return i==poppedSize;
}