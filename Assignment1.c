#include <stdio.h>
#include <string.h>

/**********************
CIS 1300
D. M.
Oct 7/20
Task 1: Get input from user of either 24 hour format or 12 hour format. Then display an inputted time in both formats.
************************/
 
 int main(){
    int hour, min, format;
    char meridian[3];

    //task 1
    //prompt for format until valid entry
    printf("Would you like to enter a time in 12-hour format (enter 1) or 24-hour format (enter 2)?");
    scanf("%d", &format);   

    //prompt for time based on format choice
    if(format == 1){
        printf("Enter time in 12-hour format\n\n");
        printf("Enter a value between 0 and 12 for hour: ");
        scanf("%d", &hour);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &min);
        printf("Enter a for am or p for pm: ");
        scanf("%s", meridian);
        //determine output merdian based on input
        if(meridian[0] == 'a'){
            strcpy(meridian, "am");
        }
        else if(meridian[0] == 'p'){
            strcpy(meridian, "pm");
        }
        printf("\n\n---------------------------\n");
        printf("You entered %d%d:%d%d $s\n", (hour/10), (hour%10), (min/10), (min%10), meridian);
        //adjust 24 hour time output based on meridian
        if(meridian[0] == 'a'){
            printf("In 24 hour format, - you entered %d%d:%d%d\n", (hour/10), (hour%10), (min/10), (min%10));
        }
        else if(meridian[0] == 'p'){
            printf("In 24 hour format, - you entered %d%d:%d%d\n", ((hour/10)+12), (hour%10), (min/10), (min%10));
        }
        printf("---------------------------\n");
    }
    else if(format == 2){
        printf("Enter time in 24-hour format\n");
        printf("Enter a value between 0 and 24 for hour: ");
        scanf("%d", &hour);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &min);
        //check if inputted hour was greater than 12 to determine meridian
        if(hour >= 12){
            strcpy(meridian, "pm");
        }
        else{
            strcpy(meridian, "am");
        }
        printf("\n\n---------------------------\n");
        printf("You entered %d%d:%d%d\n", (hour/10), (hour%10), (min/10), (min%10));
        printf("In 12 hour format, - you entered %d%d:%d%d %s", (hour/10), (hour%10), (min/10), (min%10), meridian);
        printf("---------------------------\n");
    }

    return 0;
 }