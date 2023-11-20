#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

///////////GLOBAL VARIABLES////////
int stayLength;
int guests;
int newspaper;
char surname[35];
int boardChoice;
int roomChoice;
char bookingID[6][100]; // Array of booking IDs
int year;
int userAge;
int adults1;
int kids1;
float roomCost;
float boardCost;

///////////FUNCTION DECLARATIONS//////////
int bookingCheck(const char userBookingID[]);
void displayBoardRates();
void displayRoomRates();
int Choice();
void bookingIdGen();
int guestCheck(int adults, int kids);
int checkIN();
void bookingtable();
void checkOut();
void mainMenu();
int indexCheck(const char *userBookingID, const char bookingID[6][100], int arrLen);
float roomRate(const char *userBookingID);
float boardRateCalc(int boardChoice);

///////////BOOKING CHECK//////////
int bookingCheck(const char userBookingID[]) {
    char validBookingIDs[6][100] = {"ABC123", "XYZ789"};

    for (int i = 0; i < 6; i++) {
        if (strcmp(userBookingID, validBookingIDs[i]) == 0) {
            printf("Your booking ID is valid\n");
            return 1; // return 1 to indicate a valid ID
        }
    }

    printf("Your booking ID is not valid\n");
    return 0; // return 0 to indicate an invalid ID
}

/////////////////
void displayBoardRates() {
    printf("Board rates per person, per day:\n");
    printf("Full board = £20\n");
    printf("Half board = £15\n");
    printf("B&B = £5\n");
}

///////////////////
void displayRoomRates() {
    printf("Room rates per room, per day:\n");
    printf("Room 1 & 2 = £100\n");
    printf("Room 3 = £85\n");
    printf("Room 4 & 5 = £75\n");
    printf("Room 6 = £50\n");
}

/////////////////////////
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

    printf("\nTotal cost for Room %d with %s: £%d\n", roomChoice,
           (boardChoice == 1) ? "Full board" : (boardChoice == 2) ? "Half board" : "B&B", totalCost);

    return 0;
}

///////////CHECK IN///////////////
void bookingIdGen() {
    srand(time(NULL));
    int random_number = rand() % 9000 + 1000;
    char bookingid[100];
    snprintf(bookingid, sizeof(bookingid), "%s%d", surname, random_number);
    printf("Your Booking ID: %s\n", bookingid);
}

int guestCheck(int adults, int kids) {
    int guests = (adults + kids);
    if (guests > 4) {
        printf("\nmax number of guests is 4.");
        return 0;
    }
    if (guests < 1) {
        printf("\nminimum number of guests is 1");
        return 0;
    } else {
        printf("\nyou have entered %d guests", guests);
        return 1;
    }
}

int checkIN() {
    printf("Enter surname:");
    scanf("%34s", surname);
    fflush(stdin);
    printf("enter age");
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
    if (valid == 1) {
        printf("\nValid number of guests\n");
    }
    if (valid != 1) {
        printf("\ninvalid");
    }
    int newspaper;
    printf("\nWould you like a daily newspaper? \n1 for yes\n2 for no\n:");
    scanf("%d", &newspaper);
    switch (newspaper) {
        case 1:
            printf("you have chosen the daily newspaper\n");
            newspaper = 1;
            fflush(stdin);
            break;
        case 2:
            printf("you do not want the daily newspaper\n");
            newspaper = 2;
            fflush(stdin);
            break;
        default:
            printf("Invalid input! ");
            break;
    }
    printf("How many days do you plan to stay for?");
    scanf("%d", &stayLength);
    fflush(stdin);
    bookingIdGen();
    return 0;
}

//////////////////////////////////////////////////////////////////////////
////////////////TABLE BOOKING/////////////////////////////////////////////
void bookingtable() {
    int availableTables[2][3] = {{4, 4, 4}, {4, 4, 4}};
    char userBookingID[100];
    int BoardCheck = 0;
    int NumPeople = 0;
    int time = 0;
    int Chosen = 0;
    printf("Enter your booking ID: ");
    scanf("%s", userBookingID);

    if (bookingCheck(userBookingID)) {
        printf("if your board type is full or half please input 1, if it is BnB please input 2:");
        scanf("%d", &BoardCheck);

        if (BoardCheck == 1) {
            printf("valid board type\n");
            printf("how many people are you booking for?\n");
            scanf("%d", &NumPeople);

            if (NumPeople >= 5) {
                printf("Tables can only hold 4 people.\n");
            } else {
                printf("what would you like to book 7pm or 9pm?\n");
                scanf("%d", &time);

                if (time == 7) {
                    for (int x = 0; x < 3; x++) {
                        int TableFull = (availableTables[0][x] - NumPeople);

                        if (TableFull >= 0) {
                            printf("%d,0 is available at 7\n", x);
                        }
                    }

                    printf("Please select a table to book: ");
                    scanf("%d", &Chosen);
                    availableTables[0][Chosen] = (availableTables[0][Chosen] - NumPeople);
                } else if (time == 9) {
                    for (int x = 0; x < 3; x++) {
                        int TableFull = (availableTables[1][x] - NumPeople);

                        if (TableFull >= 0) {
                            printf("%d,1 is available at 9\n", x);
                        }
                    }

                    printf("Please select a table to book: ");
                    scanf("%d", &Chosen);
                    availableTables[1][Chosen] = (availableTables[1][Chosen] - NumPeople);
                } else {
                    printf("Invalid value\n");
                }
            }
        } else {
            printf("Invalid board type\n");
        }
    }
}
//////////////////
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
////////////////////////////////////////////////////////////////////////////////

void checkOut() {
    char userBookingID[100];
    printf("Enter your booking ID: ");
    scanf("%s", userBookingID);

    if (bookingCheck(userBookingID)) {
        int index = indexCheck(userBookingID, bookingID, 6);

        if (index != -1) {
            printf("Checking out for room %d.\n", index);

            if (userAge <= 65) {
                roomCost = stayLength * roomRate(userBookingID);
                printf("Total payment for the room is £%.2f\n", roomCost);
            } else {
                roomCost = stayLength * roomRate(userBookingID) * 0.9;
                printf("Total payment for the room is £%.2f (elderly discount applied)\n", roomCost);
            }

            boardCost = boardRateCalc(boardChoice) * (adults1 + kids1 / 2) * stayLength;
            printf("Total payment for the meals is £%.2f\n", boardCost);

            if (newspaper == 1) {
                printf("Plus an additional £5.50 for the newspaper.\n");
                printf("In total, your bill is £%.2f\n", roomCost + boardCost + 5.5);
            } else {
                printf("In total, your bill is £%.2f\n", roomCost + boardCost);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

void mainMenu() {
    int choice;
    printf("Welcome to the Kashyyk Hotel!\nWould you like to:\n1. Checkout\n2. Book a table in our restaurant\n3. Check in\nEnter any other number to quit.");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            checkOut();
            break;
        case 2:
            bookingtable();
            break;
        case 3:
            checkIN();
            break;
        default:
            break;
    }
}

///////////////////////////////////////////////////////////////////////////
int main() {
    mainMenu();
    return 0;
}
