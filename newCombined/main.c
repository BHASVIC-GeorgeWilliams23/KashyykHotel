#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
// Function prototypes
int bookingCheck(const char *userBookingID);
int indexCheck(const char *userBookingID, const char bookingID[6][100], int arrLen);

// Global arrays
char bookingid[100];
char bookingID[6][100]; // Array of booking IDs
int stayLength;
int newspaper;
int i;
char surname[35];
int boardChoice;
int roomChoice;
int userAge;
int adults1;
int kids1;
/////idCheck////////
int bookingCheck(const char *userBookingID) {
    // Placeholders
    strcpy(bookingID[roomChoice], bookingid);

    for (int i = 0; i < 6; i++) {
        if (strcmp(userBookingID, bookingID[i]) == 0) {
            printf("Your booking ID is valid\n");
            return 1; // Return 1 to indicate a valid ID
        }
    }

    printf("Your booking ID is not valid\n");
    return 0; // Return 0 to indicate an invalid ID
}
////RoomRate////////
float roomRate() {
    int roomRate = 0;
    // ... (rest of your code here)
    switch (roomChoice) {
        case 0:
            roomRate = 0;
            printf("Room 0 does not exist.");
            break;
        case 1:
            roomRate = 100;
            break;
        case 2:
            roomRate = 100;
            break;
        case 3:
            roomRate = 85;
            break;
        case 4:
            roomRate = 75;
            break;
        case 5:
            roomRate = 75;
            break;
        case 6:
            roomRate = 50;
            break;
    }

    return roomRate;
}
///////////////
float boardRate(){
    int boardRate = 0;
    switch(boardChoice){
        case 1:
            boardRate =20;
            break;
        case 2:
            boardRate = 15;
            break;
        case 3:
            boardRate = 5;
            break;
    }
    return boardRate;
}
/////////CheckOUt//////
void checkOut() {
    char userBookingID[100];
    int validBooking = 0;

    // Keep asking for booking ID until a valid one is provided
    while (!validBooking) {
        printf("\nEnter your booking ID: ");
        scanf("%s", userBookingID);

        validBooking = bookingCheck(userBookingID);

        if (!validBooking) {
            printf("Invalid booking ID. Please try again.\n");
        }
    }

    int index = indexCheck(userBookingID, bookingID, 6);
    if (index != -1) {
        float newspaperCost = 0.0;
        float roomCost;
        float boardCost;
        // Perform actions for a valid booking ID
        printf("Checking out for room %d.\n", index);
        if (userAge <= 65) {
            printf("Room rate is %f\n", stayLength * roomRate());
            roomCost = stayLength * roomRate();
        } else {
            printf("Room rate is %f\n", stayLength * 0.9 * roomRate());
            roomCost = stayLength * 0.9 * roomRate();
        }
        boardCost = boardRate()*(adults1+(kids1/2))*stayLength;
        printf("Total cost of your board is %f\n",boardCost);
        if (newspaper){
            printf("You added a daily newspaper to your booking, this is an additional 5.50 pounds.\n");
            newspaperCost = 5.5;
        }
        printf("Your total bill comes in at %f",boardCost + roomCost + newspaperCost);
    }
}
////////BookingIDGen////////////////
void bookingIdGen()
{
    srand(time(NULL));


    int random_number = rand() % 9000 + 1000;
    snprintf(bookingid, sizeof(bookingid), "%s%d", surname, random_number);

    printf("Your Booking ID: %s\n", bookingid);
}
///////////////////////////////
/////////GUESTCHECK////////////
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
///////////////////////////
void displayRoomRates() {
    char GBP=163 ;
    printf("Room rates per room, per day:\n");
    printf("Room 1 & 2 = %C100\n",GBP);
    printf("Room 3 = %C85\n",GBP);
    printf("Room 4 & 5 = %C75\n",GBP);
    printf("Room 6 = %C50\n",GBP);
}
// Function to display board rates
void displayBoardRates() {
    char GBP=163 ;
    printf("Board rates per person, per day:\n");
    printf("Full board = %c20\n",GBP);
    printf("Half board = %c15\n",GBP);
    printf("B&B = %C5\n",GBP);
}
void bookingTable() {
    // availableTables[time][table]
    int avaliableTables[2][3] = {4,4,4,4,4,4};
    char userBookingID[100];
    int BoardCheck = 0;
    int NumPeople = 0;
    int time = 0;
    int Chosen = 0;
    printf("Enter your booking ID: ");
    scanf("%s", &userBookingID);
    if (bookingCheck(userBookingID)) {
        printf("if your board type is full or half please input 1, if it is BnB please input 2:"); // why the same for half and full?
        scanf("%d", &BoardCheck);
        if (BoardCheck == 1) { // what about if they enter 2??
            printf("valid board type\n");
            printf("how many people are you booking for?\n");
            scanf("%d", &NumPeople);
            if (NumPeople >=5){
                printf("Tables can only hold 4 people.");  //stops values over 4 going through
            }
            else{
                printf("Would you like to book for 7pm or 9pm?\n"); //gets value to define which row to check // 7 or 9 what?
                scanf("%d", &time);
                if (time == 7) {
                    int x;
                    for (x = 0; x < 3; x++) {
                        int TableFull = (avaliableTables[0][x] - NumPeople);  //checks which tables are avaliable for amount of people
                        if (TableFull >= 0) {
                            printf("%d,0 is avaliable at 7\n", x);
                        }
                    }
                    printf("Please select a table to book");
                    scanf("%d",&Chosen);
                    avaliableTables[0][Chosen] = (avaliableTables[0][Chosen] - NumPeople);     //doesnt work?
                } else if(time == 9){
                    int x;
                    for (x = 0; x < 3; x++) {
                        int TableFull = (avaliableTables[1][x] - NumPeople);
                        if (TableFull >= 0) {
                            printf("%d,1 is avaliable at 9\n", x);
                        }
                    }
                    printf("Please select a table to book\n");
                    scanf("%d",&Chosen);
                    avaliableTables[1][Chosen] = (avaliableTables[1][Chosen] - NumPeople);
                }else{
                    printf("Invalid value\n");
                }
            }
        } else{
            printf("Invalid board type\n");
        }
    }
    printf("Time to check out...\n ------- Check Out Panel ----------\n");
    checkOut();
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
    printf("\nRoom and board successfully booked, please checkout to see your final bill.");

    return 0;
}
////////////Main CheckIn/////////////
int checkIN()
{
    printf("Enter surname:");
    scanf("%34s",&surname);
    fflush(stdin);
    int day,month,year;
    printf("\nEnter your age.");
    scanf("%d", &userAge);
    fflush(stdin);
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
    printf("\nWould you like a daily newspaper? \n1 for yes\n2 for no\n:");
    scanf("%d",&newspaper);
    switch(newspaper)
    {
        case 1:
            printf("You have chosen the daily newspaper\n");
            newspaper = 1;
            fflush(stdin);
            break;

        case 2:
            printf("You do not want the daily newspaper\n");
            newspaper = 2;
            fflush(stdin);
            break;

        default:
            printf("Invalid input! ");
            break;
    }

    printf("\nHow many days do you plan to stay for?");
    scanf("%d",&stayLength);
    fflush(stdin);
    bookingIdGen();
    Choice();
    printf("\n------ Restaurant Booking System --------------");
    bookingTable();


}
//////////////////////////////
//////////////////////////////
int indexCheck(const char *userBookingID, const char bookingid[6][100], int arrLen) {
    int index = -1;

    for (int i = 0; i < arrLen; i++) {
        if (strcmp(bookingID[i], userBookingID) == 0) {
            index = i;
            break;
        }
    }
    return index;
}
////////////TableBooking///////

/////////////////////////////////
void mainMenu() {
    int choice;
    printf("Welcome to the Kashyyk Hotel!\nWould you like to:\n1. Check in\n2. Book a table in our restaurant\n3. Check out \nEnter any other number to quit.");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            checkIN();
            break;
        case 2:
            bookingTable();
            break;
        case 3:
            checkOut();
            break;
        default:
            break;
    }
}

int main() {
    mainMenu();
    return 0; // Indicate successful program execution
}