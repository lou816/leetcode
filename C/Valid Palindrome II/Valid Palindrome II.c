// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

//My way
bool isPalindrome(char *s,int left, int right){
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++; right--;
    }
    return true;
}
bool validPalindrome(char * s){
    int fault = 1;
    for(int i = 0, j = strlen(s)-1; i < strlen(s)/2; i++, j--){
        // printf("this round character is\nleft: %c\tright: %c\tfault: %d\n",s[i],s[j],fault);
        if(s[i] != s[j] && fault == 1){
            return (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1));
        } 
    }
    return true;
}
