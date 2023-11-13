#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>
int available[6] = {1,1,1,1,1,1};
char stay[50][6];
char names[6];
char DOB[6];
int numGuests[6];
int guests[6];
char boardType[6];
int newspaper[6];
char bookingID[6];
int i;
int bookings[6][50];
char name[] = "";



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
    int roomNum,num;
    printf("Enter your room number");
    scanf("%d",roomNum);

    FILE *filepointer;
    if ((filepointer = fopen("C:\\total_bookings.txt","r")) == NULL){
        printf("Error opening file!");
        exit(1);
    }
    fscanf(filepointer,"%d", &num);
    printf("num of bookings = %d", num);
    fclose(filepointer);
    return 0;
}
