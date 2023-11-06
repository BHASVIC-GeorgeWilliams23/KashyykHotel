#include <stdio.h>
#include <string.h>
// Function to check the user's booking ID
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
int main() {
    char userBookingID[100];
    printf("Enter your booking ID: ");
    scanf("%s", userBookingID);
    if (bookingCheck(userBookingID)) {
// User's booking ID is valid
    } else {
// User's booking ID is not valid
    }
    return 0;
}
