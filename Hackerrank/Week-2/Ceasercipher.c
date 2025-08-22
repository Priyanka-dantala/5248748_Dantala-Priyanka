#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* caesarCipher(char* s, int k) {
    int len=strlen(s);
    k=k%26;
    
    char* result=(char*) malloc((len+1)*sizeof(char));
    for(int i=0;i<len;i++){
        char c=s[i];
        
        if(c>='a' && c<='z'){
            result[i]=((c - 'a' +k )%26)+ 'a';
            
        }else if(c>='A' && c<='Z'){
            result[i]=((c - 'A' + k)%26) + 'A';
            
        }else{
            result[i]=c;
        }
        
    }
    result[len]='\0';
    return result;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char* s = readline();

    int k = parse_int(ltrim(rtrim(readline())));

    char* result = caesarCipher(s, k);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}