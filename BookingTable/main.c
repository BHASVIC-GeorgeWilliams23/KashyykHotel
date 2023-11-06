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

int BookTable() {
    char Bid,boardtype;
    i=0;
    int Tables[1][2];
    scanf("%s",Bid);
    for(i=0;i<5; i++)
    {
        if (Bid == bookingID[i])
        {
            printf("your booking ID is valid");
            break;
        }
        else
        {
            printf("your booking id is not valid");
        }
    }
 
}

