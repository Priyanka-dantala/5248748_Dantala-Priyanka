char* pangrams(char* s) {
    static char pangram[]="pangram";
    static char not_pangram[]="not pangram";

    int letters[26]={0};
    int i;
    
    for(i=0; s[i]!='\0';i++){
        if(isalpha(s[i])){
            char lower=tolower(s[i]);
            letters[lower-'a']=1;
            
        }
    }
    for(i=0;i<26;i++){
        if(letters[i]==0){
            return not_pangram;
        }
    }
    return pangram;

}
