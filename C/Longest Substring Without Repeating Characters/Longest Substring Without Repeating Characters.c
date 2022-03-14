// Given a string s, find the length of the longest substring without repeating characters.
// Input: s = "abcabcbb"
// Output: 3
// Input: s = "bbbbb"
// Output: 1
// Input: s = "pwwkew"
// Output: 3

// Constraints:
//     0 <= s.length <= 5 * 104
//     s consists of English letters, digits, symbols and spaces.

//My way
int lengthOfLongestSubstring(char * s){
    if(strlen(s) == 0){
        return 0;
    }
    int maxLen = 1;
    if(s[strlen(s)] == '\n'){
        s[strlen(s)] = '\0';
    }
    char *head = s, *tail = head+1;
    while(*s != '\0' && *tail != '\0'){
        int len = 1;
        int isDuplicate = 0;
        while(head != tail){
            if(*head == *tail){
                isDuplicate = 1;
                break;
            }
            head++;
            len++;
        }
        if(isDuplicate){
            s++;
            head = s; tail = head+1;
        } else {
            tail++;
            head = s;
        }
        if(len > maxLen){
            maxLen = len;
        }
    }
    return maxLen;
}