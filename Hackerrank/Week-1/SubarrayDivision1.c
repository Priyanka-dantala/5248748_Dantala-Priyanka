int birthday(int s_count, int* s, int d, int m) {
    int ways=0;
    
    for(int i=0;i<=s_count-m;i++){
        int sum=0;
        
        for(int j=0;j<m;j++){
            sum+=s[i+j];
        }
        if(sum==d){
            ways++;
        }
    }
    return ways;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** s_temp = split_string(rtrim(readline()));

    int* s = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int s_item = parse_int(*(s_temp + i));

        *(s + i) = s_item;
    }

    char** first_multiple_input = split_string(rtrim(readline()));

    int d = parse_int(*(first_multiple_input + 0));

    int m = parse_int(*(first_multiple_input + 1));

    int result = birthday(n, s, d, m);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}
