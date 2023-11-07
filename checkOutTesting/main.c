#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>
//int available[6] = [1,1,1,1,1,1];
char stay[50][6];
char names[6];
char DOB[6];
int numGuests[6];
int kids[6];
int adults[6];
char boardType[6];
int newspaper[6];
int bookingID[5];
int i;
int bookings[6][50];

int bookingCheck(const char userBookingID[]) {
    char bookingID[6][100]; // Assuming you have an array of booking IDs
// Placeholders
    strcpy(bookingID[0], "ABC123");
    strcpy(bookingID[1], "XYZ789");
    int i;
    for (i = 0; i < 6; i++) {
        if (strcmp(userBookingID, bookingID[i]) == 0) {
            printf("Your booking ID is valid\n");
            return 1; // Return 1 to indicate a valid ID
        }
    }
    printf("Your booking ID is not valid\n");
    return 0; // Return 0 to indicate an invalid ID
}

void checkIn(){
    printf("Checking in.\n");
}
void bookTable(){
        printf("Booking table.\n");
}
void checkOut() {
    char userBookingID[100];
    printf("Enter your booking ID: \n");
    scanf("%s", userBookingID);
    bookingCheck(userBookingID);
    if(bookingCheck(userBookingID)){

    }
    }



void mainMenu() {
    int choice;
    printf("Welcome to the Kashyyk Hotel!\nWould you like to:\n1. Checkout\n2.Book a table in our restaurant\n3.Check in\nEnter any other number to quit.");
    scanf("%d",&choice);
    switch(choice){
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
int main(){
    mainMenu();
}