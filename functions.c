#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "variables.c"
#include "Header/functions.h"


//////////////////////////// INPUT FUCNTIONS /////////////////////////////////////////////
void InputChar( char input[]){
    scanf(" %[^\n]", input);
}
////////////////////////////// CHECK //////////////////////////////////////////////////////
void Check(){
    if (referenceCount == 0) {
        printf("No reservations available.\n");
        return;
    }
}

////////////////////////////////////////// AJOUT //////////////////////////////////////////
void addReservation(){
    int n;
    printf("Enter number of reservations to add : ");
    scanf("%d", &n);

    printf("\n=========================== Add Reservation ===========================\n");
    for(int i=reservationCount;i<n+reservationCount;i++){
        printf("\n=== Reservation N %d ===\n", i+1);
        reservations[i].reference = ++referenceCount;

        printf("Enter Name :");
        InputChar(reservations[i].name);

        printf("Enter Prenom :");
        InputChar(reservations[i].prenom);

        printf("Enter Phone Number :");
        InputChar(reservations[i].phone);

        printf("Enter Age :");
        scanf("%d", &reservations[i].age);

        strcpy(reservations[i].status, "valide");

        printf("Enter Date :");
        InputChar(reservations[i].date);
    }
    reservationCount += n;
}

/////////////////////////////////// MODIFICATION & SUPPRESSION ///////////////////////////////////
void ModifyOrDeleteReservation() {
    system("cls");
    printf("\n=========================== Modify or Delete Reservation ===========================\n");

    if (referenceCount == 0) {
        printf("No reservations available.\n");
        return;
    }

    int id;
    printf("Enter reservation reference to modify or delete: ");
    scanf("%d", &id);

    int index = SearchReservationByReference(id);

    if (index == -1) {
        printf("Reservation with reference %d not found.\n", id);
        return;
    }

    int choix;
    printf("\n1. Modify Reservation\n2. Delete Reservation\nEnter your choice: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: {
            char newName[MAX];
            char newPrenom[MAX];
            char newPhone[MAX];
            int newAge;
            int choice;
            char newDate[MAX];

            printf("Enter new name (To keep Current let it Blank): ");
            InputChar(newName);
            if (strlen(newName) > 0) {
                strcpy(reservations[index].name, newName);
            }

            printf("Enter new prenom (To keep Current let it Blank): ");
            InputChar(newPrenom);
            if (strlen(newPrenom) > 0) {
                strcpy(reservations[index].prenom, newPrenom);
            }

            printf("Enter Phone Number (To keep Current let it Blank): ");
            InputChar(newPhone);
            if (strlen(newPhone) > 0) {
                strcpy(reservations[index].phone, newPhone);
            }

            printf("Enter New Age (To keep Current let it Blank):");
            scanf("%d", &newAge);
            if (newAge > 0) {
                reservations[index].age = newAge;
            }

            printf("Enter New Status (Blank to Keep The Current): \n1. Valide\n2. reporte\n3. annule\n4. traite:\n5. Exit\n");
            printf("Choice? : ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    strcpy(reservations[index].status, "valide");
                    break;
                case 2:
                    strcpy(reservations[index].status, "reporte");
                    break;
                case 3:
                    strcpy(reservations[index].status, "annule");
                    break;
                case 4:
                    strcpy(reservations[index].status, "traite");
                    break;
                case 5:
                    printf("Returning to the main menu.\n");
                    break;
                default:
                    printf("Invalid choice. Keeping the current status.\n");
                    break;
            }



            printf("\nReservation N %d Successfully Modified.\n",index);
        }
        break;

        case 2: {
            for (int i = index; i < referenceCount - 1; i++) {
                reservations[i] = reservations[i + 1]; 
            }
            referenceCount--;
            printf("\nReservation deleted successfully.\n");
        }
        break;

        default:
            printf("Invalid choice.\n");
            break;
    }

}
/////////////////////////////////////// AFFICHAGE ////////////////////////////////////////////////
void ShowReservation(){
    Check();

    int choice;
    do {
        printf("\n=========================== Show Reservations ===========================\n");
        printf("1. Show All Reservations\n");
        printf("2. Show Reservation By Reference\n");
        printf("3. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ShowAllReservations();
                break;

            case 2: {
                int id;
                printf("Enter the reference number: ");
                scanf("%d", &id);

                ShowReservationByReference(id);
                break;
            }
            
            case 3:
                printf("Going back to the main menu.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);
}


////ALL
void ShowAllReservations(){
    printf("\n=========================== All Reservations ===========================\n");
    for (int i = 1; i < referenceCount+1; i++) {
       ShowReservationByReference(i);
    }
}

///1 
void ShowReservationByReference(int id) {
    int index = SearchReservationByReference(id);

    if (index == -1) {
        printf("Reservation with reference %d not found.\n", id);
        return;
    }

    printf("\n================ Reservation N %d ================\n",index+1);
            printf("Reference: %d\n", reservations[index].reference);
            printf("Name: %s\n", reservations[index].name);
            printf("Prenom: %s\n", reservations[index].prenom);
            printf("Phone: %s\n", reservations[index].phone);
            printf("Age: %d\n", reservations[index].age);
            printf("Status: %s\n", reservations[index].status);
            printf("Date: %s\n", reservations[index].date);
}


///////////////////////////////////////// RECHERCHE /////////////////////////////////////////////
void SearchReservation(){

    Check();

    int choice;
    do {
        printf("\n=========================== Search Menu ===========================\n");
        printf("1. Search By reference\n");
        printf("2. Search By name\n");
        printf("3. Seartch By Date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                        int id;
                        printf("Enter the reference number: ");
                        scanf("%d", &id);
                        
                        int index = SearchReservationByReference(id);

                        if(index == -1){
                            printf("Reservation with reference %d not found.\n", id);
                            return;
                        }
                        ShowReservationByReference(index);
                break;
            }
                break;

            case 2: {
                        char name[MAX];

                        printf("Enter name : ");
                        InputChar(name);
                        SearchReservationByName(name);
                }
                break;

            case 3: {
                        char date[MAX];

                        printf("Enter date : ");
                        InputChar(date);
                        SearchReservationByDate(date);

                }
                break;

            case 4:
                printf("Going back to the main menu.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
}




int SearchReservationByReference(int id) {
    for (int i = 0; i < referenceCount; i++) {
        if (reservations[i].reference == id) {
            return i;
            break; 
        }
    }
    return -1;
}

void SearchReservationByName(char name[]){
    int found = 0;

    for(int i=0;i<referenceCount;i++){
        if(strcasecmp(reservations[i].name , name) == 0){
            printf("Reference: %d\n", reservations[i].reference);
            printf("Name: %s\n", reservations[i].name);
            printf("Prenom: %s\n", reservations[i].prenom);
            printf("Phone: %s\n", reservations[i].phone);
            printf("Age: %d\n", reservations[i].age);
            printf("Status: %s\n", reservations[i].status);
            printf("Date: %s\n", reservations[i].date);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Reservation with Name %s not found.\n", name);
        return;
    }
}

void SearchReservationByDate(char date[]){
    int found =  0;

    for(int i=0;i<referenceCount;i++){
        if(strcasecmp(reservations[i].date, date) == 0){
            printf("Reference: %d\n", reservations[i].reference);
            printf("Name: %s\n", reservations[i].name);
            printf("Prenom: %s\n", reservations[i].prenom);
            printf("Phone: %s\n", reservations[i].phone);
            printf("Age: %d\n", reservations[i].age);
            printf("Status: %s\n", reservations[i].status);
            printf("Date: %s\n", reservations[i].date);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Reservation with name %s not found.\n", date);
        return;
    }
}


////////////////////////////////////// SORTS /////////////////////////////////////////////////
void SortReservation(){
    Check();

    int choice;
    do {
        printf("\n=========================== Sort Menu ===========================\n");
        printf("1. Sort By name\n");
        printf("2. Sort By date\n");
        printf("3. Sort By status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Sort(choice);
                break;

            case 2: Sort(choice);
                break;
            
            case 3: Sort(choice);
                break;

            case 4:
                printf("Going back to the main menu.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
}


void Sort(int type){
    Reservation T;
    if(type == 1){
            for(int i=0;i<referenceCount - 1;i++){
                for(int j=0;j<referenceCount -i -1;j++){
                    if(strcasecmp(reservations[j].name, reservations[j+1].name) > 0){
                        T = reservations[j];
                        reservations[j] = reservations[j+1];
                        reservations[j+1] = T;
                    }
                }
            }
    } else if(type == 2){
            for(int i=0;i<referenceCount - 1;i++){
                for(int j=0;j<referenceCount -i -1;j++){
                    if(strcasecmp(reservations[j].date, reservations[j+1].date) > 0){
                        T = reservations[j];
                        reservations[j] = reservations[j+1];
                        reservations[j+1] = T;
                    }
                }
            }
    } else if(type == 3){
            for(int i=0;i<referenceCount - 1;i++){
                for(int j=0;j<referenceCount -i -1;j++){
                    if(GetStatusIndex(reservations[j].status) > GetStatusIndex(reservations[j+1].status)){
                        T = reservations[j];
                        reservations[j] = reservations[j+1];
                        reservations[j+1] = T;
                    }
                }
            }
    }
    ShowAllReservations();
}



int GetStatusIndex(char status[]){
    if(strcasecmp(status, "valide") == 0){
        return 1;
    }else if(strcasecmp(status, "reporte") == 0){
        return 2;
    }else if(strcasecmp(status, "annule") == 0){
        return 3;
    }else if(strcasecmp(status, "traite") == 0){
        return 4;
    } else {
        printf("Status Invalide!");
        return 5;
    }
}


//////////////////////////////////// STATISTICS /////////////////////////////////////
void Statistics(){

    if (referenceCount == 0) {
        printf("No reservations available.\n");
        return;
    }

    int choice;
    do {
        printf("\n=========================== Statistics Menu ===========================\n");
        printf("1. Age Average\n");
        printf("2. Show Patients by Sections\n");
        printf("3. Totale Reservation By status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: AverageAge();
                break;

            case 2: SectionsAge();
                break;
            
            case 3: TotaleReservationsByStatus();
                break;

            case 4:
                printf("Going back to the main menu.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
}

void AverageAge(){

    int SumOfAge = 0;
    
    for(int i=0;i<reservationCount;i++){
        SumOfAge += reservations[i].age;
    }

    float AverageAge = (float)SumOfAge/reservationCount;

    printf("The Average age is : %.2f", AverageAge);
}

void SectionsAge(){
    printf("========================== 0-18 ============================");
    for(int i=0;i<referenceCount;i++){
        if(reservations[i].age>=0 && reservations[i].age <= 18) {
            ShowReservationByReference(i+1);
        }
    }

    printf("========================== 19-36 ============================");
    for(int i=0;i<referenceCount;i++){
        if(reservations[i].age>=19 && reservations[i].age <= 36) {
            ShowReservationByReference(i+1);
        }
    }

    printf("========================== 36+ ============================");
    for(int i=0;i<referenceCount;i++){
        if(reservations[i].age>36) {
            ShowReservationByReference(i+1);
        }
    }
}
void TotaleReservationsByStatus(){
    int valide = 0,reporte = 0,annule = 0,traite = 0;

    for(int i=0;i<reservationCount;i++){
        if(GetStatusIndex(reservations[i].status) == 1){
            valide++;
        } else if(GetStatusIndex(reservations[i].status) == 2){
            reporte++;
        } else if(GetStatusIndex(reservations[i].status) == 3){
            traite++;
        } else if(GetStatusIndex(reservations[i].status) == 4){
            annule++;
        }
    }

    printf("\n================================ Totale Of Reservations By Status ==================================\n");
    printf("Valide = %d\nReporte = %d\nAnnule = %d\nTraite = %d",valide,reporte,annule,traite);
}