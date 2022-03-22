// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.

//My way
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 1){
        return strs[0];
    }
    for(int i = 0; i < strsSize-1; i++){
        int len = 0;
        if(strlen(strs[i]) > strlen(strs[i+1])){
            len = strlen(strs[i+1]);
        } else {
            len = strlen(strs[i]);
        }
        if(len == 0){
            strs[i+1][0]='\0';
            continue;
        }
        for(int j = 0; j < len; j++){
            if(strs[i+1][j] != strs[i][j]){
                strs[i+1][j] = '\0';
                break;
            }
        }
        if(strstr(strs[i+1],strs[i]) != NULL)
            strs[i+1][len] = '\0';
    }
    return strs[strsSize-1];
}