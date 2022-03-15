// Given a string s of '(' , ')' and lowercase English characters.
// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
// Formally, a parentheses string is valid if and only if:
// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Input: s = "a)b(c)d"
// Output: "ab(c)d"
// Input: s = "))(("
// Output: ""

// Constraints:
//     1 <= s.length <= 105
//     s[i] is either'(' , ')', or lowercase English letter.

//My way
char * minRemoveToMakeValid(char * s){
    if(strchr(s,'(') == NULL && strchr(s,')') == NULL)
        return s;
    char* returnString = (char*)malloc(sizeof(char) * strlen(s));
    returnString = (char*)calloc(strlen(s),sizeof(char));
    int* stack = (int*)malloc(sizeof(int) * strlen(s));
    stack = (int*)calloc(strlen(s), sizeof(int));
    int top = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '('){
            stack[top] = i;
            top++;
        } else if(s[i] == ')'){
            if(top == 0){
                s[i] = '*';
            } else {
                top--;
            }
        }
    }
    while(top > 0){
        top--;
        s[stack[top]] = '*';
    }
    int j = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] != '*'){
            returnString[j] = s[i];
            j++;
        }
    }
    return returnString;
}