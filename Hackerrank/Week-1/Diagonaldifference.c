int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int LefttoRight=0;
    int RighttoLeft=0;
    
    for(int i=0; i<arr_rows;i++){
        LefttoRight+=arr[i][i];
        RighttoLeft+=arr[i][arr_columns-1-i];
        
    }
    return abs(LefttoRight-RighttoLeft);

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int** arr = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        *(arr + i) = malloc(n * (sizeof(int)));

        char** arr_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < n; j++) {
            int arr_item = parse_int(*(arr_item_temp + j));

            *(*(arr + i) + j) = arr_item;
        }
    }

    int result = diagonalDifference(n, n, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}