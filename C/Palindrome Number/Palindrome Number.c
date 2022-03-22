// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward.

// For example, 121 is a palindrome while 123 is not.
 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:

// -231 <= x <= 231 - 1
 

// Follow up: Could you solve it without converting the integer to a string?

//My way
bool isPalindrome(int x){
    int size = 0;
    double X = 0;
    if(x > 0){
        size = 0;
        X = x;
    } else {
        size = 1;
        X = (double)x * (-1);
    }
    printf("%ld\n",X);
    while(X != 0){
        X /= 10;
        size++;
    }
    // printf("%d\n",size);
    if(size == 0 || size == 1){
        return true;
    }
    printf("%d\n",size);
    char *str = (char*)malloc(sizeof(char)*(size+1));
    str = (char*)calloc((size+1),sizeof(char));
    sprintf(str,"%d",x);
    printf("%s\n%d\n",str,size);
    for(int i = 0; i < size/2; i++){
        if(str[i] != str[size-1-i]){
            return false;
        }
    }       
    return true;
}