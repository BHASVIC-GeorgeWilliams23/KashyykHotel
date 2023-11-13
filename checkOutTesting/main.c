#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int bookingCheck(const char *userBookingID);
int indexCheck(const char *userBookingID, const char bookingID[6][100], int arrLen);

// Global arrays
char stay[50][6];
char names[6];
char DOB[6];
int numGuests[6];
int kids[6];
int adults[6];
char boardType[6];
char bookingID[6][100]; // Array of booking IDs
int userAge= 70;
int stayLength = 5;
int boardChoice = 1;
int adults1 = 2;
int kids1 = 3;
int newspaper = 1;
float roomCost;
float boardCost;
void checkIn() {
    printf("Checking in.\n");
}

int indexCheck(const char *userBookingID, const char bookingID[6][100], int arrLen) {
    int index = -1;

    for (int i = 0; i < arrLen; i++) {
        if (strcmp(bookingID[i], userBookingID) == 0) {
            index = i;
            break;
        }
    }
    return index;
}
float roomRate(const char *userBookingID) {
    float roomCost = 0.0;
    float boardCost = 0.0;
    float newspaperCost = 0.0;
    int roomRate = 0;
    int index = indexCheck(userBookingID, bookingID, 6);
    // ... (rest of your code here)
    switch (index) {
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
float boardRateCalc(int boardChoice){
    int boardRate;
    switch(boardChoice){
        case 1:
            boardRate = 20;
            break;
        case 2:
            boardRate =15;
            break;
        case 3:
            boardRate=5;
            break;
    }
    return boardRate;
}
int bookingCheck(const char *userBookingID) {
    // Placeholders
    strcpy(bookingID[1], "XYZ789");
    strcpy(bookingID[2], "123DEF");
    strcpy(bookingID[3], "456GHI");
    strcpy(bookingID[4], "789JKL");
    strcpy(bookingID[5], "MNO000");

    for (int i = 0; i < 6; i++) {
        if (strcmp(userBookingID, bookingID[i]) == 0) {
            printf("Your booking ID is valid\n");
            return 1; // Return 1 to indicate a valid ID
        }
    }

    printf("Your booking ID is not valid\n");
    return 0; // Return 0 to indicate an invalid ID
}

void checkOut() {
    char userBookingID[100];
    printf("Enter your booking ID: \n");
    scanf("%s", userBookingID);

    if (bookingCheck(userBookingID)) {
        int index = indexCheck(userBookingID, bookingID, 6);
        if (index != -1) {
            // Perform actions for a valid booking ID
            printf("Checking out for room %d.\n", index);
            if (userAge <= 65) {
                roomCost = stayLength * roomRate(userBookingID);
                printf("Total payment for the room is %f\n", roomCost);
            } else {
                roomCost = stayLength * roomRate(userBookingID)*0.9;
                printf("Total payment for the room is %f (elderly discount applied)\n", roomCost);
            }
            boardCost = boardRateCalc(boardChoice)*(adults1+kids1/2)*stayLength;
            printf("Total payment for the meals is %f\n",boardCost);
            float totalBill = roomCost + boardCost;
            if (newspaper==1){
                printf("Plus an additional 5.50 for the newspaper.\n");
                printf("In total, your bill is %f\n",totalBill+5.5);
            }
            else{
                float totalBill = roomCost + boardCost;
                printf("In total, your bill is %f\n",totalBill);
            }
        }


    }
}
////////////////////////////////////////////////////////////////////////////////

void bookTable() {
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
                printf("what would you like to book 7pm or 9pm?\n"); //gets value to define which row to check // 7 or 9 what?
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

                }
                else{
                    printf("invalid value\n");
                }
            }
        } else{
            printf("invalid board type\n");
        }
    }
}





























void mainMenu() {
    int choice;
    printf("Welcome to the Kashyyk Hotel!\nWould you like to:\n1. Checkout\n2. Book a table in our restaurant\n3. Check in\nEnter any other number to quit.");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            checkOut();
            break;
        case 2:
            bookTable();
            break;
        case 3:
            checkIn();
            break;
        default:
            break;
    }
}

int main() {
    mainMenu();
    mainMenu();
    return 0; // Indicate successful program execution
}
