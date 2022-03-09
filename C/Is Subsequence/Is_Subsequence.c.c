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