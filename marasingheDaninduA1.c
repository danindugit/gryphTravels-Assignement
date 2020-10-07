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
Task 5: Calculate and display total cost before discounts and taxes
Task 6: Calculate discounted price
Task 7: Display net cost
E1: Loop billing 3 times and give user cheapest price option
************************/
#include <stdio.h>  //used for printf and scanf
#include <string.h>
 
 int main(){
    int hour, min, format, isHotel, hotelChoice, daysInHotel, rideChoice, dayOfBirth, sumBirthDigits;
    char meridian[3];
    double flightCost, hotelCost, rideCost, totalCost, option1Cost, option2Cost, option3Cost;

    //initialize variables
    daysInHotel = 0;
    flightCost = 0;
    hotelCost = 0;
    rideCost = 0;
    totalCost = 0;
    sumBirthDigits = 0;
    option1Cost = 0;
    option2Cost = 0;
    option3Cost = 0;

    //notify user that this billing process wil repeat 3 times
    printf("This will run for 3 transactions\n\n");

    //loop through billing process 3 times for each option
    for (int i = 0; i < 3; i++){
        //reset cost variables for next iteration
        daysInHotel = 0;
        flightCost = 0;
        hotelCost = 0;
        rideCost = 0;
        totalCost = 0;

        //task 1
        //prompt for format until valid entry
        printf("Would you like to enter a time in 12-hour format (enter 1) or 24-hour format (enter 2)? ");
        scanf("%d", &format);   

        //prompt for time based on format choice
        if(format == 1){
            printf("\nEnter time in 12-hour format\n\n");
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
            printf("---------------------------\n");
            printf("You entered %d%d:%d%d %s\n", (hour/10), (hour%10), (min/10), (min%10), meridian);
            //adjust 24 hour time output based on meridian
            if(meridian[0] == 'a'){
                if(hour == 12){
                    //if 12am, set hour to 0
                    hour = 0;
                }
                printf("In 24 hour format, - you entered %d%d:%d%d\n", (hour/10), (hour%10), (min/10), (min%10));
            }
            else if(meridian[0] == 'p'){
                //add 12 to the pm hour unless it was noon
                if(hour != 12){
                    hour +=12;
                }
                printf("In 24 hour format - you entered %d%d:%d%d\n", ((hour/10)), (hour%10), (min/10), (min%10));
            }
            printf("---------------------------\n");
        }
        else if(format == 2){
            printf("\nEnter time in 24-hour format\n");
            printf("\nEnter a value between 0 and 24 for hour: ");
            scanf("%d", &hour);
            printf("Enter a value between 0 and 60 for minutes: ");
            scanf("%d", &min);
            printf("---------------------------\n");
            printf("You entered %d%d:%d%d\n", (hour/10), (hour%10), (min/10), (min%10));
            //check if inputted hour was greater than 12 to determine meridian and convert to 12 hour
            if(hour >= 12){
                strcpy(meridian, "pm");
                //subtract 12 from the hour only if it wasnt noon
                if(hour > 12){
                    hour -= 12;
                }
            }
            else{
                strcpy(meridian, "am");
                //if hour was 0, set to 12 hor 12 hour format
                if(hour == 0){
                    hour = 12;
                }
            }
            printf("In 12 hour format - you entered %d%d:%d%d %s\n", (hour/10), (hour%10), (min/10), (min%10), meridian);
            printf("---------------------------\n");

            //if changed for pm, change back to 24 hour format, unless it was set to noon
            if(meridian[0] == 'p' && (hour != 12)){
                hour += 12;
            }
            //if 0 hour changed to 12, change back
            else if(hour == 12 && meridian[0] == 'a'){
                hour = 0;
            }
        }
        //task 2
        //if given time is from 0:00 to 6:59 or if it is from 07:00 to 07:44
        if ((hour >= 0 && hour < 7) || (hour == 7 && min <= 44)) {
            //closest departure time is 7:15am
            printf("Closest departure times is 7:15 a.m., arriving at 8:25 a.m.\n");
            flightCost = 231;
        }
        else if((hour < 8) || (hour == 8 && min <= 44)){
            printf("Closest departure times is 8:15 a.m., arriving at 9:25 a.m.\n");
            flightCost = 226;
        }
        else if((hour < 9) || (hour == 9 && min <= 44)){
            printf("Closest departure times is 9:15 a.m., arriving at 10:25 a.m.\n");
            flightCost = 226;
        }
        else if((hour < 10) || (hour == 10 && min <= 44)){
            printf("Closest departure times is 10:15 a.m., arriving at 11:25 a.m.\n");
            flightCost = 283;
        }
        else if((hour < 13) || (hour == 13 && min <= 14)){
            printf("Closest departure times is 11:15 a.m., arriving at 12:25 p.m.\n");
            flightCost = 283;
        }
        else if((hour < 15) || (hour == 15 && min <= 44)){
            printf("Closest departure times is 3:15 p.m., arriving at 4:25 p.m.\n");
            flightCost = 226;
        }
        else if((hour < 16) || (hour == 16 && min <= 44)){
            printf("Closest departure times is 4:15 p.m., arriving at 5:25 p.m.\n");
            flightCost = 226;
        }
        else if((hour < 23) || (hour == 23 && min <= 59)){
            printf("Closest departure times is 5:15 p.m., arriving at 6:25 p.m.\n");
            flightCost = 401;
        }

        //task 3
        printf("\nWould you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
        scanf("%d", &isHotel);
        //if they want a hotel, display hotel choices and get their choices
        if(isHotel==1){
            printf("\nThere are 3 hotels:\n1. Marriott: $248 per night\n2. Sheraton: $90 per night\n3. Double Tree: $128 per night\n\n");
            printf("Your choice?:");
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
            printf("\nWould you like a ride from airport to hotel? - enter 0 for no; 1 for yes ");
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

        //prompt for user DOB for task 6 discount 2
        printf("\nNow enter your day of birth to qualify for discount2: ");
        scanf("%d", &dayOfBirth);

        //task 5
        //display individual costs
        printf("\nYour total cost comes to:\n\nCost of closest departure flight: $ %.2lf\nCost of Hotel for %d days: $ %.2lf\nCost of Ride: $ %.2lf\n\n", flightCost, daysInHotel, hotelCost, rideCost);
        totalCost = flightCost + hotelCost + rideCost;  //calculate total cost before discounts and taxes
        printf("Total cost before tax: $ %.2lf\n\n", totalCost);

        //task 6
        //if subtotal cost was a multiple of 11
        if((int)totalCost % 11 == 0){
            //knock 5% off and notify user of the discount
            totalCost *= 0.95;
            printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
        }
        else{
            //notify if user didnt qualify for the discount1
            printf("Sorry - you missed out on 5%% discount because the total cost was not a multiple of 11\n");
        }
        //calculate sum of day of birth digits
        sumBirthDigits = (dayOfBirth/10) + (dayOfBirth%10);
        //if subtotal cost after discount 1 is a multiple of the sum of the digits of the user's day of birth
        if((int)totalCost % sumBirthDigits == 0){
            //knock 5% off and notify user of the discount
            totalCost *= 0.95;
            printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your day of birth :)\n");
        }
        else{
            //notify if user didnt qualify for the discount1
            printf("Sorry - you missed out on the additional 5%% discount because the total cost after discount1 was not a multiple of the sum of digits in your day of birth\n");
        }
        //display subtotal after discounts but before taxes
        printf("\nTotal cost after discounts 1 and 2: $ %.2lf\n\n", totalCost);

        //task 7
        //calculate and display net cost after taxes
        totalCost = totalCost * 1.13;
        printf("Finally, your total cost after taxes: $ %.2lf\n", totalCost);
        printf("--------------------------------------\n\n");

        //assign total cost to option cost variable based on which option the loop is running through
        if(i == 0){
            option1Cost = totalCost;
        }
        else if(i == 1){
            option2Cost = totalCost;
        }
        else if(i == 2){
            option3Cost = totalCost;
        }

    }//end for loop

    //compare option costs to get best option
    if(option1Cost <= option2Cost && option1Cost <= option3Cost){
        //option 1 is either cheapest or tied for cheapest
        printf("\n Option number 1 is the best option for you with a minimum cost = $ %.2lf\n", option1Cost);
    }
    else if(option2Cost <= option1Cost && option2Cost <= option3Cost){
        //option 2 is either cheapest or tied for cheapest
        printf("\n Option number 2 is the best option for you with a minimum cost = $ %.2lf\n", option2Cost);
    }
    else{
        //option 3 is either cheapest or tied for cheapest
        printf("\n Option number 3 is the best option for you with a minimum cost = $ %.2lf\n", option3Cost);
    }

    return 0;
 }