int* countingSort(int arr_count, int* arr, int* result_count) {
    int* frequency=(int*)calloc(100,sizeof(int));
    
    for(int i=0;i<arr_count;i++){
        frequency[arr[i]]++;
    }
    *result_count=100;
    
    return frequency;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    int result_count;
    int* result = countingSort(n, arr, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}
