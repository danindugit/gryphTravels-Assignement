#include <stdio.h>

/*
 * Name: Assignment.c
 * Author: Danindu Marasinghe
 * Function: 
 *  Task 1: Get input from user of either 24 hour format or 12 hour format. Then display an inputted time 
 *          in both formats.
 */
 
 int main(){
    int hours, min, format;
    //char[2] meridian;

    //task 1
    //prompt for format until valid entry
    printf("Would you like to enter a time in 12-hour format (enter 1) or 24-hour format (enter 2)?");
    scanf("%d", &format);   

    //prompt for time based on format choice
    if(format == 1){
         printf("Enter time in 12-hour format\n");
    }
    else if(format == 2){
        printf("Enter time in 24-hour format\n");
    }

    return 0;
 }