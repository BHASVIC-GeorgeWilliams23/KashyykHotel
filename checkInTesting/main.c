#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int stayLength;
int guests;
int newspaper;
int i;
char surname[35];
int boardChoice;
int roomChoice;

void bookingIdGen()
{
    srand(time(NULL));


    int random_number = rand() % 9000 + 1000;

    char bookingid[100];
    snprintf(bookingid, sizeof(bookingid), "%s%d", surname, random_number);

    printf("Your Booking ID: %s\n", bookingid);

    return 0;
}

int guestCheck(int adults,int kids)
{
    int guests = (adults + kids);
    if (guests > 4){
        printf("\nmax number of guests is 4.");
        return 0;
    }
    if (guests < 1){
        printf("\nminimum number of guests is 1");
        return 0;
    }
    else{
        printf("\nyou have entered %d guests",guests);
        return 1;
    }

}

int checkIN()
{
    printf("Enter surname:");
    scanf("%34s",&surname);
    fflush(stdin);
    int day,month,year;
    printf("enter DOB (day month year):");
    scanf("%d%d%d", &day,&month,&year);
    fflush(stdin);
    int kids1,adults1;
    printf("\nEnter number of children (u16) that will be staying:");
    scanf("%d", &kids1);
    fflush(stdin);
    printf("\nEnter number of adults (16+) that will be staying:");
    scanf("%d", &adults1);
    fflush(stdin);
    int valid;
    valid = guestCheck(adults1, kids1);
    if (valid == 1){
        printf("\nValid number of guests\n");
    }
    if (valid != 1){
            printf("\ninvalid");
    }
    int newspaper;
    printf("\nWould you like a daily newspaper? \n1 for yes\n2 for no\n:");
    scanf("%d",&newspaper);
    switch(newspaper)
    {
        case 1: printf("you have chose the daily newspaper\n");
                newspaper = 1;
                fflush(stdin);

        case 2: printf("you do not want the daily newspaper\n");
                newspaper = 2;
                fflush(stdin);
    }
    printf("How many days do you plan to stay for?");
    scanf("%d",&stayLength);
    fflush(stdin);
    bookingIdGen();
    return 0;
}






void displayRoomRates() {
    printf("Room rates per room, per day:\n");
    printf("Room 1 & 2 = £100\n");
    printf("Room 3 = £85\n");
    printf("Room 4 & 5 = £75\n");
    printf("Room 6 = £50\n");
}

// Function to display board rates
void displayBoardRates() {
    printf("Board rates per person, per day:\n");
    printf("Full board = £20\n");
    printf("Half board = £15\n");
    printf("B&B = £5\n");
}

int Choice() {

    printf("Available rooms:\n");
    displayRoomRates();


    printf("\nEnter the room number you would like to book (1-6): ");
    scanf("%d", &roomChoice);


    if (roomChoice < 1 || roomChoice > 6) {
        printf("Invalid room choice. Please choose a room between 1 and 6.\n");
        return 1;
    }


    printf("\nBoard rates:\n");
    displayBoardRates();


    printf("\nEnter the board type you would like (1-3):\n");
    printf("1. Full board\n");
    printf("2. Half board\n");
    printf("3. B&B\n");
    printf("Enter your choice: ");
    scanf("%d", &boardChoice);


    if (boardChoice < 1 || boardChoice > 3) {
        printf("Invalid board choice. Please choose a board type between 1 and 3.\n");
        return 1; // Exit the program with an error code
    }


    int roomRate;
    switch (roomChoice) {
        case 1:
        case 2:
            roomRate = 100;
            break;
        case 3:
            roomRate = 85;
            break;
        case 4:
        case 5:
            roomRate = 75;
            break;
        case 6:
            roomRate = 50;
            break;
        default:

            return 1;
    }

    int boardRate;
    switch (boardChoice) {
        case 1:
            boardRate = 20;
            break;
        case 2:
            boardRate = 15;
            break;
        case 3:
            boardRate = 5;
            break;
        default:

            return 1;
    }


    int totalCost = roomRate + boardRate;


    printf("\nTotal cost for Room %d with %s: £%d\n", roomChoice, (boardChoice == 1) ? "Full board" : (boardChoice == 2) ? "Half board" : "B&B", totalCost);

    return 0;
}


int main()
{
    checkIN();
}