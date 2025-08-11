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
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'twoArrays' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 *  3. INTEGER_ARRAY B
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
 int compareAsc(const void*a,const void*b){
    int x=*(const int*)a;
    int y=*(const int*)b;
    if(x<y)return -1;
    if(x>y)return 1; 
    return 0;
 }
 int compareDesc(const void * a, const void * b){
    int x=*(const int*)a;
    int y=*(const int*)b;
    if(x>y)return -1;
    if(x<y)return 1; 
    return 0;
    
 }
char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    qsort(A,A_count,sizeof(int),compareAsc);
    qsort(B,B_count,sizeof(int),compareDesc);
    
    for(int i=0; i<A_count;i++){
        if(A[i]+B[i]<k){
            char* result=malloc(3 * sizeof(char));
            strcpy(result,"NO");
            return result;
        }
    }
    char* result=malloc(4*sizeof(char));
    strcpy(result,"YES");
    return result;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int q = parse_int(ltrim(rtrim(readline())));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));

        int n = parse_int(*(first_multiple_input + 0));

        int k = parse_int(*(first_multiple_input + 1));

        char** A_temp = split_string(rtrim(readline()));

        int* A = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            int A_item = parse_int(*(A_temp + i));

            *(A + i) = A_item;
        }

        char** B_temp = split_string(rtrim(readline()));

        int* B = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            int B_item = parse_int(*(B_temp + i));

            *(B + i) = B_item;
        }

        char* result = twoArrays(k, n, A, n, B);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}