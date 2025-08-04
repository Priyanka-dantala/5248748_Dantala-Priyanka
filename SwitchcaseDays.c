#include <stdio.h>

int main() {
    int day;
    int i;
    for(i=1;i<=7;i++){
        while(1){
            printf("Enter the number between 1 to 7: ");
            scanf("%d",&day);
            switch(day){
                case 1:printf("Monday");
                break;
                case 2:printf("Tuesday");
                break;
                case 3:printf("Wednesday");
                break;
                case 4:printf("Thursday");
                break;
                case 5:printf("Friday");
                break;
                case 6:printf("Saturday");
                break;
                case 7:printf("Sunday");
                break;
                default:printf("Enter correct number\n");
                continue;
            }
        break;
        }
        return 0;
        
    }
    
    
}