#include <stdio.h>
#include <string.h>
// Function to check the user's booking ID
int bookingCheck(const char userBookingID[]) {
    char bookingID[6][100]; //for an array of booking IDs
    strcpy(bookingID[0], "ABC123");
    strcpy(bookingID[1], "XYZ789");
    int i;
    for (i = 0; i < 6; i++) {
        if (strcmp(userBookingID, bookingID[i]) == 0) {
            printf("Your booking ID is valid\n");
            return 1; // return 1 to indicate a valid ID
        }
    }
    printf("Your booking ID is not valid\n");
    return 0; // return 0 to indicate an invalid ID
}
int main() {
    int avaliableTables[2][1];
    char userBookingID[100];
    int BoardCheck = 0;
    int NumPeople = 0;
    int time = 0;
    printf("Enter your booking ID: ");
    scanf("%s", &userBookingID);
    if (bookingCheck(userBookingID)) {
        printf("if your board type is full or half please input 1, if it is BnB please input 2:");
        scanf("%d", &BoardCheck);
        if (BoardCheck == 1) {
            printf("valid board type\n");
            printf("how many people are you booking for?\n");
            scanf("%d", &NumPeople);
            printf("what would you like to book 7 or 9?\n");
            scanf("%d", &time);
            if (time == 7) {
                int x;
                for (x = 0; x < 3; x++) {
                    if ((avaliableTables[x,0] - NumPeople) >= 0) {
                        printf("%d,0 is avaliable at 7\n", x);
                    }
                }
            } else if(time == 9){
                int x;
                for (x = 0; x < 3; x++) {
                    if ((avaliableTables[x,1] - NumPeople) >= 0) {
                        printf("%d,0 is avaliable at 9\n", x);
                    }
                }
            }else{
                printf("invalid board type\n");
            }
        } else {
            printf("invalid board type\n");
        }
        return 0;
    }
}