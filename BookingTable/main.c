#include <stdio.h>
#include <stdlib.h>
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
char bookingID[5];
int i;
int bookings[6][50];

int main() {
    bookingID[0]="g";
    char Bid[100];
    char boardtype;
    i=0;
    int Tables[1][2];
    for(i=0;i<6; i++)
    {
        scanf("%s",&Bid);
        printf("\n%s",Bid);
        if (Bid == bookingID[i])
        {
            printf("\n your booking ID is valid");
            i=6;
        }
        else
        {
            printf("your booking id is not valid");
            i=6;
        }
    }

}

