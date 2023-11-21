#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

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
int stayLength;
int guests;
int newspaper;
int i;
char surname[35];
int boardChoice;
int roomChoice;

////////BookingIDGen////////////////
void bookingIdGen()
{
    srand(time(NULL));


    int random_number = rand() % 9000 + 1000;

    char bookingid[100];
    snprintf(bookingid, sizeof(bookingid), "%s%d", surname, random_number);

    printf("Your Booking ID: %s\n", bookingid);
}
///////////////////////////////

void bookTable() {
    printf("Booking table.\n");
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
            if(userAge<=65){
                printf("Room rate is %f", stayLength*roomRate(userBookingID));
            }
            else{
                printf("Room rate is %f", stayLength*0.9*roomRate(userBookingID));
            }
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
    return 0; // Indicate successful program execution
}