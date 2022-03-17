// Given a balanced parentheses string s, return the score of the string.
// The score of a balanced parentheses string is based on the following rule:
//     "()" has score 1. AB has score A + B, where A and B are balanced parentheses strings.
//     (A) has score 2 * A, where A is a balanced parentheses string.
 
// Input: s = "()"
// Output: 1
// Input: s = "(())"
// Output: 2
// Input: s = "()()"
// Output: 2

// Constraints:
//     2 <= s.length <= 50
//     s consists of only '(' and ')'.
//     s is a balanced parentheses string.
int scoreOfParentheses(char * s){
    int left = 0, tot = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '('){
            left++;
        } else {
            tot += 1 << (left-1);
            while(s[i] == ')'){
                i++;
                left--;
            }
            i--;
        }
    }
    return tot;
}