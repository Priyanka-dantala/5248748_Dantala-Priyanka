void plusMinus(int arr_count, int* arr) {
    int positivecount=0,negativecount=0,zeroes=0;
    
    for(int i=0;i<arr_count;i++){
        if(arr[i]>0)
            positivecount++;
        else if(arr[i]<0)
            negativecount++;
        else 
            zeroes++;
        
    }
        printf("%.6f\n",(float)positivecount/arr_count);
        printf("%.6f\n",(float)negativecount/arr_count);
        printf("%.6f\n",(float)zeroes/arr_count);
    
    

}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    plusMinus(n, arr);

    return 0;
}
