#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
int available[6] = {1,1,1,1,1,1};
char stay[50][6];
char names[6];
char DOB[6];
int numGuests[6];
int guests[6];
char boardType[6];
int newspaper[6];
char bookingID[100];
int i;
int bookings[6][50];
char name[] = "";
char surname;


int guestCheck(adults, kids)
{
    int total
    total = (adults + kids);
    if (total < 4){
        printf("max number of guests is 4.")
        return 0
    }
    if (total < 1){
        printf("minimum number of guests is 1")
        return 0
    }
    else{
        printf("you have entered %d guests",&total)
        return 1
    }

}

int checkIN()
{
    char surname[] = "";
    printf("Enter surname");
    scanf("c",&surname);
    int day,month,year;
    printf("enter DOB (day month year)");
    scanf("%d%d%d", &day &month &year);
    int kids1,adults1;
    printf("Enter number of children (u16) that will be staying");
    scanf("c", &kids1);
    printf("Enter number of adults (16+) that will be staying");
    scanf("c", &adults1);
    int valid;
    valid = guestCheck(adults1, kids1);
    if (valid == 1){
        printf("Valid number of guests")
    else{
            printf("invalid")
            break
    }
    printf("Would you like a daily newspaper?")
    scanf("%d")
    switch case()
        {
            case 1: printf("you have chose the daily newspaper")

            case 2: printf("you do not want the daily newspaper")
        }

    }
}


char bookingIdGen()
{
    srand(time(NULL));


    int random_number = rand() % 9000 + 1000;

    char bookingid[100];
    snprintf(bookingid, sizeof(bookingid), "%s%d", surname, random_number);

    printf("Your Booking ID: %s\n", bookingid);

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
    int roomChoice;
    int boardChoice;


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

