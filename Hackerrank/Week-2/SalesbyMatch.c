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
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, int ar_count, int* ar) {
    int pairs=0;
    int freq[101]={0};
    
    for(int i=0;i<n;i++){
        freq[ar[i]]++;
    
    }
    for(int i=1;i<=100;i++){
        pairs+=freq[i]/2;
    }
    return pairs;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** ar_temp = split_string(rtrim(readline()));

    int* ar = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int ar_item = parse_int(*(ar_temp + i));

        *(ar + i) = ar_item;
    }

    int result = sockMerchant(n, n, ar);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}
