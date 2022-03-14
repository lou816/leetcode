// Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
// In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

// The canonical path should have the following format:
//     The path starts with a single slash '/'.
//     Any two directories are separated by a single slash '/'.
//     The path does not end with a trailing '/'.
//     The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
//     Return the simplified canonical path.
// Input: path = "/home/"
// Output: "/home"
// Input: path = "/../"
// Output: "/"
// Input: path = "/home//foo/"
// Output: "/home/foo"
// Constraints:
//     1 <= path.length <= 3000
//     path consists of English letters, digits, period '.', slash '/' or '_'.
//     path is a valid absolute Unix path.

//My way
//目前沒解決部分: 遇到.. or . 為上一級資料夾/當前資料夾

char * simplifyPath(char * path){
    if(path[strlen(path)] == '\n'){
        path[strlen(path)] == '\0';
    }
    char * absolute_path = (char *)malloc(sizeof(char) * (strlen(path)+1));
    absolute_path = (char*)calloc(strlen(path)+1, sizeof(char));
    *absolute_path = '/';
    while(*path == '/')
        path++;

    char * end = path;
    char * start = absolute_path;

    while(*path != '\0'){
        while(*start != '\0')
            start++;
        printf("%s\n",absolute_path);
        if(strchr(path, '/')){
            end = strchr(path, '/');
            while(*end == '/'){
                *end = '\0';
                end++;
            }
        } else {
            if(strcmp(path,"..") == 0){
                start--;
                if(start != absolute_path){
                    start--;
                    while (*start != '/')                        
                        start--;
                    if(start != absolute_path){
                        *start = '\0';
                    } else if(start == absolute_path){
                        *(start+1) = '\0';
                    }
                }
            } else if(strcmp(path,".") == 0){
                start--;
                if(start != absolute_path){
                    *start = '\0';
                }
            } else{
                sprintf(start, "%s\0", path);
            }
            break;
        }

        if(strcmp(path,"..") == 0){
            start--;
            if(start != absolute_path){
                start--;
                while (*start != '/')                        
                    start--;
                if(*end == '\0' && start != absolute_path){
                    *start = '\0';
                } else {
                    *(start+1) = '\0';
                }
            }
        } else if(strcmp(path,".") == 0){
            if(*end == '\0'){
                start--;
                if(start != absolute_path){
                    *start = '\0';
                }
            }
        } else{
            if(*end == '\0'){
                sprintf(start,"%s\0",path);
                break;  
            } else {
                sprintf(start,"%s/",path);
            }
        } 
        path = end;
    }
    return absolute_path;
}
