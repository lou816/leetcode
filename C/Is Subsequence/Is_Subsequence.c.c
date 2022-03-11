// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Input: s = "axc", t = "ahbgdc"
// Output: false

// Constraints:
//     0 <= s.length <= 100
//     0 <= t.length <= 104
//     s and t consist only of lowercase English letters.

//My way(尚未精簡)
bool isSubsequence(char * s, char * t){
    for(; isalpha(*s) != 0; s++){
        if(strchr(t, *s) == NULL)
            break;
        t = strchr(t, *s);
        t++;
    }
    if(isalpha(*s)){
        return false;
    } else {
        return true;
    }
}