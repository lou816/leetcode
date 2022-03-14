// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Input: s = "()"
// Output: true
// Input: s = "()[]{}"
// Output: true
// Input: s = "(]"
// Output: false
 
// Constraints:
//     1 <= s.length <= 104
//     s consists of parentheses only '()[]{}'.

//My way
bool isValid(char * s){
    if(s[strlen(s)] == '\n'){
        s[strlen(s)] == '\0';
    }
    if(strlen(s)%2 == 1){
        return false;
    }
    char *stack = (char*)malloc(sizeof(char) * (strlen(s)+1));
    stack = (char*)calloc((strlen(s)+1),sizeof(char));
    char *top = stack;
    while(*s != '\0'){
        if(*s == '(' || *s == '[' || *s == '{'){
            top++;
            *top = *s;
            s++;
            continue;
        } else {
            if(top == stack){
                return false;
            }
            switch(*s){
                case ']':
                    if(*top != '['){
                        return false;
                    }
                    break;
                case ')':
                    if(*top != '('){
                        return false;
                    }
                    break;
                case '}':
                    if(*top != '{'){
                        return false;
                    }
                    break;
                default:
                    return false;
                    break;
            }
            *top = '\0'; top--; s++;
        }
    }
    if(top == stack){
        return true;
    }
    return false;
}

//Better way
//用 assert 去診斷開陣列大小是否成功
bool isValid(char * s){
    char *stack = malloc(strlen(s));
    assert(stack);
    int top = 0;
    int i;
    char c, e;
    
    for (i = 0; i < strlen(s); i++) {
        c = s[i];
        if (c == ')') {
            if (top == 0)
                return false;
            e = stack[--top];
            if (e != '(')
                return false;
        } else if (c == '}') {
            if (top == 0)
                return false;
            e = stack[--top];
            if (e != '{')
                return false;
        } else if (c == ']') {
            if (top == 0)
                return false;
            e = stack[--top];
            if (e != '[')
                return false;
        } else {
            stack[top++] = c;
        }
    }
    
    return top == 0;
}