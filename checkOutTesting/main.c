#include <stdio.h>
#include <process.h>
#include <stdlib.h>
//int available[6] = [1,1,1,1,1,1];
char stay[50][6];
char names[6];
char DOB[6];
int numGuests[6];
int kids[6];
int adults[6];
char boardType[6];
int newspaper[6];
void checkOut() {
    printf("Checking out.\n");
    }
void checkIn(){
    printf("Checking in.\n");
}
void bookTable(){
        printf("Booking table.\n");
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
    mainMenu()
}