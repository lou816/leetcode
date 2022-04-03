// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Input: s = "bcabc"
// Output: "abc"
// Input: s = "cbacdcbc"
// Output: "acdb"
// Constraints:
//     1 <= s.length <= 104
//     s consists of lowercase English letters.
 
//My way
char * removeDuplicateLetters(char *string){
    int cntLetters[26];
    memset(cntLetters,0,sizeof(cntLetters));
    char *output = (char*)malloc(sizeof(char)*strlen(string));
    output = (char*)calloc(strlen(string),sizeof(output));
    for(int i = strlen(string)-1; i >= 0; i--){
        cntLetters[(string[i]-'a')]++;
        // printf("%d\n",lastIndexOfLetters[i]);
    }
    // for(int i = 0; i < 26; i++){
    //     printf("%d\n",cntLetters[i]);
    // }
    char *start = output;
    *start = 'z'+1;
    for(int i = 0; i < strlen(string); i++){
        if(*start == string[i]){
            cntLetters[*start-'a']--;
            if(cntLetters[*start-'a'] == 0){
                start++;
                *start = 'z'+1;
            }
            continue;
        }
        if(*start == 'z'+1 && cntLetters[string[i] - 'a'] > 0){
            *start = string[i];
            cntLetters[string[i] - 'a']--;
            continue;
        }
        if(cntLetters[string[i] - 'a'] == 1){
            if(*start > string[i] && cntLetters[*start-'a'] > 0){
                *start = string[i];
                cntLetters[string[i] - 'a']--;
            } else {
                while(*start != '\0'){
                    cntLetters[*start-'a'] = 0;
                    start++;
                }
                *start = string[i];
                cntLetters[*start-'a'] = 0;
            }
            start++;
            *start = 'z'+1;
        } else if(cntLetters[string[i] - 'a'] > 1 && *start > string[i]){
            if(cntLetters[*start - 'a'] > 0){
                *start = string[i];
                cntLetters[string[i] - 'a']--;
            } else {
                start++;
                *start = string[i];
                cntLetters[string[i] - 'a']--;
            }
            // } else {
                // while(*start != '\0'){
                //     cntLetters[*start-'a'] = 0;
                //     start++;
                // }
                // *start = string[i];
                // cntLetters[*start-'a'] = 0;
            // }
        } else if(string[i] > *start){
            cntLetters[string[i]-'a']--;
        } else{
            continue;
        }
    }
    if(*start == 'z'+1){
        *start = '\0';
    }
    return output;
}