void miniMaxSum(int arr_count, int* arr) {
    long total=0;
    int min=arr[0];
    int max=arr[0];
    
    for(int i=0;i<arr_count;i++){
        total+=arr[i];
        
        if(arr[i]< min){
            min=arr[i];
        }
        if(arr[i]> max){
            max=arr[i];
            
        }
    }
        printf("%ld %ld\n",total-max,total-min);
    

}