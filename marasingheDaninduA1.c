/************************marasingheDaninduA1.c**************
 Student Name: Danindu Marasinghe Email Id: dmarasin@uoguelph.ca
Due Date: Oct 7, 2020 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged any
and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared by
me specifically for this course.
********************************************************

*********************************************************
Compiling the program
The program should be compiled using the following flags: -Wall -std=c99
compiling:
gcc gcc -Wall -std=c99 marasingheDaninduA1.c

Running the Program
Running: ./a.out
*********************************************************

**********************
CIS 1300
D. M.
Oct 7/20
Task 1: Get input from user of either 24 hour format or 12 hour format. Then display an inputted time in both formats.
Task 2: Based on the time entered by the customer, the closest departure time is displayed using 12-hour format.
Task 3: Ask user if they want a hotel, and if so, give them the choices for a hotel and ask how long the stay is.
Task 4: Ask if user wants a ride to the hotel (if they're staying in one)
************************/
#include <stdio.h>  //used for printf and scanf
#include <string.h>
 
 int main(){
    int hour, min, format, isHotel, hotelChoice, daysInHotel, rideChoice;
    char meridian[3];
    double flightCost, hotelCost, rideCost;

    //initialize variables
    flightCost = 0;
    hotelCost = 0;
    rideCost = 0;

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
        printf("You entered %d%d:%d%d %s\n", (hour/10), (hour%10), (min/10), (min%10), meridian);
        //adjust 24 hour time output based on meridian
        if(meridian[0] == 'a'){
            printf("In 24 hour format, - you entered %d%d:%d%d\n", (hour/10), (hour%10), (min/10), (min%10));
        }
        else if(meridian[0] == 'p'){
            hour +=12;
            printf("In 24 hour format, - you entered %d%d:%d%d\n", ((hour/10)), (hour%10), (min/10), (min%10));
        }
        printf("---------------------------\n");
    }
    else if(format == 2){
        printf("Enter time in 24-hour format\n");
        printf("Enter a value between 0 and 24 for hour: ");
        scanf("%d", &hour);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &min);
        printf("\n\n---------------------------\n");
        printf("You entered %d%d:%d%d\n", (hour/10), (hour%10), (min/10), (min%10));
        //check if inputted hour was greater than 12 to determine meridian and convert to 12 hour
        if(hour >= 12){
            strcpy(meridian, "pm");
            hour -= 12;
        }
        else{
            strcpy(meridian, "am");
        }
        printf("In 12 hour format, - you entered %d%d:%d%d %s\n", (hour/10), (hour%10), (min/10), (min%10), meridian);
        printf("---------------------------\n");

        //if changed for pm, change back to 24 hour format
        if(meridian[0] == 'p'){
            hour += 12;
        }
    }
    //task 2
    //if given time is before 7:15am or after 5:15pm
    if ((hour < 7) || (hour == 7 && min <= 15) || (hour > 17) || (hour == 17 && min > 15)) {
        //closest departure time is 7:15am
        printf("Closest departure times is 7:15 a.m., arriving at 8:25 a.m.\n");
        flightCost = 231;
    }
    else if((hour < 8) || (hour == 8 && min <= 15)){
        printf("Closest departure times is 8:15 a.m., arriving at 9:25 a.m.\n");
        flightCost = 226;
    }
    else if((hour < 9) || (hour == 9 && min <= 15)){
        printf("Closest departure times is 9:15 a.m., arriving at 10:25 a.m.\n");
        flightCost = 226;
    }
    else if((hour < 10) || (hour == 10 && min <= 15)){
        printf("Closest departure times is 10:15 a.m., arriving at 11:25 a.m.\n");
        flightCost = 283;
    }
    else if((hour < 11) || (hour == 11 && min <= 15)){
        printf("Closest departure times is 11:15 a.m., arriving at 12:25 p.m.\n");
        flightCost = 283;
    }
    else if((hour < 15) || (hour == 15 && min <= 15)){
        printf("Closest departure times is 3:15 p.m., arriving at 4:25 p.m.\n");
        flightCost = 226;
    }
    else if((hour < 16) || (hour == 16 && min <= 15)){
        printf("Closest departure times is 4:15 p.m., arriving at 5:25 p.m.\n");
        flightCost = 226;
    }
    else if((hour < 17) || (hour == 17 && min <= 15)){
        printf("Closest departure times is 5:15 p.m., arriving at 6:25 p.m.\n");
        flightCost = 226;
    }

    //task 3
    printf("Would you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
    scanf("%d", &isHotel);
    //if they want a hotel, display hotel choices and get their choices
    if(isHotel==1){
        printf("\n\nThere are 3 hotels:\n1. Marriott: $248\n2. Sheraton: $90\n3. Double Tree: $128\n\n");
        printf("Your choice:");
        scanf("%d", &hotelChoice);
        //ask how many days the user wants to stay
        printf("How many days in Montreal?");
        scanf("%d", &daysInHotel);
        //calculate hotel cost based on choice of hotel and days in montreal
        if(hotelChoice == 1){
            //marriott hotel
            hotelCost = 248 * daysInHotel;
        }
        else if(hotelChoice == 2){
            //sheraton hotel
            hotelCost = 90 * daysInHotel;
        }
        else if(hotelChoice == 3){
            //Double tree hotel
            hotelCost = 128 * daysInHotel;
        }
        //task 4
        //ask if user wants a ride to hotel
        printf("Would you like a ride from airport to hotel? - enter 0 for no; 1 for yes ");
        scanf("%d", &rideChoice);
        //if user wants a ride, calculate ride cost
        if(rideChoice == 1){
            //calculate ride cost based on choice of hotel
            switch (hotelChoice)
            {
            case 1: //mariott
                rideCost = 0;
                break;
            case 2: //sheraton
                rideCost = 25;
                break;
            case 3: //sheraton
                rideCost = 20;
                break;            
            default: //invalid value
                break;
            }
        }
    }

    //test output
    printf("Hotel Choice: %d\nHotel cost: %.2lf\nRide cost: %.2lf", hotelChoice, hotelCost, rideCost);

    return 0;
 }