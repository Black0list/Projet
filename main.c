#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

int main() {
    int choix;

    do {
        printf("===== Dentist Appointment Management =====\n");
        printf("1. Add Reservation\n");
        printf("2. Modify or Delete Reservation\n");
        printf("3. Display Reservation Details\n");
        printf("4. Search Reservations\n");
        printf("5. Sort Reservations\n");
        printf("6. Statistics\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: addReservation();
            break;

            case 2: ModifyOrDeleteReservation();
            break;

            case 3: ShowReservation();
            break;

            case 4: SearchReservation();
            break;

            // // case 5: {
            // //     if (reservationCount == 0) {
            // //         printf("No data available.\n");
            // //         continue;
            // //     }
            // //     SearchReservation();
            // // }
            // break;

            // // case 6: {
            // //     if (reservationCount == 0) {
            // //         printf("No data available.\n");
            // //         continue;
            // //     }
            // //     generateStatistics();
            // // }
            // break;

            case 7: {
                return 0;
            }
            break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choix != 7);

    return 0;
}
