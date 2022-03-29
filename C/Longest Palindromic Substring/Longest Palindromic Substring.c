// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

//My way

char * longestPalindrome(char * s){
    if(strlen(s) == 1){
        return s;
    }
    char *returnString = (char*)malloc(sizeof(char)*strlen(s)+1);
    memset(returnString,'\0',sizeof(char) * (strlen(s)+1));
    char *start, *end, *mid, *tail = &s[strlen(s)-1];
    int max = 0;
    for(int i = 0; i < strlen(s); i++){
        printf("this is round %d\n",i);
        int isSame= 1, cnt = 1;
        mid = &s[i];
        start = mid;
        end = mid;
        if(i == 0){
            if(s[0] == s[1]){
                end++;
                cnt = 2;
            }
        } else if(i == strlen(s)-1){
            if(s[i] == s[i-1]){
                start--;
                cnt = 2;
            }
        } else {
            if(*(mid-1) == *mid && *(mid+1) != *mid){
                start = (mid-1);
                cnt++; isSame = 0;
            } else if(*(mid+1) == *mid && *(mid-1) != *mid){
                end = (mid+1);
                cnt++; isSame = 0;
            }
            while(start != s && end != tail){
                start--; end++;
                if(*start == *end){
                    cnt+=2;
                    if(*start != *mid){
                        isSame = 0;
                    }
                } else{
                    if(cnt%2 == 1 && isSame == 1){
                        if(*start == *mid){
                            end--;
                            cnt++;
                            continue;
                        } else if(*end == *mid){
                            start++;
                            cnt++;
                            continue;
                        }
                    }
                    start++; end--;
                    break;
                }
            }
            if(isSame == 1){
                if(start == s && end != tail){
                    if(*(end+1) == *mid){
                        end++;
                        cnt++;
                    }
                } else if(start != s && end == tail){
                    if(*(start-1) == *mid){
                        start--;
                        cnt++;
                    }
                } else {
                    if(start != s && end != tail){
                        if(*(end+1) == *mid){
                            end++;
                            cnt++;
                        } else if(*(start-1) == *mid){
                            start--;
                            cnt++;
                        }
                    }
                }
            }
        }

        if(cnt > max){
            max = cnt;
            strncpy(returnString, start, cnt);
            printf("%s\n",returnString);
        }
    }
    return returnString;
}

//Better way
//原本的方法考慮太多重複字元出現處理,更好的方法:計算重複文字再去找映射字串,因為重複字元不論單雙都可以映射
char* longestPalindrome(char* s) {
    char *start, *end;
    char *p = s, *subStart = s;
    int maxLen = 1;
    while(*p){
        start = p; end = p;
        
        while(*(end+1) && *(end+1) == *end){
            end++; // skip duplicates
        }
        p = end + 1;
        
        while(*(end + 1) && (start > s) && *(end + 1) == *(start - 1)){
            start--;
            end++;
        }
        if(end - start + 1 > maxLen){
            maxLen = end - start + 1;
            subStart = start;
        }
    }
    
    char *rst = (char *) calloc(maxLen + 1, sizeof(char));
    strncpy(rst, subStart, maxLen);
    return rst;
}