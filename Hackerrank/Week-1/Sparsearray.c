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
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY strings
 *  2. STRING_ARRAY queries
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    int* results=malloc(queries_count * sizeof(int));
    *result_count=queries_count;
    
    for(int i=0;i<queries_count;i++){
        results[i]=0;
        for(int j=0;j<strings_count;j++){
            if(strcmp(queries[i],strings[j])==0){
                results[i]++;
            }
        }
    }
    return results;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int strings_count = parse_int(ltrim(rtrim(readline())));

    char** strings = malloc(strings_count * sizeof(char*));

    for (int i = 0; i < strings_count; i++) {
        char* strings_item = readline();

        *(strings + i) = strings_item;
    }

    int queries_count = parse_int(ltrim(rtrim(readline())));

    char** queries = malloc(queries_count * sizeof(char*));

    for (int i = 0; i < queries_count; i++) {
        char* queries_item = readline();

        *(queries + i) = queries_item;
    }

    int res_count;
    int* res = matchingStrings(strings_count, strings, queries_count, queries, &res_count);

    for (int i = 0; i < res_count; i++) {
        fprintf(fptr, "%d", *(res + i));

        if (i != res_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}
