// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".
 

// Constraints:

// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.
 

// Follow up: Can you solve it in O(n) time and O(1) space?

//My way
bool backspaceCompare(char * s, char * t){
    int sIndex = strlen(s)-1, tIndex = strlen(t)-1;
    for(; sIndex >= 0 && tIndex >= 0; sIndex--, tIndex--){
        int sCnt = 0, tCnt = 0;
        while(sIndex >= 0 && s[sIndex] == '#'){
            sCnt++;
            sIndex--;
            while(sCnt > 0 && sIndex >= 0){
                if(s[sIndex] != '#'){
                    sCnt--;
                    sIndex--;
                }else{
                    sCnt++;
                    sIndex--;
                }
            }
        }
        while(tIndex >= 0 && t[tIndex] == '#'){
            tCnt++;
            tIndex--;
            while(tCnt > 0 && tIndex >= 0){
                if(t[tIndex] != '#'){
                    tCnt--;
                    tIndex--;
                }else{
                    tCnt++;
                    tIndex--;
                }
            }
        }
        if(sIndex < 0 || tIndex < 0){
            break;
        }
        if(s[sIndex] != t[tIndex]){
            return false;
        }
    }
    if(sIndex < 0 && tIndex < 0){
        return true;
    }else if(sIndex < 0 && tIndex >= 0){
        printf("s is over\n");
        while(tIndex >= 0){
            int cnt = 0;
            while(tIndex >= 0 && t[tIndex] == '#'){
                cnt++;
                tIndex--;
                while(cnt > 0 && tIndex >= 0){
                    if(t[tIndex] != '#'){
                        cnt--;
                        tIndex--;
                    }else{
                        cnt++;
                        tIndex--;
                    }
                }
            }
            if(tIndex < 0){
                return true;
            }
            if(t[tIndex] != '#'){
                return false;
            }
        }
    }else{
        printf("t is over\n");
        while(sIndex >= 0){
            int cnt = 0;
            while(sIndex >= 0 && s[sIndex] == '#'){
                cnt++;
                sIndex--;
                while(cnt > 0 && sIndex >= 0){
                    if(s[sIndex] != '#'){
                        cnt--;
                        sIndex--;
                    }else{
                        cnt++;
                        sIndex--;
                    }
                }
            }
            if(sIndex < 0){
                return true;
            }
            if(s[sIndex] != '#'){
                return false;
            }
        }
    }
    return true;
}