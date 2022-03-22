// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

// Return a list of integers representing the size of these parts.

 

// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
// Example 2:

// Input: s = "eccbbbbdec"
// Output: [10]
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * string, int* returnSize){
    int lettersEndIndex[26];
    for(int i = 0; i < 26; i++){
        lettersEndIndex[i] = -1;
    }
    for(int i = 0; i < strlen(string); i++){
        if(lettersEndIndex[string[i]-'a'] < (i+1)){
            lettersEndIndex[string[i]-'a'] = (i+1);
        }
    }
    
    int *subStringLen = (int*)malloc(sizeof(int) * 500);
    subStringLen = (int*)calloc(500, sizeof(int));

    int subStringCnt = 0;
    for(int i = 0; i < strlen(string); i++){
        if(i+1 == lettersEndIndex[string[i]-'a']){
            if(subStringCnt == 0){
                subStringLen[subStringCnt] = 1;
            } else {
                subStringLen[subStringCnt] = subStringLen[subStringCnt-1]+1;
            }
            subStringCnt++;
            continue;
        }
        subStringLen[subStringCnt] = lettersEndIndex[string[i]-'a'];
        for(int j = i; j < subStringLen[subStringCnt]; j++){
            if(lettersEndIndex[string[j] - 'a'] > subStringLen[subStringCnt]){
                subStringLen[subStringCnt] = lettersEndIndex[string[j] - 'a'];
            }
        }
        i = subStringLen[subStringCnt]-1;
        subStringCnt++;
    }

    subStringLen = (int*)realloc(subStringLen,sizeof(int)*subStringCnt);

    for(int i = subStringCnt-1; i > 0; i--){
        subStringLen[i] -= subStringLen[i-1];
    }

    *returnSize = subStringCnt;
    return subStringLen;
}